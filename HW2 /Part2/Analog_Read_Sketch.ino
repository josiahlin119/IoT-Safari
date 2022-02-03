#include<Wire.h>
int analogPin = A3;
int val = 0;
#define BUFLEN 8192
unsigned long buf[BUFLEN];
unsigned int msg[30];
unsigned long start_time, duration;

void setup() {
  Serial.begin(9600);
}
bool beenThereDoneThat = false;

void loop()
{
   if(!beenThereDoneThat)
   {
       analogDuration();
       
       for(int c = 0; c < 30; c++){
       
        Serial.println(msg[c]);

       }
       beenThereDoneThat = true;
   }
   
}

void analogDuration()
{
  for(int c = 0; c < 30; c++){
    start_time = micros();
    for(int i = 0; i <BUFLEN; i++){
      buf[i] = analogRead(analogPin);
  }
  duration = micros() - start_time;
  msg[c] = duration;
  delay(500);
}
}
 
