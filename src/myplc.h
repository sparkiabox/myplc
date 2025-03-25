#ifndef MYPLC_H
#define MYPLC_H
#include <chrono>
using namespace std::chrono_literals;

namespace myplc {

    // Timer On Delay class (TON)
    class TON {

    protected:
        bool _IN = false ; 
        bool _Q  = false ;  
        std::chrono::milliseconds _PT = 0ms; 
        std::chrono::milliseconds _ET = 0ms; 

        bool old_IN = false; // Previous input state for edge detection
        bool running=false; // Timer active flag
        std::chrono::time_point<std::chrono::system_clock> start ; // Timer start time

    public: //Abstraction Functions
        virtual void IN(bool); // Input Trigger 
        void PT(std::chrono::milliseconds init_PT) {_PT = init_PT;} // Preset time to reach before _Q activates
        int32_t ET(){return _ET.count();} // Elapsed time
        bool Q(){return _Q;} // Output signal

    };

    class TOF : public TON {
    public :
        void IN(bool) override;
    };

}

#endif
