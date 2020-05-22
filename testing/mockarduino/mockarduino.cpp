//
// Created by Petri on 5/21/2020.
//


#include "Arduino.h"

void init(void) {
}

void initVariant(void) {
}

//int atexit(void (*func)()) { return 0; }

void pinMode(uint8_t pin, uint8_t mode) {

}

void digitalWrite(uint8_t pin, uint8_t val) {

}

int digitalRead(uint8_t pin) {
    return 0;
}

int analogRead(uint8_t pin) {
    return 0;
}

void analogReference(uint8_t mode) {

}

void analogWrite(uint8_t pin, int val) {

}

unsigned long millis(void) {
    return 0;
}

unsigned long micros(void) {
    return 0;
}

void delay(unsigned long ms) {

}

void delayMicroseconds(unsigned int us) {

}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout) {
    return 0;
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout) {
    return 0;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    return 0;
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {

}

void detachInterrupt(uint8_t interruptNum) {

}


#define PORTCOUNT 64

const uint16_t port_to_mode_PGM[PORTCOUNT] = { 0, };
const uint16_t port_to_input_PGM[PORTCOUNT] = { 0, };
const uint16_t port_to_output_PGM[PORTCOUNT] = { 0, };

const uint8_t digital_pin_to_port_PGM[PORTCOUNT] = { 0, };
const uint8_t digital_pin_to_bit_mask_PGM[PORTCOUNT] = { 0, };
const uint8_t digital_pin_to_timer_PGM[PORTCOUNT] = { 0, };

