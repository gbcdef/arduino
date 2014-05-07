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
