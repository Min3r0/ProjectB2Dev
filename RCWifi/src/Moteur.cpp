#include <Arduino.h>
#include "Moteur.h"

Moteur::Moteur(int pin)
{
    m_pin = pin;
}

Moteur::~Moteur()
{
}

void Moteur::setPin(int pin){
    m_pin=pin;
}

int Moteur::getPin(){
    return m_pin;
}

void Moteur::acceleration(int value){
    analogWrite(m_pin, value);
}

void Moteur::off(){
    digitalWrite(m_pin, LOW);
}