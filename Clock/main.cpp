#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector> 
#include <mutex>
#include <condition_variable>
#include <deque>
#include <random>

void c() {
    while(true){
        std::this_thread::sleep_for (std::chrono::seconds(1));
        system("clear");
        time_t now = time(0);
        
        std::cout << ctime(&now);
        
        
    }
}

int main(int argc, char** argv) {
    
    
    std::thread clock(c);
    
    clock.join();
}

