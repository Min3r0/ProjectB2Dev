#ifndef LED_H
#define LED_H

class Led {
    private:
        int m_pin;
        bool m_state;
    
    public:
        Led(int pin, bool state);
        ~Led();
        void turnOn(int ms);
        void turnOn();
        void turnOff();
        
        int getPin();
        bool getState();

        void setPin(int pin);
        void setState(bool state);
};


#endif