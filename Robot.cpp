//
// Created by Zhengye Chen on 8/10/26.
//

#include "Robot.h"

Robot::Robot(double mass, double drag): mass(mass), drag(drag){
    state.position.set(0, 0, 0);
    state.velocity.set(0, 0, 0);
    state.acceleration.set(0, 0, 0);
    force.set(0, 0, 0);
}

void Robot::update(double dt) {
    state.acceleration.x = (force.x - drag * state.velocity.x) / mass;
    state.acceleration.y = (force.y - drag * state.velocity.y) / mass;

    state.velocity.x += state.acceleration.x * dt;
    state.velocity.y += state.acceleration.y * dt;

    state.position.x += state.velocity.x * dt;
    state.position.y += state.velocity.y * dt;
}

void Robot::applyForce(const Vec3 &output) {
    force.x = output.x;
    force.y = output.y;
    force.z = output.z;
}

const Vec3& Robot::getPosition() const {
    return state.position;
}

const Vec3& Robot::getVelocity() const {
    return state.velocity;
}

const Vec3& Robot::getAcceleration() const {
    return state.acceleration;
}

double Robot::getXPosition() const{
    return state.position.x;
}

double Robot::getYPosition() const {
    return state.position.y;
}

double Robot::getZPosition() const {
    return state.position.z;
}

double Robot::getXVelocity() const {
    return state.velocity.x;
}

double Robot::getYVelocity() const {
    return state.velocity.y;
}

double Robot::getZVelocity() const {
    return state.velocity.z;
}

double Robot::getXAcceleration() const {
    return state.acceleration.x;
}

double Robot::getYAcceleration() const {
    return state.acceleration.y;
}

double Robot::getZAcceleration() const {
    return state.acceleration.z;
}