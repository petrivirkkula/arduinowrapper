
#include "arduinowrapper/AWDigitalPin.h"

void AWDigitalPin::setPinMode(AWDigitalPin::PinMode mode) {
    pinMode(pinNumber_, mode);
}

void AWDigitalPin::write(int value) {
    digitalWrite(pinNumber_, value);
}

int AWDigitalPin::read() {
    return digitalRead(pinNumber_);
}
