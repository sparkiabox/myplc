#include <iostream>
#include <thread>
#include "../../src/myplc.h"

int main() {
    // Initialize
    myplc::TON ton1(milliseconds(2000)); //2 seconds timer on delay

    // Loop Program
    std::cout << std::boolalpha << "Start" << std::endl;
    while (true) {
        ton1.IN = true; // Start Timer
        ton1.execute();
        if (ton1.Q) {
            std::cout << "Tempo executed" << std::endl;
            std::cout << "Q = " << ton1.Q << " and ET = " << ton1.ET.count() << std::endl;
            std::cout << "Reset Tempo..." << std::endl;
            ton1.IN = false;
            ton1.execute();
            std::cout << "Q = " << ton1.Q << " and ET = " << ton1.ET.count() << std::endl;
            break; // Comment out for infinite run
        }
        std::this_thread::sleep_for(milliseconds(10)); // 10ms cycle
    }
    return 0;
}