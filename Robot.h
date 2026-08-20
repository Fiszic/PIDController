//
// Created by Zhengye Chen on 8/10/26.
//

#ifndef PIDCONTROLLER_ROBOT_H
#define PIDCONTROLLER_ROBOT_H
#include "DifferentialDrive.h"


class Robot {
private:
    DifferentialDrive drive;
    double mass;
    double drag;
public:
    Robot(double mass, double drag);
    void update(double dt);
    void driveForward(double velocity);
    void turn(double velocity);
    void stop();
};


#endif //PIDCONTROLLER_ROBOT_H
