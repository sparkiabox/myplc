#include <iostream>
#include <thread>
#include "../../src/myplc.h"

int main() {
// Declare value here
myplc::TP tp1;
int8_t STEP_MACHINE = 0;

// Loop Program
while (true) {

    switch (STEP_MACHINE)
    {
    case 0: //init value
        tp1.PT(3s);
        tp1.IN(false);   
        if (!tp1.Q()) {  
            STEP_MACHINE = 1;
            std::cout << "TP Initialized" << std::endl;
            std::cout << "Q = " << tp1.Q() << " and ET = " << tp1.ET() << std::endl;
        }
        break;

    case 1: // Run the TON
        tp1.IN(true);
        if (!tp1.Q()) {  
            std::cout << "Tempo Executing" << std::endl;
            std::cout << "Q = " << tp1.Q() << " and ET = " << tp1.ET() << std::endl;
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