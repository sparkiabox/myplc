#include "../../src/myplc.h"

int main() {
// Initialize
myplc::TON ton1; //2 seconds timer on delay
int8_t STEP_MACHINE = 0; //STEP MACHINE of the PLC


// Loop Program
while (true) {

    switch (STEP_MACHINE)
    {
    case 0:  // Init and Start Timer
        ton1.PT = 3s;
        ton1._IN = true;
        ton1.execute();
        if (ton1._Q) {
            STEP_MACHINE = 1;
        }
        break;

    case 1: // Reset Timer
        ton1._IN = false;
        ton1.execute();
        STEP_MACHINE = 0;
        break;
    
    default:
        break;
    }

}
return 0;
}