#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 5
    
DHT dht(dht_dpin, DHTTYPE); 
  

WiFiClient espClient;
PubSubClient client(espClient);

String data;
const char* ssid = "mi_red";
const char* password = "mi_contraseña";
const char* mqttServer = "server_mqtt"; // MQTT Broker en la Raspberry
const int mqttPort = 1883;

void temperature(){
  float t = dht.readTemperature();
  int dat = (int)t;         
  Serial.print("temperature = ");
  Serial.println(dat); 
  char temperaturenow [15];
  //dtostrf(t ,4, 0, temperaturenow); // convert float to char
  sprintf(temperaturenow, "%d", dat);
  client.publish("temp", temperaturenow); // send char
  delay(800);
}

void setup() {
  //pinMode(LED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  //Wire.begin(D2, D1);
  delay(700);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266Client1")) {
      Serial.println("connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  client.subscribe("temp");
}
void loop() {
  temperature();
  client.loop();
  delay(1000);
}
