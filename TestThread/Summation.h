//
// Created by desmondzhu0901 on 11/28/17.
//

#ifndef TESTTHREAD_SUMMATION_H
#define TESTTHREAD_SUMMATION_H


#include "Sum.h"

class Summation {
private:
    int upper;
    Sum sumValue;
    int power;
public:
    Summation(int upper, Sum *sumValue, int power);
    void run();
};


#endif //TESTTHREAD_SUMMATION_H
