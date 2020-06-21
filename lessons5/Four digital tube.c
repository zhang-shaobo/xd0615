void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
}
byte income1=0;
byte income2=0;
byte income3=0;
byte income4=0;
void loop()
{
  if(Serial.available()>0)
  {
    delay(10);
    income1=Serial.read();
    income2=Serial.read();
    income3=Serial.read();
    income4=Serial.read();
    
    income1=income1-'0';
    income2=income2-'0';
    income3=income3-'0';
    income4=income4-'0';
    
    digitalWrite(8,LOW);
    digitalWrite(2,income1&0x1);
    digitalWrite(3,(income1>>1)&0x1);
    digitalWrite(4,(income1>>2)&0x1);
    digitalWrite(5,(income1>>3)&0x1);
    digitalWrite(8,HIGH);
    delay(10);
    
    digitalWrite(9,LOW);
    digitalWrite(2,income2&0x1);
    digitalWrite(3,(income2>>1)&0x1);
    digitalWrite(4,(income2>>2)&0x1);
    digitalWrite(5,(income2>>3)&0x1);
    digitalWrite(9,HIGH);
    delay(10);
    
    digitalWrite(10,LOW);
    digitalWrite(2,income3&0x1);
    digitalWrite(3,(income3>>1)&0x1);
    digitalWrite(4,(income3>>2)&0x1);
    digitalWrite(5,(income3>>3)&0x1);
    digitalWrite(10,HIGH);
    delay(10);
    
    digitalWrite(11,LOW);
    digitalWrite(2,income4&0x1);
    digitalWrite(3,(income4>>1)&0x1);
    digitalWrite(4,(income4>>2)&0x1);
    digitalWrite(5,(income4>>3)&0x1);
    digitalWrite(11,HIGH);
    delay(10);
  }
}