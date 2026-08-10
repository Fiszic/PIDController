//
// Created by Zhengye Chen on 8/9/26.
//

#ifndef PIDCONTROLLER_PID_H
#define PIDCONTROLLER_PID_H


class PID {
private:
    double kp;
    double ki;
    double kd;
    double integral=0;
    double previous_error=0;
public:
    PID(double kp, double ki, double kd);
    double calculate(double target, double pos, double dt);
};


#endif //PIDCONTROLLER_PID_H
