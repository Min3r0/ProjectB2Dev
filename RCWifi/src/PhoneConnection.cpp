#include <WiFi.h>
#include "PhoneConnection.h"
#include "Led.h"
#include <constants.h>
Led red_bis_led(RED_LED_PIN, false);

void connectionWifi(){
    WiFi.mode(WIFI_STA);   //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        red_bis_led.turnOn();
        delay(100);
        red_bis_led.turnOff();
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
}
