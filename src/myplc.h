#ifndef MYPLC_H
#define MYPLC_H
#include <chrono>
using std::chrono::milliseconds;

namespace myplc {

    // Timer On Delay (TON) for PLC-style timing
    class TON {

    private:
        bool old_IN = false; // Previous input state for edge detection
        bool running=false; // Timer active flag
        std::chrono::time_point<std::chrono::system_clock> start ; // Timer start time

    public:
        bool IN = false; // Input Trigger 
        bool Q  = false;  // Output signal
        milliseconds ET = milliseconds(0); // Elapsed time
        milliseconds PT = milliseconds(0); // Preset time to reach before Q activates
        void execute(); //Execute one timer cycle
        
        TON(milliseconds init_PT) {
            PT = init_PT;
        }

    };

}

#endif