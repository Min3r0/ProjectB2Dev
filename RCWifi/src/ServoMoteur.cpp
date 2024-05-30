#include "ServoMoteur.h"

ServoMoteur::ServoMoteur(int pin, int init_degrees) : m_pin(pin), m_init_degrees(init_degrees) {
    m_servo.attach(m_pin);
    m_servo.write(m_init_degrees);  
}

ServoMoteur::~ServoMoteur() {
    m_servo.detach();
}

void ServoMoteur::setPin(int pin) {
    m_pin = pin;
    m_servo.attach(m_pin);
}

void ServoMoteur::setDegrees(int init_degrees) {
    m_init_degrees = init_degrees;
    m_servo.write(m_init_degrees);
}

int ServoMoteur::getPin() {
    return m_pin;
}

int ServoMoteur::getDegrees() {
    return m_init_degrees;
}

void ServoMoteur::turn(int degrees) {
    m_servo.write(degrees);
}
