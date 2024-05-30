#ifndef WAIT_H
#define WAIT_H

#include <Arduino.h>

class Wait {
  public:
    Wait(unsigned long interval);
    bool timeUp();
    void reset();
    
  private:
    unsigned long _previousTime;
    unsigned long _interval;
};

#endif
