// count A&B from encoder using interupt rising
void CunterR()
{
  if(digitalRead(BR)==LOW)
  {
  cuntR++;
  }
  else
  {
   cuntR--; 
  }
}
///////////////////////////////
void CunterL()
{
  if(digitalRead(BL)==LOW)
  {
  cuntL++;
  }
  else
  {
   cuntL--; 
  }
}
