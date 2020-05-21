#ifndef _ARDUINOWRAPPER_DIGITALPIN_H_
#define _ARDUINBOWRAPPER_DIGITALPIN_H_

#include "Arduino.h"
#include "arduinowrapper/AWPin.h"

class AWDigitalPin : public AWPin {
public:
    enum PinMode {
        PinModeNone = -1,
        PinModeInput = INPUT,
        PinModeOutput = OUTPUT,
        PinModeInputPullup = INPUT_PULLUP
    };
public:
    AWDigitalPin(int pinNumber, PinMode mode) : AWPin(pinNumber) {
        setPinMode(mode);
    }

    ~AWDigitalPin() {
    }

    void init(int pinNumber) {
        AWPin::init(pinNumber);
    }

    void setPinMode(PinMode mode);

    void write(int value);

    int read();
};


#endif //_ARDUINOWRAPPER_DIGITALPIN_H_
