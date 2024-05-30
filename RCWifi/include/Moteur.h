#ifndef MOTEUR_H
#define MOTEUR_H

class Moteur {
    private:
        int m_pin;
        
    public:
        Moteur(int pin);
        ~Moteur();

        void setPin(int pin);

        int getPin();

        void acceleration(int value);
        void off();
};

#endif