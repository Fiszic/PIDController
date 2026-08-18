//
// Created by Zhengye Chen on 8/16/26.
//

#ifndef PIDCONTROLLER_MOTORCONTROLLER_H
#define PIDCONTROLLER_MOTORCONTROLLER_H
#include "Motor.h"
#include "PID.h"
#include "Encoder.h"

enum class ControlMode {
    Power,
    Velocity,
    Position
};

class MotorController {
private:
    Motor motor;
    Encoder encoder;
    PID positionPID;
    PID velocityPID;

    ControlMode mode=ControlMode::Power;

    double targetPosition=0;
    double targetVelocity=0;
    double targetPower=0;
public:
    MotorController(const std::string &name, double kp, double ki, double kd, double vkp, double vki, double vkd, double max_rpm, double max_torque, int cpr);
    void setPower(double target);
    void setTargetPosition(double target);
    void setTargetVelocity(double target);
    void update(double dt);
};


#endif //PIDCONTROLLER_MOTORCONTROLLER_H
