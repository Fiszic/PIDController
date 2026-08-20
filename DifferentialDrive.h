//
// Created by Zhengye Chen on 8/18/26.
//

#ifndef PIDCONTROLLER_DIFFERENTIALDRIVE_H
#define PIDCONTROLLER_DIFFERENTIALDRIVE_H

#include "MotorController.h"
#include <numbers>

class DifferentialDrive {
private:
    MotorController leftMotor;
    MotorController rightMotor;

    double wheelRadius;
    double trackWidth;

    double x=0;
    double y=0;
    double theta=0;

    double previousLeftDistance=0;
    double previousRightDistance=0;
public:
    DifferentialDrive(double wheelRadius, double trackWidth);
    void setVelocity(double leftVelocity, double rightVelocity);
    void arcadeDrive(double forward, double rotation);
    void stop();
    void update(double dt);
    void updateOdometry(double dt);
};


#endif //PIDCONTROLLER_DIFFERENTIALDRIVE_H
