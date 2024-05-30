#include "wait.h"

Wait::Wait(unsigned long interval) {
  _interval = interval;
  _previousTime = millis();
}

bool Wait::timeUp() {
  unsigned long currentTime = millis();
  if (currentTime - _previousTime >= _interval) {
    _previousTime = currentTime;
    return true;
  }
  return false;
}

void Wait::reset() {
  _previousTime = millis();
}
