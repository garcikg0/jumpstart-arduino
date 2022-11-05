/*
  JS-3-4 WiFi Web Server - by Tom Igoe

 */

#include <SPI.h>
#include <WiFiNINA.h>


char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password 


WiFiServer server(80);
WiFiClient client;

String URI;

void setup() {

int status = WL_IDLE_STATUS;

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(5000);
  }
  
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
  server.begin(); // start webserver (port 80)
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  client = server.available();
  if (client) {
    
    // an HTTP request ends with a blank line
    
    got_a_request(1);  // 0=means do not show HTTP, 1=show
    send_a_response();
    
    }

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

String got_a_request(int http) {

 String line = "";
 int done_http = 0;
 int pos0,pos1;

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

      if (line.startsWith("GET") == 1) {
               
               pos0 = line.indexOf(" ");
               pos0++;
               pos1 = line.indexOf(" ",pos0);
               URI = line.substring(pos0,pos1);
         }
      
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
return(URI);  // so at the end, what's still in 'line'
               // is the payload - and return from
}


void send_a_response() {
int status_of_LED;

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");  // the connection will be closed after completion of the response
client.println();


if (URI.equals("/")) 
{
    send_status_page();     
              
}

if (URI.equals("/on")) { 
  digitalWrite(8,HIGH);
  send_on_page();
}

if (URI.equals("/off")) {  
  digitalWrite(8,LOW);
  send_off_page();
}

client.stop();  
}

void send_on_page() {
  client.println("<!DOCTYPE HTML>");
  client.print("<html><body>");
  client.print("<center><h2>Turned the LED: ON</h2></center>");
  client.print("<center><img src=\"https://www.pngmart.com/files/10/Thumbs-UP-PNG-File.png\" width=\"500\" height=\"600\" >");
  client.print("</center></body></html>");
  client.println();
  delay(10);
}

void send_off_page() {
  client.println("<!DOCTYPE HTML>");
  client.print("<html><body>");
  client.print("<center><h2>Turned the LED: OFF</h2></center>");
  client.print("<center><img src=\"https://www.pngmart.com/files/10/Thumbs-Down-Transparent-Background.png\" width=\"500\" height=\"600\" >");
  client.print("</center></body></html>");
  client.println();
   delay(10);
}

void send_status_page() {

int status_of_LED;
String status_text;
String image;

  client.println("<!DOCTYPE HTML>");

  status_of_LED = digitalRead(8);
          
         if (status_of_LED == 0) {
                   status_text = "OFF";   
                   image = "https://www.pngmart.com/files/10/Thumbs-Down-Transparent-Background.png";
               }
         else {
              status_text = "ON";
              image = "https://www.pngmart.com/files/10/Thumbs-UP-PNG-File.png";
              
            }

  client.println("<html>");
  client.println("<h1 \"font-size:60px\">");
  client.println("<center>LED is: ");
  client.println(status_text);
  client.println("</center></h1>");
  client.print("<center><img src=\" ");
  client.print(image);
  client.print("\" width=\"500\" height=\"600\" >");
  client.print("</center></body></html>");
  client.println();
   delay(10);


}
