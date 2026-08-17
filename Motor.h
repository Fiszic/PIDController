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
    double power=0.0;

    double current=0;
    double temperature=25;
    bool is_enabled=false;
public:
    Motor(std::string name, double max_rpm, double max_torque);
    void enable();
    void disable();
    void setPower(double newPower);
    double getPower() const;
    void stop();
private:
    void applyPower();
};


#endif //PIDCONTROLLER_MOTOR_H
