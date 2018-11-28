#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#define LED D1           

WiFiClient espClient;
PubSubClient client(espClient);
String data;
const char* ssid = "mi_red";
const char* password = "mi_contraseña";
const char* mqttServer = "server_mqtt"; // MQTT Broker en la Raspberry
const int mqttPort = 1883;   // puerto del server mqtt

void callback(char* topic, byte* payload, unsigned int length) {
  delay(1000);
  char dataArray[length];
  for (int i=0;i<length;i++) {
    
    dataArray[i] = (char)payload[i];
  }
  data = dataArray;
  Serial.println(length);
  Serial.println(data);
  
  float value;
  value = data .toFloat();
  if (value > 29) {
    Serial.println("LOW");
    digitalWrite(LED, LOW);
  } else {
    Serial.println("HIGH");
    digitalWrite(LED, HIGH);
  }
}
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  //Wire.begin(D2, D1);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266Client2")) {
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
  client.loop();
}
