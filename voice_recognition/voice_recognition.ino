int ledPin=8;
byte com=0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x21); //import group 1
}

void loop()
{
  while(Serial.available())
  {
  com=Serial.read();
  switch(com)
  {
    case 0x11://blink
      fblink();
      break;
    case 0x12:
      flong();
      break;
    case 0x13:
      fclose();
      break;
    case 0x14:
      fblinkfast();
      break;
    case 0x15:
      fend();
      break;
  }
  }
}

void fblink()
{
  for(int i=0;i<4;i++)
  {
  delay(1000);
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  }
}
void flong()
{
  digitalWrite(ledPin,HIGH); 
}
void fclose()
{
    for(int i=0;i<4;i++)
  {
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  }
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
}
void fblinkfast()
{
  for(int i=0;i<10;i++)
  {
  delay(100);
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  }
}
void fend()
{
  
}
