#ifndef _ARDUINOWRAPPER_PIN_H_
#define _ARDUINOWRAPPER_PIN_H_

class AWPin {
protected:
    int pinNumber_;

    AWPin(int pinNumber) {
        this->pinNumber_ = pinNumber;
    }

    AWPin(AWPin &other) {
        this->pinNumber_ = other.pinNumber_;
    }

    virtual ~AWPin() {
    }

    void init(int pinNumber) {
        this->pinNumber_ = pinNumber;
    }

public:

    virtual AWPin &operator = (AWPin &pin) {
        this->pinNumber_ = pin.pinNumber_;
    }

    virtual void write(int value) = 0;

    virtual int read() = 0;
};

#endif //_ARDUINOWRAPPER_PIN_H_
