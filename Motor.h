//
// Created by Zhengye Chen on 8/15/26.
//

#ifndef PIDCONTROLLER_MOTOR_H
#define PIDCONTROLLER_MOTOR_H

#include <string>

class Motor {
private:
    std::string name;
    double max_rpm;
    double max_torque;

    double actual_rpm=0;
    double target_rpm=0;
    double current=0;
    double temperature=25;
    bool is_enabled=false;
public:
    Motor(std::string name, double max_rpm, double max_torque);
    void enable();
    void disable();
    void set_speed(double rpm);
    void stop();
};


#endif //PIDCONTROLLER_MOTOR_H
