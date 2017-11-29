//
// Created by desmondzhu0901 on 11/28/17.
//

#include "Driver.h"
int main(int argc, const char* argv[]){
    if(argc > 0){
        if((int)argv[0] < 0){
            std::cerr << argv[0] << " must be >= 0" << std::endl;
        } else {
            auto *sumObject = new Sum();
            int upper = (int)argv[0];
            std::thread *thrd = new std::thread(new Summation(upper, sumObject, (int)argv[1]));
            try {
                thrd->join();
                std::cout << "The sum of " << upper << " is " << sumObject->getSum();
            } catch (std::exception &ie) {}
        }
    }
    else
        std::cerr <<"Usage: Summation <integer value>";
}
