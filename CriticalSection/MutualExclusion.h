//
// Created by desmondzhu0901 on 11/28/17.
//

#ifndef CRITICALSECTION_MUTUALEXCLUSION_H
#define CRITICALSECTION_MUTUALEXCLUSION_H

class MutualExclusion {
public :

    virtual void enteringCriticalSection(int t);

    virtual void leavingCriticalSection(int t);

    static const int TURN_0 = 0;
    static const int TURN_1 = 1;

    static void criticalSection();

    static void nonCriticalSection();

private:
    static const int TIME = 3000;

};

#endif //CRITICALSECTION_MUTUALEXCLUSION_H
