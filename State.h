//
// Created by Zhengye Chen on 8/11/26.
//

#ifndef PIDCONTROLLER_POINT_H
#define PIDCONTROLLER_POINT_H
#include <valarray>

#endif //PIDCONTROLLER_POINT_H

struct Vec3 {
    double x;
    double y;
    double z;

    void set(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double distance(const Vec3 &other) const {
        return std::sqrt((std::pow(x-other.x,2)+std::pow(y-other.y,2)+std::pow(z-other.z,2)));
    }

    double distance2D(const Vec3 &other) const {
        return std::sqrt((std::pow(x-other.x,2)+std::pow(y-other.y,2)));
    }
};

struct State {
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
};