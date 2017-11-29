//
// Created by desmondzhu0901 on 11/28/17.
//

#include <complex>
#include "Summation.h"

Summation::Summation(int upper, Sum *sumValue, int power) {
    this->upper;
    this->sumValue;
    this->power;
}

void Summation::run() {
    int sum = 0;
    for(int i=0; i<= upper; i++)
        sum += std::pow(i, power);
    sumValue.setSum(sum);
}
