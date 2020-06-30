const int numReadings = 10;     //���ó��� 

int readings[numReadings];      //ģ������Ķ���
int readIndex = 0;              //��ǰ����������
int total = 0;                  //�����ܼ� 
int average = 0;                //ƽ��ֵ

int inputPin = A0;

void setup()                    //��ʼ��
{
  Serial.begin(9600);           //���ò����� 
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;  //�����ж�����ʼ��Ϊ0
  }
}

void loop() {
  total = total - readings[readIndex];       //��ȥ���Ķ���
  readings[readIndex] = analogRead(inputPin);//�Ӵ�������ȡ
  total = total + readings[readIndex];       //�������ӵ��ܼ���
  readIndex = readIndex + 1;                 //ǰ���������е���һ��λ��
  if (readIndex >= numReadings)              //�������е�����ĩβʱ 
  {
    readIndex = 0;                           //����Ϊ0�Ա���һ��ѭ�� 
  }
  average = total / numReadings;             //����ƽ��ֵ 
  Serial.println(average);                   //������ΪASCII���ַ��͵������
  delay(1);                                  //�ӳ� 
}
