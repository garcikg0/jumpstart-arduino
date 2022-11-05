/* 
 *  js-2-5
 */

#include <DFRobot_DHT20.h>

DFRobot_DHT20 dht20;

void setup()
{
  Serial.begin(9600);
  delay(2000);
  
  //Initialize sensor
  while(dht20.begin()) 
  {
    Serial.println("Initialize sensor failed");
    delay(1000);
   }
}
void loop()
{
 Serial.print("Celsius:"); 
 Serial.print(dht20.getTemperature());
 Serial.print("C");
 Serial.print("  Fahrenheit:"); 
 Serial.print((dht20.getTemperature() * 1.8) + 32);
 Serial.print("F");
 Serial.print("  humidity:");  
 Serial.print(dht20.getHumidity()*100);
 Serial.println("%");
 
  delay(1000);
}
