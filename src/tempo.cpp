#include "myplc.h"

namespace myplc {

    void TON::IN(bool _IN) {
        //Rising Edge of the input trigger
        if(_IN && !old_IN && (_PT >= 0ms)) {
            start=std::chrono::system_clock::now();
            _ET = 0ms;
            _Q = false;
            running = true;
            old_IN = true;
        }

        //Falling Edge of the input trigger
        if (!_IN && old_IN) {
            _ET = 0ms;
            _Q = false;
            running = false;
            old_IN = false;
        }

        //Tempo Running 
        if(running) {
            auto now = std::chrono::system_clock::now();
            _ET = std::chrono::duration_cast<std::chrono::milliseconds>(now-start);
            if (_ET >= _PT) {
                _Q = true;
                running = false;
            }
        }

    }

}

