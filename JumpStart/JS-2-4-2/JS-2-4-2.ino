int last=-1;
int delta_only = 0;

void setup() {
 
             Serial.begin(9600);
             delay(2000);
}

void loop() {
 
int x,range;

x = analogRead(A1);
delay(100);
range = map(x,0,263,1,10);

if (delta_only) {
                if (range != last) { 
                    Serial.println(range);
                    last = range;
                         } 
}
else {
       Serial.println(range);
}




}
