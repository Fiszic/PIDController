//
// Created by Zhengye Chen on 8/21/26.
//

#ifndef PIDCONTROLLER_GYROSCOPE_H
#define PIDCONTROLLER_GYROSCOPE_H


class Gyroscope {
private:
    double angularVelocity;
    double angle;
    double bias;
public:
    Gyroscope(double bias);
    void update(double trueAngularVelocity, double dt);
    double getAngularVelocity() const;
    double getAngle() const;
    void reset();
};


#endif //PIDCONTROLLER_GYROSCOPE_H
