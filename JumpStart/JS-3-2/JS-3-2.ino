/*
  js-3-2 - same as js-3-1 (just filter out the http msgs)
  
  Based on Web client from Examples by Tom Igoe
 */

#include <SPI.h>
#include <WiFiNINA.h>


char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password 

int status = WL_IDLE_STATUS;

// String IP_address;
WiFiClient client;

void setup() {
  
  Serial.begin(9600);
  
  while (status != WL_CONNECTED) {
    
    status = WiFi.begin(ssid, pass);
      // wait 5 seconds for connection:
    delay(5000);
  }
  
  printWifiStatus();

}

void loop() {

String IP_address;
String Details;
String temp="";

  IP_address = callmyAPI("api.ipify.org","/",0);
  Serial.print("External IP address: ");
  Serial.println(IP_address);

  // form the URI for the ipinfo Web Service
  
  temp = "/" + IP_address + "/geo";
  
  Details = callmyAPI("ipinfo.io",temp,0);
  Serial.println(Details);
  
  while(1) {   // just spin here forever
    
  }
  
}

String callmyAPI(char server[],String URI,int http) {

String line;

int done_http = 0;

line = "GET " + URI + " HTTP/1.1";
 
if (client.connect(server, 80)) {    
    // Send HTTP Info to server
    client.println(line);
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");      
    client.println();
  }


  line = "";

  while (!client.available()) {   // wait until stuff is returned
    
  }

  while (client.available()) {
    
    char c = client.read();  // read input a byte at a time
    line = line + c;         // slowly building a string 

    if (line.equals("\r\n")  ) {
      done_http = 1;      // if the line consists of just a /r/n
      continue;           // all the http is done, the rest is payload
    }
    
    if ( c == '\r' )      // we're at the end of a line
    {
      c = client.read();  // read (and throw away) the /n
      
      if (http == 1 ) {   // if we want to see http commands
        
         Serial.print(">>> ");
         Serial.println(line);
         
      }

      // if we're not done with the HTTP commands, wipe
      // out last line and grab another
      
      if (done_http == 0) {  
                               line = ""; 
                               }
       
    }
  }
  
 
  if (!client.connected()) {
                             client.stop();
                          }
return(line);  // so at the end, what's still in 'line'
               // is the payload - and return from this function
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
