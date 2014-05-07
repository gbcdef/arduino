void led_blink(int ledPin,int times)
{
  while(times>0)
  {
    analogWrite(ledPin,200);
    delay(100);
    analogWrite(ledPin,50);
    delay(100);
    times-=1;
  }

}

void led_increase(int steps)
{//the maximum luminance is 250
  lumix+=steps;
  if(lumix>255) lumix=250;
}

void led_decrease(int steps)
{//at least 50 luminance
  lumix-=steps;
  if(lumix<50) lumix=50;
}

void led_openbutton()
{//open and close led
  if(lumix>0) lumix=0;
  else if(lumix==0) lumix=100;
}

