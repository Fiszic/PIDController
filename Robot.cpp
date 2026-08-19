//
// Created by Zhengye Chen on 8/10/26.
//

#include "Robot.h"

Robot::Robot(double mass, double drag): drive(0.05, 0.3), mass(mass), drag(drag){

}

void Robot::update(double dt) {
    drive.update(dt);
}

void Robot::driveForward(double velocity) {
    drive.setVelocity(velocity, velocity);
}

void Robot::turn(double velocity) {
    drive.setVelocity(-velocity, velocity); //turns left if velocty is positive.
}

void Robot::stop() {
    drive.stop();
}