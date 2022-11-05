/*
 * js-2-7 - read photocell and temp sensor (used for plot)
 */

#include <DFRobot_DHT20.h>

int last = -1;

DFRobot_DHT20 dht20;

void setup(){

  Serial.begin(9600);
  
  while(dht20.begin()){
    Serial.println("Initialize sensor failed");
    delay(1000);
  }
  
}

void loop(){

  float temp_C,temp_F;
  int x,range;
  
  temp_C = dht20.getTemperature();
  temp_F = ( (9.0/5.0)*temp_C ) +32;

  x = analogRead(A1);
  range = map(x,0,183,50,59);
  
  Serial.print(temp_F);
  Serial.print(",");
  Serial.println(range); 
  
  delay(30000);

}
