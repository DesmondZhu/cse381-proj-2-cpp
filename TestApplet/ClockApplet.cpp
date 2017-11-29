//
// Created by desmondzhu0901 on 11/28/17.
//

#include "ClockApplet.h"

void ClockApplet::run() {
    while (!m_stop) {
        try {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        catch (std::exception &e) {}
    }
}

void ClockApplet::destroy() {
    if (!m_thread.joinable()) {
        m_stop = true;
        m_thread.detach();
    }
}

void ClockApplet::stop() {
    if (!m_thread.joinable()) {
        m_stop = true;
        m_thread.join();
    }
}

void ClockApplet::start() {
    if (!m_thread.joinable()) {
        ClockApplet::run();
    } else
        m_thread.detach();
}
