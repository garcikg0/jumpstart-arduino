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
const char topic[]  = "jumpstart-temp";
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


send_marker("timmy",41.87,-87.62,61.3);
delay(1000);
send_marker("jane",45.67,-111.04,76.3);
delay(1000);
send_marker("lisa",30.27,-97.74,73.3);
delay(1000);
send_marker("bobby",28.54,-81.38,66.3);
delay(1000);
send_marker("dave",36.16,-86.77,77.7);


    
  
  mqttClient.poll();
  delay(30000);
  
}

void send_marker(String name, 
                 float latitude, 
                 float longitude,
                 float temp)  {
                 

String color = "#00F0FF";
int age = 10;

        mqttClient.beginMessage(topic);
        // {"name":"Sue", "lat":39.09, "lon":-94.58,"age":5,"temp":17.3,"iconColor":#00F0FF"}
        mqttClient.print("{  \"name\":");
        mqttClient.print("\"");                  
        mqttClient.print(name);
        mqttClient.print("\""); 
        mqttClient.print(" , ");

        mqttClient.print("\"lat\" : ");
        mqttClient.print(latitude);
        mqttClient.print(" , ");

        mqttClient.print("\"lon\" : ");
        mqttClient.print(longitude);
        mqttClient.print(" , ");

        mqttClient.print("\"age\" : ");
        mqttClient.print(age);
        mqttClient.print(" , ");

        mqttClient.print("\"temp\" : ");
        mqttClient.print(temp);
        mqttClient.print(" , ");

        mqttClient.print("\"iconColor\" : ");
        mqttClient.print("\""); 
        mqttClient.print(color);
        mqttClient.print("\""); 
        
        mqttClient.println( "}" );
         
        mqttClient.endMessage();
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
