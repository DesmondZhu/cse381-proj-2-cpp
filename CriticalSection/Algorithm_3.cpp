//
// Created by desmondzhu0901 on 11/28/17.
//

#include "Algorithm_3.h"
#include "thread"

bool Algorithm_3::flag[2];
int Algorithm_3::turn;

Algorithm_3::Algorithm_3() {
    flag[0] = false;
    flag[1] = false;
    turn = TURN_0;
}

void Algorithm_3::enteringCriticalSection(int t) {
    int other;
    other = 1 - t;
    flag[t] = true;
    turn = other;
    while (flag[other] && (turn == other))
        std::this_thread::yield();
}

void Algorithm_3::leavingCriticalSection(int t) {
    flag[t] = false;
};