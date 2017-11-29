//
// Created by desmondzhu0901 on 11/28/17.
//

#ifndef CRITICALSECTION_ALGORITHM_3_H
#define CRITICALSECTION_ALGORITHM_3_H


#include "MutualExclusion.h"

class Algorithm_3 : public MutualExclusion {
public:

    Algorithm_3();

    static bool flag[2];
    static int turn;

    void enteringCriticalSection(int t) override;

    void leavingCriticalSection(int t) override;
};


#endif //CRITICALSECTION_ALGORITHM_3_H
