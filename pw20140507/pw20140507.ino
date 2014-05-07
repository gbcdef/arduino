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
  initialize();
  
}

void loop(){
  while(Serial.available()){
    com=Serial.read();
    if(com==1){
      lumix=512;
    }else if(com==2){
      lumix=0;
    }
    
    
  }

}

void initialize()
{
  for(int i=0;i<3;i++)
  {
    digitalWrite(led[i],HIGH);
    delay(300);
  }
  for(int i=0;i<255;i+=4)
  {
      for(int j=0;j<3;j++)
    {
      analogWrite(led[j],i);
      
    }
    delay(50);
  }
  for(int i=0;i<3;i++)
  {
    digitalWrite(led[i],LOW);
    delay(300);
  }
}
