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
public:
    Encoder(int cpr);
    double getPositionDegrees() const;
    void reset();
};


#endif //PIDCONTROLLER_ENCODER_H
