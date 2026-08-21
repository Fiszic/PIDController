//
// Created by Zhengye Chen on 8/21/26.
//

#include "Gyroscope.h"

Gyroscope::Gyroscope(double bias) : angularVelocity(0), angle(0), bias(bias) {

}

void Gyroscope::update(double trueAngularVelocity, double dt) {
    angularVelocity = trueAngularVelocity + bias;
    angle+=angularVelocity * dt;
}

double Gyroscope::getAngularVelocity() const {
    return angularVelocity;
}

double Gyroscope::getAngle() const {
    return angle;
}

void Gyroscope::reset() {
    angle = 0.0;
}
