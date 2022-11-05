/*
  JS-4-3 - set time delay of blinking LED via mqtt
*/

#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>

char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password (use for WPA, or use as key for WEP)
int time_delay = 200;


WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "broker.hivemq.com";


const char topic[]  = "jumpstart-xx";
int        port     = 1883;


void setup() {
  //Initialize serial and wait for port to open:
  
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  
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
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time_delay);  
  mqttClient.poll();
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(time_delay);                       // wait for a second
  
  
}

void onMqttMessage(int messageSize) {

static char input[15];
int i=0;
int value;
char c;

  // we received a message, print out the topic and contents
  Serial.print("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    c = (char)mqttClient.read();
    if ( c != '\n' && i < messageSize )
        {
          input[i] = c;
          i++;
        }
        
  }
  input[i] = '\0';

  value = atoi(input);
  Serial.println();
  Serial.println(value);
  time_delay=value;
}
