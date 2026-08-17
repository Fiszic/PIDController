#include <iostream>
#include <cmath>
#include <fstream>
#include "Robot.h"
#include "PID.h"

std::ofstream& extractXYZ(std::ofstream& file, const Vec3& vector) {
    file << vector.x << "," << vector.y << "," << vector.z;
    return file;
}

int main() {
    std::ofstream file("robot_simulation.csv");
    file << "time,x,y,z,v_x,v_y,v_z,a_x,a_y,a_z,x_error,y_error,z_error\n";
    double time = 0.0;
    double tolerance = 0.001;
    Vec3 target(10, 5, 0);
    double mass = 1;
    double drag = 0.2;
    double dt = 0.1;
    Robot robot(mass, drag);
    PID pidX(0.2, 0.0, 0.5);
    PID pidY(0.2, 0.0, 0.5);
    Vec3 error = target;

    double iteration_count = 0;
    while (error.x >tolerance || error.y > tolerance && iteration_count < 10000) {
        Vec3 output(0,0,0);
        if (error.x > tolerance) {
            output.x =pidX.calculate(target.x, robot.getXPosition(), dt);
        }
        if (error.y > tolerance) {
            output.y =pidY.calculate(target.y, robot.getYPosition(), dt);
        }

        robot.applyForce(output);
        robot.update(dt);
        time += dt;
        error.x = std::abs(target.x - robot.getXPosition());
        error.y = std::abs(target.y - robot.getYPosition());
        error.z = std::abs(target.z - robot.getZPosition());
        file << time << ",";
        extractXYZ(file, robot.getPosition());
        file << ",";
        extractXYZ(file, robot.getVelocity());
        file << ",";
        extractXYZ(file, robot.getAcceleration());
        file << ",";
        extractXYZ(file, error);
        file << "\n";
        ++iteration_count;
    }
    file.close();
    return 0;
}