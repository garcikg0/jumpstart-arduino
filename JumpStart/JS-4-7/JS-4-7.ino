/*
  JS-4-2  
*/

#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>


char ssid[] = "SRR55";        // your network SSID (name)
char pass[] = "HDGXF32YCDVLH8YZ";    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "broker.hivemq.com";
const char topic[]  = "jumpstart";
const char id[] = "01";

int        port     = 1883;


void setup() {
  //Initialize serial and wait for port to open:
  
  
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

// String message;

int x,range;


  
  

        // message = Serial.readString();
        mqttClient.beginMessage(topic);
        mqttClient.print(id);
        mqttClient.print(",");
        
        x = analogRead(A1);
        range = map(x,0,282,1,10);
        
        mqttClient.print(range);
        mqttClient.endMessage();
  
  mqttClient.poll();
  delay(2000);
  
}

void onMqttMessage(int messageSize) {

static char input[400];
int i=0;
int value;
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
