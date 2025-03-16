#include "myplc.h"

namespace myplc {

    void TON::execute() { 

        //Rising Edge of the input trigger
        if(IN && !old_IN && (PT >= milliseconds(0))) {
            start=std::chrono::system_clock::now();
            ET = milliseconds(0);
            Q = false;
            running = true;
            old_IN = true;
        }

        //Falling Edge of the input trigger
        if (!IN && old_IN) {
            ET = milliseconds(0);
            Q = false;
            running = false;
            old_IN = false;
        }

        //Tempo Running 
        if(running) {
            auto now = std::chrono::system_clock::now();
            ET = std::chrono::duration_cast<milliseconds>(now-start);
            if (ET >= PT) {
                Q = true;
            }
        }

    }

    
}