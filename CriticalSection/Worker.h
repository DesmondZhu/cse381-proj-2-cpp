//
// Created by desmondzhu0901 on 11/28/17.
//

#ifndef CRITICALSECTION_WORKER_H
#define CRITICALSECTION_WORKER_H


#include "MutualExclusion.h"
#include "string"
#include <thread>

class Worker : public std::thread {
private:
    std::string name;
    int id;
    MutualExclusion shared;
public:
    void run();

    Worker(std::string n, int i, MutualExclusion s);
};


#endif //CRITICALSECTION_WORKER_H
