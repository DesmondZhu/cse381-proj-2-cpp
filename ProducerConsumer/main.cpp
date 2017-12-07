#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector>
#include <chrono> 
#include <deque>
#include <mutex>
#include <condition_variable>

template <typename T>
class Queue
{
    private:
        std::mutex              d_mutex;
        std::condition_variable d_condition;
        std::deque<T>           d_queue;
        public:
            void push(T const& value) {
                {
                    std::unique_lock<std::mutex> lock(this->d_mutex);
                    d_queue.push_front(value);
                }
                this->d_condition.notify_one();
            }
            T pop() {
                std::unique_lock<std::mutex> lock(this->d_mutex);
                this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
                T rc(std::move(this->d_queue.back()));
                this->d_queue.pop_back();
                return rc;
            }
            
            bool empty() {
				
				return d_queue.empty();
			}
};

Queue<time_t> queue;

void p(int napTime) {
    while(true) {
        int sleeptime = rand() % napTime;
        std::cout << "Producer sleeping for " << sleeptime << " seconds" << std::endl;
        
        std::this_thread::sleep_for (std::chrono::seconds(sleeptime));
        
        time_t now = time(0);
        
        queue.push(now);
        
        std::cout << "Producer produced " << ctime(&now) << std::endl;
    }
}

void c(int napTime) {
    while(true) {
        int sleeptime = rand() % napTime;
        std::cout << "Producer sleeping for " << sleeptime << " seconds" << std::endl;
        
        std::this_thread::sleep_for (std::chrono::seconds(sleeptime));
        
        if(!queue.empty()) {
            
            time_t now = queue.pop();
            
            std::cout << "Consumer produced " << ctime(&now) << std::endl;
        }
    }
}
int main(int argc, char** argv) {
    //std::vector<time_t> queue;
    
    std::thread producer(p, 5);
    std::thread consumer(c, 5);
    
    producer.join();
    consumer.join();
}

