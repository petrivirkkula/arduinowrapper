#include "arduinowrapper/AWAnalogPin.h"


void AWAnalogPin::setReferenceVoltage(AWAnalogPin::ReferenceVoltage referenceVoltage) {
    analogReference((int) referenceVoltage);
}

void AWAnalogPin::write(int value) {
    analogWrite(pinNumber_, value);
}

int AWAnalogPin::read() {
    return analogRead(pinNumber_);
}
