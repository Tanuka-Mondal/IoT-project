#include<Servo.h>

int servoPin = 6;

Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop()
{
   int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;
  
  int sensorValue = analogRead(A1);
  
  if(temperatureC > 60 || sensorValue > 200)
  {
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
  }
  
  if(temperatureC > 65 || sensorValue > 220)
  {
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    servo.write(180);
  }
  else
  {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    servo.write(0);
  }
}
