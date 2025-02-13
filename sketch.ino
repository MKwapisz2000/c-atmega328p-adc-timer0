//Użycie ADC wraz z przerwaniami wewnętrznymi przez Timer0 compare match A
//bez użycia trigger source

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void Timer0_init()
{
  //tryb pracy CTC
  TCCR0A |= (1<<WGM01);

  //prescaler 1024 -> (16 000 000 /(1024*1000)) = 15,62 -> 1ms
  TCCR0B |= (1<<CS02);
  TCCR0B |= (1<<CS00);
  
  //porównywacz - 1ms
  OCR0A = 15;

  //włączenie przerwań 
  TIMSK0 |= (1<<OCIE0A);
 
  //wlaczenie przerwań 
  sei();
}

void ADC_init()
{
  //zasilanie
  ADMUX |= (1<<REFS0);
  ADMUX &= ~(1<<REFS1);

  //division factor
  ADCSRA |= (1<<ADPS1); 
  ADCSRA |= (1<<ADPS2); 
  ADCSRA |= (1<<ADPS0);

  //kanał A0
  ADMUX &= ~(1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADMUX &= ~(1<<MUX2);
  ADMUX &= ~(1<<MUX3);

  //włączenie przerwan
  ADCSRA |= (1<<ADIE);

  //auto trigger
  //ADCSRA |= (1<<ADATE);

  //wybranie trybu przerwań-Timer0 Compare match A
  //ADCSRB |= (1<<ADTS0);
  //ADCSRB |= (1<<ADTS1);
  
  //włączenie ADC
  ADCSRA |= (1<<ADEN);
  
}

volatile int licznik =0;
int main()
{
  ADC_init();

  //diody
  DDRD |= (1<<PD5);
  DDRD |= (1<<PD3);
  DDRD |= (1<<PD4);

  PORTD &= ~(1<<PD5);
  PORTD &= ~(1<<PD3);
  PORTD &= ~(1<<PD4);

  Timer0_init();
  
  while(1)
  {}

  return 0;
}

ISR(ADC_vect)
{
  licznik++;

  if(licznik>=5000)
  {
    int resultA0 = ADC;
    float napiecieA0 = resultA0*5.0/1023.0;
    
    if(napiecieA0 > 1.0)
    {
      PORTD |= (1<<PD5);
    }
    else
    {
      PORTD &= ~(1<<PD5);
    }
  
   
    if(napiecieA0 > 2.5)
    {
      PORTD |= (1<<PD4);
    }
    else
    {
      PORTD &= ~(1<<PD4);
    }
   
    
    if(napiecieA0 > 4.0)
    {
      PORTD |= (1<<PD3);
    }
    else
    {
      PORTD &= ~(1<<PD3);
    }


    licznik = 0;
  }
  

}

ISR(TIMER0_COMPA_vect)
{
  ADCSRA |= (1<<ADSC);

}