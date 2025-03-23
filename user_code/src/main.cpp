#include <iostream>
#include <thread>
#include "../../src/myplc.h"

int main() {
// Declare value here
int8_t STEP_MACHINE = 0;

// Loop Program
while (true) {

    switch (STEP_MACHINE)
    {
    case 0:

        break;

    case 1: // Reset Timer

        break;
    
    default:
        break;
    }

    std::this_thread::sleep_for(10ms); // 10ms cycle
}
return 0;
}