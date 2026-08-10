#include <iostream>
#include <cmath>
#include <fstream>
#include "Robot.h"
#include "PID.h"


int main() {
    double tolerance = 0.001;
    double target = 10;
    double mass = 1;
    double drag = 0.1;
    double dt = 0.1;
    Robot robot(mass, drag);
    PID pid(0.2, 0.0, 0.3);

    double iteration_count = 0;
    while (std::abs(target - robot.getPosition()) > tolerance && iteration_count < 10000) {
        double force = pid.calculate(target, robot.getPosition(), dt);

        robot.applyForce(force);
        robot.update(dt);
        ++iteration_count;
    }
    return 0;
}