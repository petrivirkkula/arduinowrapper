//
// Created by Petri on 5/21/2020.
//

#include "gtest/gtest.h"
#include "arduinowrapper/DigitalPin.h"
#include "arduinowrapper/AnalogPin.h"


TEST(tcase1, DigitalPin) {
    DigitalPin pin1(1, DigitalPin::PinMode::PinModeInput);
    EXPECT_TRUE(((int)pin1) == 1);
    DigitalPin pin2(2, DigitalPin::PinMode::PinModeOutput);
    EXPECT_TRUE(((int)pin2) == 2);
    pin2 = pin1;
    EXPECT_TRUE(((int)pin1) == 1);
    EXPECT_TRUE(((int)pin2) == 1);
    EXPECT_TRUE(((int)pin1) == ((int)pin2));
}

TEST(tcase1, AnalogPin) {
    AnalogPin pin1(1);
    EXPECT_TRUE(((int)pin1) == 1);
    AnalogPin pin2(2);
    EXPECT_TRUE(((int)pin2) == 2);
    pin2 = pin1;
    EXPECT_TRUE(((int)pin1) == 1);
    EXPECT_TRUE(((int)pin2) == 1);
    EXPECT_TRUE(((int)pin1) == ((int)pin2));
}
