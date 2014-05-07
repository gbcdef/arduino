void setLed(int pin,int lumix)
{
  analogWrite(pin,lumix);
}

void resetLed(int pin)
{
  analogWrite(pin,128);
}

void blinkLed(int pin,int f,int number)
{
  if(f<1) f=200;
  for(int i=0;i<number;i++)
  {
    
    digitalWrite(pin,HIGH);
    delay(1);
    digitalWrite(pin,LOW);
    delay(f-1);
  }
}
