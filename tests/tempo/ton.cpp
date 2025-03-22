#include <iostream>
#include <thread>
#include "../../src/myplc.h"

int main() {
// Declare value here
myplc::TON ton1; //2 seconds timer on delay
int8_t STEP_MACHINE = 0;

// Loop Program
while (true) {

    switch (STEP_MACHINE)
    {
    case 0:
        ton1.PT(3s);     // init Preset Time
        ton1.IN(true);   // Run the TON
        if (ton1.Q()) {  // ton output is true
            std::cout << "Tempo executed" << std::endl;
            std::cout << "Q = " << ton1.Q() << " and ET = " << ton1.ET() << std::endl;
            STEP_MACHINE = 1;
        }
        break;

    case 1: // Reset Timer
        std::cout << "Reset Tempo..." << std::endl;
        ton1.IN(false);
        std::cout << "Q = " << ton1.Q() << " and ET = " << ton1.ET() << std::endl;
        STEP_MACHINE = 0;
        break;
    
    default:
        break;
    }

    std::this_thread::sleep_for(10ms); // 10ms cycle
}
return 0;
}