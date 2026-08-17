//
// Created by Zhengye Chen on 8/15/26.
//

#include "Encoder.h"

Encoder::Encoder(const int cpr) : counts(0), countsPerRevolution(cpr){}

double Encoder::getPositionDegrees() const  {
    return (static_cast<double>(counts) / countsPerRevolution) * 360.0;
}

void Encoder::reset() {
    counts = 0;
}