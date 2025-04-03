#include "../myplc.h"

namespace myplc {

    bool R_TRIG::CLK(bool _CLK){
        static bool old_CLK = false;
        static bool Q = false;
        if (_CLK && !old_CLK) {
            Q=true; 
            old_CLK=true;
        } 
        else {
            Q=false; 
            old_CLK=false;
        } 
        return Q;
    
    };

    bool F_TRIG::CLK(bool _CLK){
        static bool old_CLK = false;
        static bool Q = false;
        if (!_CLK && old_CLK) {
            Q=true; 
            old_CLK=true;
        } 
        else {
            Q=false; 
            old_CLK=false;
        } 
        return Q;
    
    };
    
    
}