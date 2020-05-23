#include "arduinowrapper/AnalogPin.h"


void AnalogPin::setReferenceVoltage(AnalogPin::ReferenceVoltage referenceVoltage) {
    analogReference((int) referenceVoltage);
}

void AnalogPin::write(int value) {
    analogWrite(pinNumber_, value);
}

int AnalogPin::read() {
    return analogRead(pinNumber_);
}
