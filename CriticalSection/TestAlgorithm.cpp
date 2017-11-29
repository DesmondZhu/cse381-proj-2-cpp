//
// Created by desmondzhu0901 on 11/28/17.
//

#include "MutualExclusion.h"
#include "Worker.h"

int main(int argc, const char **argv) {
    MutualExclusion alg;

    Worker *first = new Worker("Running 0", 0, alg);
    Worker *second = new Worker("Running 1", 1, alg);

    first->run();
    second->run();
}
