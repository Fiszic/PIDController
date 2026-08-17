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
    target_rpm = 0;
}

void Motor::set_speed(double rpm) {
    target_rpm = std::max(-max_rpm, std::min(max_rpm, rpm));
}

void Motor::stop() {
    target_rpm = 0;
}
