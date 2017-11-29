//
// Created by desmondzhu0901 on 11/28/17.
//

#include <iostream>
#include "Worker.h"

Worker::Worker(std::string n, int i, MutualExclusion s) {
    name = n;
    id = i;
    shared = s;
}

void Worker::run() {
    while (true) {
        shared.enteringCriticalSection(id);
        std::cout << name + " is in critical section";
        auto now = static_cast<int>(clock());
        MutualExclusion::criticalSection();

        shared.leavingCriticalSection(id);
        std::cout << name + " is out of critical section";
        std::cout << (clock() - now) / 1000 + "s" << std::endl;
        MutualExclusion::nonCriticalSection();
    }
}
