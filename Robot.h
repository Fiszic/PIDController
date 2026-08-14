//
// Created by Zhengye Chen on 8/10/26.
//

#ifndef PIDCONTROLLER_ROBOT_H
#define PIDCONTROLLER_ROBOT_H
#include "State.h"


class Robot {
private:
    State state;
    double mass;
    double drag;
    Vec3 force;
public:
    Robot(double mass, double drag);
    void update(double dt);
    void applyForce(const Vec3 &output);
    const Vec3& getPosition() const;
    const Vec3& getVelocity() const;
    const Vec3& getAcceleration() const;
    double getXPosition() const;
    double getYPosition() const;
    double getZPosition() const;
    double getXVelocity() const;
    double getYVelocity() const;
    double getZVelocity() const;
    double getXAcceleration() const;
    double getYAcceleration() const;
    double getZAcceleration() const;
};


#endif //PIDCONTROLLER_ROBOT_H
