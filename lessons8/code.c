const int numReadings = 10;     //设置常量 

int readings[numReadings];      //模拟输入的读数
int readIndex = 0;              //当前读数的索引
int total = 0;                  //运行总计 
int average = 0;                //平均值

int inputPin = A0;

void setup()                    //初始化
{
  Serial.begin(9600);           //设置波特率 
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;  //将所有读数初始化为0
  }
}

void loop() {
  total = total - readings[readIndex];       //减去最后的读数
  readings[readIndex] = analogRead(inputPin);//从传感器读取
  total = total + readings[readIndex];       //将读数加到总计中
  readIndex = readIndex + 1;                 //前进到数组中的下一个位置
  if (readIndex >= numReadings)              //读数进行到数组末尾时 
  {
    readIndex = 0;                           //索引为0以便下一次循环 
  }
  average = total / numReadings;             //计算平均值 
  Serial.println(average);                   //将其作为ASCII数字发送到计算机
  delay(1);                                  //延迟 
}
