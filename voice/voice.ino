/*
01,kai deng,001
02,guan deng,002
03,bian liang,003
04,liang yi dian,003
05,bian an,004
06,an yi dian,004
*/

int led[3]={3,5,6};
int r=9,g=10,b=11;
int lumix=0;
int com;

void setup(){
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  {
    pinMode(led[i],OUTPUT);
  }
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(13,OUTPUT);
  initialize();
  
}

void loop(){
  while(Serial.available())
  {
    com=Serial.read();
    if(com==1){
      lumix=128;
    }
    else if(com==2)
    {
      lumix=0;
    }
    else if(com==3)
    {
      blinkLed(13,50,3);
      lumix+=100;
      if(lumix>=255) 
      {//when the lumix meet the maxium value,constrain it and blink the led
        lumix=255;
        for(int i=0;i<3;i++)
        {
          blinkLed(led[i],100,4);
        }
      }
    }
    else if(com==4)
    {
      blinkLed(13,50,3);
      lumix-=100;
      if(lumix<=0) 
      {//when the lumix meet the minimum valuse,constrain it and blink the led
        lumix=0;
        for(int i=0;i<3;i++)
        {
          blinkLed(led[i],100,4);
        }
      }
      
    }
    Serial.println(lumix);
    for(int i=0;i<3;i++)
    {
       setLed(led[i],lumix); 
    }
    
  }

}


