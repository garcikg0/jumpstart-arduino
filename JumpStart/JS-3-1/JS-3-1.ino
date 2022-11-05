/*
  js-3-1 Web client

 */


#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password 



int status = WL_IDLE_STATUS;

char server[] = "api.ipify.org";    // name address for Google (using DNS)
String IP_address;

WiFiClient client;

void setup() {
  
  Serial.begin(9600);
  
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 5 seconds for connection:
    delay(5000);
  }
  Serial.println("Connected to WiFi");
  printWifiStatus();

  
}

void loop() {

String IP_address;
String Details;
String temp;

  IP_address = callmyAPI("api.ipify.org","/",0);
  Serial.print("External IP address: ");
  Serial.println(IP_address);

  temp = "/" + IP_address + "/geo";
 
  Details = callmyAPI("ipinfo.io",temp,1);
  
  
  while(1) {
    
  }
  
}

String callmyAPI(char server[],String URI,int http) {

String line;

line = "GET " + URI + " HTTP/1.1";


if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println(line);
    client.print("Host: ");
    client.println(server);
    // client.println(line);
    client.println("Connection: close");
    client.println();
  }

  line = "";

  while (!client.available()) {
    
  }

  
  while (client.available()) {
    
    char c = client.read();
    line = line + c;
    // Serial.write(c);
    if ( line.equals("\n") ) {
      continue; 
    }
    if ( c == '\n' ) 
    {
      if (http == 1 ) {
         Serial.print(">>> ");
         Serial.print(line);
      }
     
      line = "";
    }
  }
  

  if (http == 1) { 
                  Serial.print(line);
                 }

 
  if (!client.connected()) {
                             client.stop();
                          }
return(line);

}





void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

 
}
