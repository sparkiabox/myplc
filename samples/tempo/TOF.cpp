#include <iostream>
#include <thread>
#include "../../src/myplc.h"

int main() {
// Declare value here
myplc::TOF tof1;
int8_t STEP_MACHINE = 0;

// Loop Program
while (true) {

    switch (STEP_MACHINE)
    {
    case 0: //init value
        tof1.PT(3s);
        tof1.IN(true);   
        if (tof1.Q()) {  
            std::cout << "TOF Initialized" << std::endl;
            std::cout << "Q = " << tof1.Q() << " and ET = " << tof1.ET() << std::endl;
            STEP_MACHINE = 1;
        }
        break;

    case 1: // Run the TON and Reset it after
        tof1.IN(false);
        if (!tof1.Q()) {  
            std::cout << "Tempo executed" << std::endl;
            std::cout << "Q = " << tof1.Q() << " and ET = " << tof1.ET() << std::endl;
            STEP_MACHINE = 0;
        }
        break;
    
    default:
        break;
    }

    std::this_thread::sleep_for(10ms); // 10ms cycle
}
return 0;
}