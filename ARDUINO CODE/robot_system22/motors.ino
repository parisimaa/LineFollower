void Go(int Speed,boolean Dir){
  if (Dir==HIGH)
  {
  analogWrite(M1R,Speed);
  analogWrite(M2R,0);

  analogWrite(M1L,Speed);
  analogWrite(M2L,0);
  }
  else
  {
  analogWrite(M1R,0);
  analogWrite(M2R,Speed);

  analogWrite(M1L,0);
  analogWrite(M2L,Speed);    
  }
  digitalWrite(ENR,HIGH);
 digitalWrite(ENL,HIGH);
}

///////////////////////////////////
void StopMotors(){


  analogWrite(M1R,0);
  analogWrite(M2R,0);

  analogWrite(M1L,0);
  analogWrite(M2L,0);

  digitalWrite(ENR,LOW);
  digitalWrite(ENL,LOW);
}
void Go_RIGHT(int Speed)
{
  if (Speed>=0)
  {
  analogWrite(M1R,Speed);
  analogWrite(M2R,0);
  }
  else
  {
  analogWrite(M1R,0);
  analogWrite(M2R,abs(Speed));  
  }  
  digitalWrite(ENR,HIGH);
}
////////////////////////////////////
void Go_LEFT(int Speed)
{
  if (Speed>=0)
  {
  analogWrite(M1L,Speed);
  analogWrite(M2L,0);
  }
  else
  {
  analogWrite(M1L,0);
  analogWrite(M2L,abs(Speed));  
  }
  digitalWrite(ENL,HIGH);
}
////////////////////////////////////
void Stop_RIGHT()
{
  analogWrite(M1R,0);
  analogWrite(M2R,0);
  digitalWrite(ENR,LOW);
}
////////////////////////////////////
void Stop_LEFT()
{
  analogWrite(M1L,0);
  analogWrite(M2L,0);
  digitalWrite(ENL,LOW);
}
///////////////////////////////////
