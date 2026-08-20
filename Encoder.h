//
// Created by Zhengye Chen on 8/15/26.
//

#ifndef PIDCONTROLLER_ENCODER_H
#define PIDCONTROLLER_ENCODER_H
#include <cstdint>


class Encoder {
private:
    int64_t counts;
    int countsPerRevolution;
    double velocity=0;
public:
    Encoder(int cpr);
    double getDegrees() const;
    double getRevolutions() const;
    void update(int64_t newCounts);
    void addCounts(int64_t amount, double dt);
    int64_t getCounts() const;
    double getVelocityRPM() const;
    void reset();
};


#endif //PIDCONTROLLER_ENCODER_H
