#include "Led.h"
#include <Arduino.h>
#include "Wait.h"

Led::Led(int pin, bool state)
{
    m_pin = pin;
    m_state = state;
    pinMode(pin, OUTPUT);
}

Led::~Led()
{
}

void Led::turnOn(int ms)
{
    digitalWrite(m_pin, HIGH);

    static Wait wait(ms);

    if (wait.timeUp())
    {
        turnOff();
    }
}

void Led::turnOn()
{
    digitalWrite(m_pin, HIGH);
}

void Led::turnOff()
{
    digitalWrite(m_pin, LOW);
}

int Led::getPin()
{
    return m_pin;
}

bool Led::getState()
{
    return m_state;
}

void Led::setPin(int pin)
{
    m_pin = pin;
}

void Led::setState(bool state)
{
    m_state = state;
}
