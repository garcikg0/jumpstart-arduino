/*
 * js-2-6
 */

#include <DFRobot_DHT20.h>

DFRobot_DHT20 dht20;

void setup(){

  Serial.begin(9600);
  delay(2000);
  
  while(dht20.begin()){
    Serial.println("Initialize sensor failed");
    delay(1000);
  }
  
}

void loop(){

  float temp_C,temp_F;

  temp_C = dht20.getTemperature();
  temp_F = ( (9.0/5.0)*temp_C ) +32;
  Serial.println(temp_F); 
  
  delay(3000);

}
