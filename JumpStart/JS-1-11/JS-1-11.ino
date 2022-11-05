/*

JS-1-11 - fill/empty/fill
  
*/

void setup() {
  // initialize digital pins as output.
  
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
delay(2000);
}

// the loop function runs over and over again forever
void loop() {


#define WAITTIME 200

  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  delay(WAITTIME);
;
;
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(WAITTIME);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(WAITTIME)
 ;
 ;
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(WAITTIME);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(WAITTIME);
  
 ;
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  delay(WAITTIME);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(WAITTIME);

  

  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(WAITTIME);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(WAITTIME);
;
;
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(WAITTIME);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(WAITTIME);
;
;
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(WAITTIME);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);               
                
}
