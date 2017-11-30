#include <iostream>       // std::cout
#include <thread> 
#include <ctime>
#include <vector> 
#include <mutex>
#include <condition_variable>
#include <deque>

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
};

Queue<std::string> q;

void p() {
    std::vector<std::string> v;
    v.push_back("Mares eat oats");
    v.push_back("Does eat oats");
    v.push_back("Little lambs eat ivy");
    v.push_back("Wouldn't you eat ivy too?");
    
    for(int i=0;i<v.size();i++) {
        q.push(v.at(i));
    }
    q.push("done");
    
}

void c() {
    std::string c = "not done";
    while(c.compare("done") != 0) {
        c = q.pop();
        if(c.compare("done") != 0)
        std::cout << c << std::endl;
    } 
}

int main(int argc, char** argv) {
    
    
    std::thread producer(p);
    std::thread consumer(c);
    
    producer.join();
    consumer.join();
}

