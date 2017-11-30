#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector> 
#include <mutex>
#include <condition_variable>
#include <deque>
#include <random>

void s(int c) {
    int sum = 0;
    for(int i=1;i<=c;i++) sum += i;
    std::cout << sum << std::endl;
}

int main(int argc, char** argv) {
    
    int c;
    
    std::cin >> c;
    
    std::thread sum(s, c);
    
    sum.join();
}

