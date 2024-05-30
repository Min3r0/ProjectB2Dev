#include <WiFi.h>
#include <constants.h>
#include "createWifi.h"

void createWifi(){
  
  WiFi.softAP(ssidESPWifi, passwordESPWifi);

  Serial.println("Access Point Mode");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}