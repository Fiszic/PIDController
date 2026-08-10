//
// Created by Zhengye Chen on 8/10/26.
//

#include "Robot.h"

Robot::Robot(const double mass, const double drag): position(0), velocity(0), acceleration(0), mass(mass),drag(drag), force(0) {}

void Robot::update(const double dt) {
    acceleration = (force - drag * velocity) / mass;
    velocity += acceleration * dt;
    position += velocity * dt;
}

void Robot::applyForce(const double output) {
    force = output;
}

double Robot::getPosition() const {
    return position;
}

double Robot::getVelocity() const {
    return velocity;
}

double Robot::getAcceleration() const {
    return acceleration;
}