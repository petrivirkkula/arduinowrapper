#ifndef _ARDUINOWRAPPER_PIN_H_
#define _ARDUINOWRAPPER_PIN_H_


class Pin {
protected:

    int pinNumber_;

public:

    Pin(int pinNumber) {
        this->pinNumber_ = pinNumber;
    }

    Pin(Pin &other) {
        this->pinNumber_ = other.pinNumber_;
    }

    virtual ~Pin() {
    }

    void init(int pinNumber) {
        this->pinNumber_ = pinNumber;
    }

public:

    virtual Pin &operator = (Pin &pin) {
        this->pinNumber_ = pin.pinNumber_;
        return *this;
    }

    operator int () {
        return this->pinNumber_;
    }
};

#endif //_ARDUINOWRAPPER_PIN_H_
