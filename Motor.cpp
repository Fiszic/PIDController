//
// Created by Zhengye Chen on 8/15/26.
//

#include "Motor.h"

#include <utility>
#include <algorithm>

Motor::Motor(std::string name, double max_rpm, double max_torque) : name(std::move(name)), max_rpm(max_rpm), max_torque(max_torque) {}

void Motor::enable() {
    is_enabled = true;
}

void Motor::disable() {
    is_enabled = false;
    power = 0.0;
    applyPower();
}

void Motor::setPower(double newPower) {
    if (newPower > 1.0) {
        newPower = 1.0;
    }
    if (newPower < -1.0) {
        newPower = -1.0;
    }

    power = newPower;

    if (is_enabled) {
        applyPower();
    }
}

double Motor::getPower() const {
    return power;
}

void Motor::stop() {
    power = 0;
}

void Motor::applyPower() {
    // to be worked on maybe in the future if I want to add a motor driver.
}
