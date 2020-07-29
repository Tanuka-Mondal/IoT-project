void setup()
{
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureK = temperatureC + 273;
  if(temperatureK >= 279 )
  {
    digitalWrite(5,HIGH);
  }
  else if(temperatureK < 277)
  {
    digitalWrite(5,LOW);
  }
}
