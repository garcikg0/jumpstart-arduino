/*

JS-3-5 - temperature gague 

 */

#include <SPI.h>
#include <WiFiNINA.h>
#include <DFRobot_DHT20.h>

DFRobot_DHT20 dht20;

char ssid[] = "Fios-x2QXN";        // your network SSID (name)
char pass[] = "too675tax58toil";    // your network password 

WiFiServer server(80);
WiFiClient client;

String URI;

void setup() {

int status = WL_IDLE_STATUS;

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. 
  }

  while(dht20.begin()) 
  {
    Serial.println("Initialize sensor failed");
    delay(1000);
   }


  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(5000);
  }
  
  
  server.begin(); // start webserver (port 80)
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  client = server.available();
  if (client) {
    
    got_a_request(1);  // 0=means do not show HTTP, 1=show
    send_a_response();
    
    }

}

void printWifiStatus() {
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

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


client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");  // the connection will be closed after completion of the response
client.println();


if (URI.equals("/")) 
{
    send_status_page();     
              
}


client.stop();  
}



void send_status_page() {

  client.println("<!DOCTYPE HTML>"); 
  client.println("<html><head>");
  client.println("<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>");
  client.println("<script type=\"text/javascript\">");
  client.println("google.charts.load('current', {'packages':['gauge']});");
  client.println("google.charts.setOnLoadCallback(drawChart);");
  client.println("function drawChart() {");
  client.println("var data = google.visualization.arrayToDataTable([");
  client.println("['Label', 'Value'], ['Temp', 80],]);");
  client.println("var options = {width: 800, height: 240,redFrom: 85, redTo: 100,yellowFrom:75, yellowTo:85,");
  client.println("minorTicks: 5 };");
  client.println("var chart = new google.visualization.Gauge(document.getElementById('chart_div'));");
  client.print("data.setValue(0,1,");
//  client.print(dht20.getTemperature());
  client.print((dht20.getTemperature() * 1.8) + 32);

  client.println(");chart.draw(data, options); }");
  client.println("</script> </head><body>");
  client.println("<div id=\"chart_div\" style=\"width: 400px; height: 120px;\"></div></body></html>");
  client.println();
  
   delay(10);


}
