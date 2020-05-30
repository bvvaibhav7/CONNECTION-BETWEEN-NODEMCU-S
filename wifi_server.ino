//Created by Venkata Vaibhav Bhagavatula
//For the Wireless Communications Project
//TOPIC: SWARM ROBOTICS//

#include <ESP8266WiFi.h>                  //Header for the ESP8266 WiFi module


char ssid[] = "bbramasarma";               // SSID 
char pass[] = "9441924418";               // password
WiFiServer server(80);                    

IPAddress ip(192, 168, 0, 80);            // IP address of the server
IPAddress gateway(192,168,0,1);           // gateway of network
IPAddress subnet(255,255,255,0);          // subnet mask of network

void setup() {
  Serial.begin(115200);                   // Baud rate
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {       //Checking for the connection to be established
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      String request = client.readStringUntil('\r');   // receives the message from the client
      if(request!="\0"){
      Serial.print("From client: "); Serial.println(request);  //Print received message
      }
      client.flush();
      //String h;
       //h = Serial.readString();                   // Read the message to be sent
        client.println("Have you received");        // sends the message to the server
      }
    }
 }
