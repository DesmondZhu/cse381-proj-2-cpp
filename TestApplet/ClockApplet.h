//
// Created by desmondzhu0901 on 11/28/17.
//

#ifndef TESTAPPLET_CLOCKAPPLET_H
#define TESTAPPLET_CLOCKAPPLET_H

#include "thread"

class ClockApplet {
public:
    void run();

    void start();

    void stop();

    void destroy();

private:
    bool m_stop;
    std::thread m_thread;
};


#endif //TESTAPPLET_CLOCKAPPLET_H
