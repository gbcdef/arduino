int ledPin=3;
int lumix=128;
char cmd;
boolean onoff=false;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  if(Serial.available())
  {
    cmd=char(Serial.read());
    
    if(String(cmd)=="+" && onoff) lumix+=30;
    else if(String(cmd)=="-" && onoff) lumix-=30;
    else if(String(cmd)=="o") onoff=true;
    else if(String(cmd)=="c") {onoff=false;lumix=128;}
    else if(String(cmd)=="r") lumix=128;

    
    if(lumix<20 && onoff) lumix=20;
    else if(lumix>255 && onoff) lumix=255;
  
  
    Serial.println(cmd);
    Serial.println();
    
  }
  
  
  if(onoff) analogWrite(ledPin,lumix);
  else analogWrite(ledPin,0);
}
