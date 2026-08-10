//
// Created by Zhengye Chen on 8/10/26.
//

#ifndef PIDCONTROLLER_ROBOT_H
#define PIDCONTROLLER_ROBOT_H


class Robot {
private:
    double position;
    double velocity;
    double acceleration;
    double mass;
    double drag;
    double force;
public:
    Robot(double mass, double drag);
    void update(double dt);
    void applyForce(double output);
    double getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;
};


#endif //PIDCONTROLLER_ROBOT_H
