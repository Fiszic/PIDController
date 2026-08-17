//
// Created by Zhengye Chen on 8/15/26.
//

#include "Encoder.h"

Encoder::Encoder(const int cpr) : counts(0), countsPerRevolution(cpr){}

double Encoder::getPositionDegrees() const  {
    return getPositionRevolutions() * 360.0;
}

double Encoder::getPositionRevolutions() const {
    return static_cast<double>(counts) / countsPerRevolution;
}

void Encoder::update(int64_t newCounts) {
    counts = newCounts;
}

void Encoder::addCounts(int64_t amount, double dt) {
    velocity = static_cast<double>(amount) / dt;
    counts += amount;
}

int64_t Encoder::getCounts() const {
    return counts;
}

double Encoder::getVelocityRPM() const {
    return velocity;
}

void Encoder::reset() {
    counts = 0;
}