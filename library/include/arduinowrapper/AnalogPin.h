#ifndef _ARDUINBOWRAPPER_ANALOGPIN_H_
#define _ARDUINBOWRAPPER_ANALOGPIN_H_

#include <Arduino.h>
#include "arduinowrapper/Pin.h"
#include "arduinowrapper/Readable.h"
#include "arduinowrapper/Writable.h"

class AnalogPin : public Pin, public Readable, public Writable {
public:
    enum ReferenceVoltage {
        ReferenceVoltageDEFAULT = DEFAULT,
        ReferenceVoltageINTERNAL = INTERNAL,
        ReferenceVoltageINTERNAL2V56 = 9,
        ReferenceVoltageEXTERNAL = EXTERNAL,
//        ReferenceVoltageAR_DEFAULT = AR_DEFAULT,
//        ReferenceVoltageAR_INTERNAL = AR_INTERNAL,
//        ReferenceVoltageAR_INTERNAL1V0 = AR_INTERNAL1V0,
//        ReferenceVoltageAR_INTERNAL1V65 = AR_INTERNAL1V65,
//       ReferenceVoltageAR_INTERNAL2V23 = AR_INTERNAL2V23,
//        ReferenceVoltageAR_EXTERNAL = AR_EXTERNAL,
//        ReferenceVoltageVDD = VDD,
//        ReferenceVoltageINTERNAL0V55 = INTERNAL0V55,
        ReferenceVoltageINTERNAL1V1 = 8
//        ReferenceVoltageINTERNAL1V5 = INTERNAL1V5,
//        ReferenceVoltageINTERNAL2V5 = INTERNAL2V5,
//        ReferenceVoltageINTERNAL4V3 = INTERNAL4V3
    };
public:
    AnalogPin(int pinNumber) : Pin(pinNumber) {
    }

    AnalogPin(AnalogPin &analogPin) : Pin(analogPin) {
    }

    ~AnalogPin() {
    }

    void init(int pinNumber) {
        Pin::init(pinNumber);
    }

    AnalogPin &operator = (AnalogPin &pin) {
        this->pinNumber_ = pin.pinNumber_;
        return *this;
    }

    static void setReferenceVoltage(ReferenceVoltage referenceVoltage);

    void write(int value);

    int read();
};

#endif //_ARDUINBOWRAPPER_ANALOGPIN_H_
