#include "ToggleButton.h"

ToggleButton::ToggleButton(int buttonPin, void (*pushFunction)(int), void (*holdFunction)())
{
  m_pushFunction = pushFunction;
  m_holdFunction = holdFunction;
  
  m_pin = buttonPin;

  m_current_state = false;
  
  m_hold_fired = false;
  m_pressCount_fired = true;
  m_toggled = false;

  m_switch_time = 0;
  m_pressCount = 0;
  pinMode(m_pin, INPUT_PULLUP);
}

void ToggleButton::update()
{
  unsigned long millisec = millis();
  
  bool pinState = !digitalRead(m_pin);
  
  if (pinState != m_last_pin_state)
  {
    m_switch_time = millisec;
    m_toggled = false;
  }
 
  unsigned long timeSinceSwitch = millisec - m_switch_time;
  
  if (!m_toggled && timeSinceSwitch > ((unsigned long)(DEBOUNCE_DELAY))) // TOGGLE STATE
  {
    m_current_state = pinState;
    
    if(m_current_state) //debounce signal going up
    {
      m_pressCount++;
      m_hold_fired = false;
      m_pressCount_fired = false;
    }
    
    // reset both event triggers
    m_toggled = true;
  }

  if(m_current_state) // ON
  {
    if (!m_hold_fired && timeSinceSwitch > ((unsigned long)(HOLD_THRESHOLD))) // HOLD
    {
      if (m_holdFunction)
        m_holdFunction();

      m_hold_fired = true;
    }
    
  }
  else // OFF
  {
    if (!m_pressCount_fired && timeSinceSwitch > ((unsigned long)(RELEASE_DELAY)))
    {
      if (!m_hold_fired && m_pushFunction)
          m_pushFunction(m_pressCount);
      m_pressCount = 0;
      m_pressCount_fired = true;
    }
  }
  
  m_last_pin_state = pinState;
}
