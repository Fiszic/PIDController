//
// Created by Zhengye Chen on 8/18/26.
//

#include "DifferentialDrive.h"

DifferentialDrive::DifferentialDrive(double wheelRadius, double trackWidth):
wheelRadius(wheelRadius), trackWidth(trackWidth),
leftMotor("DriveLeftMotor", 0.2, 0.0, 0.3, 0.0, 0.0, 0.0, 1000, 5, 2048),
rightMotor("DriveRightMotor", 0.2, 0.0, 0.3, 0.0, 0.0, 0.0, 1000, 5, 2048){

}

void DifferentialDrive::arcadeDrive(double forward, double rotation) {
    double left = forward + rotation;
    double right = forward - rotation;
    double maxMagnitude = std::max(std::abs(left), std::abs(right));

    if (maxMagnitude > 1.0) {
        left /= maxMagnitude;
        right /= maxMagnitude;
    }

    leftMotor.setPower(left);
    rightMotor.setPower(right);
}

void DifferentialDrive::stop() {
    leftMotor.setPower(0.0);
    rightMotor.setPower(0.0);
}

void DifferentialDrive::update(double dt) {
    leftMotor.update(dt);
    rightMotor.update(dt);
}