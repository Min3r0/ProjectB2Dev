#ifndef SERVO_MOTEUR_H
#define SERVO_MOTEUR_H

#include <Arduino.h>
#include <Servo.h>  // Inclusion de la bibliothèque Arduino Servo

class ServoMoteur {
    private:
        int m_pin;
        int m_init_degrees;
        Servo m_servo;  // Instance de la classe Servo d'Arduino
    
    public:
        ServoMoteur(int pin, int init_degrees);
        ~ServoMoteur();

        void setPin(int pin);
        void setDegrees(int init_degrees);

        int getPin();
        int getDegrees();

        void turn(int degrees);
};

#endif
