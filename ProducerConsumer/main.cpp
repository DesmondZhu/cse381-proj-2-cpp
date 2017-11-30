#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector>
#include <chrono> 

void p(std::vector<time_t> queue, int napTime) {
    while(true) {
        int sleeptime = rand() % napTime;
        std::cout << "Producer sleeping for " << sleeptime << " seconds" << std::endl;
        
        std::this_thread::sleep_for (std::chrono::seconds(sleeptime));
        
        time_t now = time(0);
        
        queue.push_back(now);
        
        std::cout << "Producer produced " << ctime(&now) << std::endl;
    }
}

void c(std::vector<time_t> queue, int napTime) {
    while(true) {
        int sleeptime = rand() % napTime;
        std::cout << "Producer sleeping for " << sleeptime << " seconds" << std::endl;
        
        std::this_thread::sleep_for (std::chrono::seconds(sleeptime));
        
        if(!queue.empty()) {
            time_t now = queue.back();
            queue.pop_back();
            
            std::cout << "Consumer produced " << ctime(&now) << std::endl;
        }
    }
}
int main(int argc, char** argv) {
    std::vector<time_t> queue;
    
    std::thread producer(p, queue, 5);
    std::thread consumer(c, queue, 5);
    
    producer.join();
    consumer.join();
}

