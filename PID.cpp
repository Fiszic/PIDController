//
// Created by Zhengye Chen on 8/9/26.
//

#include "PID.h"

PID::PID(const double kp, const double ki, const double kd) : kp(kp), ki(ki), kd(kd) {}

double PID::calculate(double target, double pos, double dt) {
    double error = pos - target;
    if (previous_error == 0 && error != 0) {
        previous_error = error;
    }
    integral += error * dt;
    double deriv = (error - previous_error) / dt;

    double P = kp * error;
    double I = ki * integral;
    double D = kd * deriv;

    return P + I + D;
}
