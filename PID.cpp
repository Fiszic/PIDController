//
// Created by Zhengye Chen on 8/9/26.
//

#include "PID.h"

PID::PID(const double kp, const double ki, const double kd) : kp(kp), ki(ki), kd(kd) {}

double PID::calculate(double target, double pos, double dt) {
    double error = target - pos;
    integral += error * dt;
    double deriv = (error - previous_error) / dt;

    double P = kp * error;
    double I = ki * integral;
    double D = 0;
    if (first_calculation) {
        first_calculation=false;
    }
    else {
        D = kd * deriv;
    }

    previous_error = error;

    return P + I + D;
}
