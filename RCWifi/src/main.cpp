#include <WiFi.h>
#include <constants.h>
#include "PhoneConnection.h"
#include "createWifi.h"
#include "Led.h"
#include "ServoMoteur.h"
#include "Moteur.h"

// Initialisation des Variables et des Objets

Led red_led(RED_LED_PIN, false);
Led green_led(GREEN_LED_PIN, false);
ServoMoteur servoMotor(SERVO_PIN, INIT_DEGREES);
Moteur backMotor(MOTEUR_PIN);
int acc, dir;
String strX, strY;

void erreurconnection();

void setup()
{

    Serial.begin(115200);
    delay(1000);
    switch (TypeOfConnection)
    {
    case 0:
        connectionWifi();
        green_led.turnOn();
        break;
    case 1:
        createWifi();
        break;
    default:
        erreurconnection();
    }
}

void loop()
{
    /*
    En Theorie

    String value = server.arg("LEDstatexy"); //LEDstatexy donnée envoyée par le serveur de la forme "LEDstatexy=X_VALUE Y_VALUE"
    value.remove(0, 20); //garde seulement X_VALUE Y_VALUE

    //sépare les valeurs de X et Y et retire 'x=' et 'y='
    for (int i = 0; i < value.length(); i++) { 
    if (value.substring(i, i + 1) == " ") {
        strX = value.substring(0, i);
        strY = value.substring(i + 1);
        strX.remove(0, 3);
        strY.remove(0, 3);
        break;
        }
    }

    //convertie String to INT
    int x = strX.toInt();
    int y = strY.toInt();
    
    acc = x;
    dir = y;
    */

    if (acc < 0) acc = 0;
    if (acc > 200) acc = 200;
    if (acc > 0){
        acc = map(acc, 0,200,100,1023);
        backMotor.acceleration(acc);
    }else{
        backMotor.off();
    }

    if (dir > 200) dir = 200;
    if (dir < -200) dir = -200;
    if (dir > 0){
        dir = map(dir, 0,200, 90, 125); //angle de 35° max
        servoMotor.turn(dir);
    }else if (dir<0){
        dir = map(dir , -200, 0, 55, 90); //angle de 35° max
        servoMotor.turn(dir);
    }else {
        servoMotor.turn(90);
    }
    




}

void erreurconnection()
{
    while (true)
    {
        red_led.turnOn(500);
        green_led.turnOn(450);
    }
}
