//Created by Venkata Vaibhav Bhagavatula
//For the Wireless Communications Project
//TOPIC: SWARM ROBOTICS//
//TCP/IP


#include <ESP8266WiFi.h>                //Header for the ESP8266 WiFi module


char ssid[] = "bbramasarma";           // SSID of  WiFi
char pass[] = "9441924418";            // password of WiFi


IPAddress server(192,168,0,80);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // Baud Rate
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {           //Checking for the connection to be established
    Serial.print(".");
    delay(500);
  }
}
String h;
void loop () {
  client.connect(server, 80);        // Connection to the server
  h = Serial.readString();           // read the message
  client.println(h);                // sends the message to the server
  client.flush();                   //Clear the already read content from client
  delay(2000);     
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  if(answer != "\0"){
  Serial.println("from server: " + answer);    //Message received from server
  } 
  }
