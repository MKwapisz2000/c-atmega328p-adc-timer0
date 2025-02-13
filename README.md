# c-atmega328p-adc-timer0

**Project Description - English**

This project demonstrates the handling of the Analog-to-Digital Converter (ADC) in the ATmega328P microcontroller using internal interrupts triggered by Timer0 (compare match A). The ADC conversion is performed periodically, at fixed time intervals, instead of being manually triggered by the user or an external source. The implementation is done in pure C, directly accessing registers, without Arduino libraries.

Features:

- Initialization of ADC and Timer0 in CTC mode

- Automatic, periodic ADC conversion using timer interrupts

- LED control based on the measured voltage

- Using ATmega328P microcontroller in pure C

Hardware Requirements:

- ATmega328P microcontroller (e.g., Arduino Nano or standalone AVR)

- Analog sensor or potentiometer (connected to A0)

- LED (connected to a selected microcontroller pin)

- Connecting wires

Usage Instructions:

- Compile the code in an AVR C-compatible environment (e.g., Atmel Studio, PlatformIO, AVR-GCC).

- Upload the program to the microcontroller using an ISP programmer.

- The microcontroller automatically performs ADC readings at fixed time intervals thanks to Timer0.

- The LED will turn on or off depending on the measured voltage.


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


**Opis projektu - Polski**

Ten projekt demonstruje obsługę przetwornika analogowo-cyfrowego (ADC) w mikrokontrolerze ATmega328P przy użyciu przerwań wewnętrznych wyzwalanych przez Timer0 (compare match A). Konwersja ADC odbywa się periodycznie, w ustalonych odstępach czasu, zamiast ręcznego wyzwalania przez użytkownika lub trigger source. Implementacja w języku C korzysta bezpośrednio z rejestrów, bez bibliotek Arduino.

Funkcjonalność:

- Inicjalizacja ADC i Timera0 w trybie CTC

- Automatyczna, cykliczna konwersja ADC dzięki przerwaniom timera

- Sterowanie diodą LED w zależności od odczytanego napięcia

- Obsługa mikrokontrolera ATmega328P w czystym C

Wymagania sprzętowe:

- Mikrokontroler ATmega328P (np. Arduino Nano lub standalone AVR)

- Czujnik analogowy lub potencjometr (podłączony do A0)

- Dioda LED (podłączona do wybranego pinu mikrokontrolera)

- Przewody połączeniowe

Instrukcja użytkowania:

- Skompiluj kod w środowisku obsługującym AVR C (np. Atmel Studio, PlatformIO, AVR-GCC).

- Wgraj program do mikrokontrolera za pomocą programatora ISP.

- Mikrokontroler automatycznie wykonuje pomiary ADC w równych odstępach czasu dzięki Timer0.

- Dioda LED zapali się lub zgaśnie w zależności od odczytanego napięcia.

