//
// Created by desmondzhu0901 on 11/28/17.
//


#include "thread"
#include "random"
#include "MutualExclusion.h"

void MutualExclusion::criticalSection() {
    try {
        std::this_thread::sleep_for(std::chrono::microseconds(random() * MutualExclusion::TIME));

    } catch (std::exception &e) {}
}

void MutualExclusion::nonCriticalSection() {
    try {
        std::this_thread::sleep_for(std::chrono::microseconds(random() * MutualExclusion::TIME));
    } catch (std::exception &e) {}
}

void MutualExclusion::enteringCriticalSection(int t) {

}

void MutualExclusion::leavingCriticalSection(int t) {

}

