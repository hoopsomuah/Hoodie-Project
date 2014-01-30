#ifndef _TOGGLEBUTTON_h
#define _TOGGLEBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define HOLD_THRESHOLD 1000
#define RELEASE_DELAY 300
#define DEBOUNCE_DELAY 50



class ToggleButton
{
private:
    bool m_current_state;
    bool m_last_pin_state;
    
    bool m_hold_fired;
    bool m_pressCount_fired;
    bool m_toggled;

    unsigned long m_switch_time;
    
    int m_pin;
    
    void (*m_holdFunction)();
    void (*m_pushFunction)(int);
    
    int m_pressCount;


public:
    ToggleButton(int buttonPin, void (*pushFunction)(int), void (*holdFunction)());
    void update();
};


#endif // _TOGGLEBUTTON_h
