#include <iostream>
#include <cmath>
#include <fstream>

int main() {
    std::ofstream file("pid_simulation.csv");
    file << "time,position,velocity,error\n";
    int iteration_count = 0;
    double target = 10.0;
    double pos = 0.0;
    double tolerance = 0.001;
    double mass = 1;

    double kp = 0.2;
    double ki = 0;
    double kd = 0.3;

    double prev_error = target - pos;
    double error = target - pos;
    double integral = 0;
    double deriv = 0;
    double dt = 0.1;
    double time = 0;
    double accel = 0;

    double P = 0;
    double I = 0;
    double D = 0;

    double output = 0;
    double velocity = 0;
    while (std::abs(target - pos) > tolerance && iteration_count < 10000) {
        integral += error * dt;
        deriv = (error - prev_error) / dt;

        P = kp * error;
        I = ki * integral;
        D = kd * deriv;

        output = P + I + D;
        accel = output / mass;
        velocity += accel * dt;
        pos += velocity * dt;
        prev_error = error;
        time += dt;
        error = target - pos;
        file << time << ","<< pos << ","<< velocity << ","<< error << "\n";
        ++iteration_count;
    }
    file.close();
    return 0;
}