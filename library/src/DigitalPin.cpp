
#include "arduinowrapper/DigitalPin.h"

void DigitalPin::setPinMode(DigitalPin::PinMode mode) {
    pinMode(pinNumber_, mode);
}

void DigitalPin::write(int value) {
    digitalWrite(pinNumber_, value);
}

int DigitalPin::read() {
    return digitalRead(pinNumber_);
}
