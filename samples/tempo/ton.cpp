#include "../../src/myplc.h"

int main() {
    // Initialize
    myplc::TON ton1(milliseconds(2000));//2s Timer on delay

    // Loop Program
    while (true) {
        ton1.IN = true; // Start Timer
        ton1.execute(); //execute Timer
        if (ton1.Q) { 
            /*Your code here
            use ton1.ET.count() to get the elapsed time,
            */
           //Reset After Q is set
            ton1.IN = false;
            ton1.execute();
        }
    }

    return 0;
}