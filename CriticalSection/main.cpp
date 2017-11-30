#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector> 
#include <mutex>
#include <condition_variable>
#include <deque>
#include <random>

int napTime = 5;
int turn = 0;
void w(int t, bool flag[]) {
    while(true) {
        int other = 1 - t;
	flag[t] = true;
	turn = other;
	while (flag[other] == true && (turn == other))
            std::this_thread::yield();
        int sleeptime = rand() % napTime;
        std::cout << "worker " << t << "entering critical section" << std::endl;
        
        std::this_thread::sleep_for (std::chrono::seconds(sleeptime));
        
        std::cout << "worker " << t << "leaving critical section" << std::endl;
        flag[t] = false;
    }
}

int main(int argc, char** argv) {
    
    bool flag[] = {false, false};
    
    std::thread w1(w, 0, flag);
    std::thread w2(w, 1, flag);
    
    w1.join();
    w2.join();
}

