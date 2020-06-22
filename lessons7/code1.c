#include <MsTimer2.h>     
 
int tick = 0;
int pinInterrupt=2;
int state=0;
void onTimer()
{
  Serial.println(tick++);
  state=~state;
}
 
void setup()
{
  Serial.begin(9600); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  MsTimer2::set(1000, onTimer);
  MsTimer2::start();
  
}

byte income=0;
void loop()
{
    income=tick%10-'0';
    digitalWrite(3,income&0x1);
    digitalWrite(4,(income>>1)&0x1);
    digitalWrite(5,(income>>2)&0x1);
    digitalWrite(6,(income>>3)&0x1);
  	delay(10);
}
