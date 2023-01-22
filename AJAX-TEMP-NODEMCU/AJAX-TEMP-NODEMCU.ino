#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
#define LED D0

const char* ssid = "WiFi Name";
const char* password = "Password";
ESP8266WebServer server(80);
void handleRoot(){
 String s = webpage;
 server.send(200, "text/html", s);
}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/adcread", sensor_data);
  server.begin();
}

void loop(void){
  server.handleClient();
}

void sensor_data(){
 int a = analogRead(A0);
 int temp= a/4.35;
 String sensor_value = String(temp);
 server.send(200, "text/plane", sensor_value);
}
