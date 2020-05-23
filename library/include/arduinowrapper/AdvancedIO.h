//
// Created by Petri on 5/22/2020.
//

#ifndef ARDUIWRAPPER_ADVANCEDIO_H
#define ARDUIWRAPPER_ADVANCEDIO_H

#include <Arduino.h>
#include "arduinowrapper/Pin.h"

class AdvancedIO {
private:
    Pin pin_;
public:

    AdvancedIO(Pin &pin) : pin_(pin) {
    }

};

#endif //ARDUIWRAPPER_ADVANCEDIO_H
