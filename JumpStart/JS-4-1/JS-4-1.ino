/*
  JS-4-1 -  subscribe to an mqtt topic 
*/

#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>

char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password (use for WPA, or use as key for WEP)



WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "broker.hivemq.com";

const char topic[] = "JumpStartChat";
int        port    = 1883;


void setup() {
  //Initialize serial and wait for port to open:
  
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. 
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();


  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  

  Serial.print("Waiting for messages on topic: ");
  Serial.println(topic);
  Serial.println();
}

void loop() {
  
  // call poll() regularly to allow the library to receive MQTT messages and
  // send MQTT keep alives which avoids being disconnected by the broker

  mqttClient.poll();
  
}

void onMqttMessage(int messageSize) {

static char input[400];
int i=0;
char c;

  while (mqttClient.available()) {
    c = (char)mqttClient.read();
    if ( c != '\n' && i < messageSize )
        {
          input[i] = c;
          i++;
        }
        
  }
  input[i] = '\0';
  Serial.println(input);
  
}
