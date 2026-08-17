//
// Created by Zhengye Chen on 8/16/26.
//

#include "MotorController.h"

MotorController::MotorController(const std::string &name, const double kp, const double ki, const double kd, double vkp, double vki, double vkd,const double max_rpm, const double max_torque, const int cpr):
motor(name, max_rpm, max_torque), encoder(cpr), positionPID(kp, ki, kd), velocityPID(vkp, vki, vkd) {}

void MotorController::setTargetPosition(const double target) {
    mode = ControlMode::Position;
    this->targetPosition = target;
}

void MotorController::setTargetVelocity(const double target) {
    mode = ControlMode::Velocity;
    this->targetVelocity = target;
}

void MotorController::setTargetPower(double target) {
    mode = ControlMode::Power;
    this->targetPower = target;
}

void MotorController::update(double dt) {
    if (mode == ControlMode::Position) {
        double currentPos = encoder.getPositionDegrees();
        double output = positionPID.calculate(targetPosition, currentPos, dt);
        motor.setPower(output);
    }
    else if (mode == ControlMode::Velocity) {
        double currentVel = encoder.getVelocityRPM();
        double output = velocityPID.calculate(targetVelocity, currentVel, dt);
        motor.setPower(output);
    }
    else if (mode == ControlMode::Power) {
        motor.setPower(targetPower);
    }
}