#ifndef _ARDUINOWRAPPER_DIGITALPIN_H_
#define _ARDUINBOWRAPPER_DIGITALPIN_H_

#include <Arduino.h>
#include "arduinowrapper/Pin.h"
#include "arduinowrapper/Readable.h"
#include "arduinowrapper/Writable.h"

class DigitalPin : public Pin, public Readable, public Writable {
public:
    enum PinMode {
        PinModeNone = -1,
        PinModeInput = INPUT,
        PinModeOutput = OUTPUT,
        PinModeInputPullup = INPUT_PULLUP
    };
public:
    DigitalPin(int pinNumber, PinMode mode) : Pin(pinNumber) {
        setPinMode(mode);
    }

    DigitalPin(int pinNumber) : Pin(pinNumber) {
    }

    DigitalPin(DigitalPin &digitalPin) : Pin(digitalPin) {
    }

    ~DigitalPin() {
    }

    DigitalPin &operator = (DigitalPin &pin) {
        this->pinNumber_ = pin.pinNumber_;
        return *this;
    }

    void init(int pinNumber) {
        Pin::init(pinNumber);
    }

    void setPinMode(PinMode mode);

    void write(int value);

    int read();
};


#endif //_ARDUINOWRAPPER_DIGITALPIN_H_
