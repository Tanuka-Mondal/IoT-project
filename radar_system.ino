

#include <Servo.h>
#include <LiquidCrystal.h>



Servo robotNeck; //servo variable with name robotNeck

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object with parameters: (rs, enable, d4, d5, d6, d7)


const int sigPin = 13;

int distanceCm, distanceIn;
long timeVal;
const int speedOfSound = 0.0343; //sets the speed of sound to a constant value

int distCalc(){
  pinMode(sigPin, OUTPUT);
  
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(sigPin, INPUT);
  timeVal = pulseIn(sigPin, HIGH);
  
  //converts time to distance
  distanceCm = timeVal / 29 / 2;
  distanceIn = timeVal / 74 / 2;
  
  return distanceCm, distanceIn;
}

void setup() {
  robotNeck.attach(3); //Servo is connected to arduino pin ~3
  
 
  
  lcd.begin(16, 2); //Initializes the lcd and specifies the dimension (width and height, respectively) of the display
  
  lcd.setCursor(3,0);
  lcd.print("Welcome to");
  delay(1000);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("TANUKA'S");
  lcd.setCursor(1,1);
  lcd.print("Distance Meter");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Booting.");
  delay(500);
  lcd.clear();
  lcd.print("Booting..");
  delay(1000);
  lcd.clear();
  lcd.print("Booting...");
  delay(1500);
  lcd.clear();

}

void loop() {
  //Rotate robotNeck from 15` to 165` because of limits which might draw too much current
  for(int j=15; j<=165; j++){
    
    if(distanceCm <=25){
    robotNeck.write(0);
  }
  else if(distanceCm <= 50){
    robotNeck.write(30);
  }
    else if(distanceCm <= 100){
    robotNeck.write(50);
  }
  else if(distanceCm <= 150){
    robotNeck.write(70);
  }
  else if(distanceCm <= 170){
    robotNeck.write(100);
  }
  else if(distanceCm <= 200){
    robotNeck.write(130);
  }
  else if(distanceCm <= 250){
    robotNeck.write(150);
  }
  else if(distanceCm > 250){
    robotNeck.write(180);
  }
  delay(100);
    
    distanceCm = distCalc();
    distanceIn = distCalc();
    
    //To display value on the lcd
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance: " on the LCD
    lcd.print(distanceCm); // Prints the distance value from the sensor
    lcd.print("cm"); // Prints the unit of measurement
    delay(10); //waits for 10 milliseconds
    
    lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance: " on the LCD
    lcd.print(distanceIn); // Prints the distance value from the sensor
    lcd.print("in"); // Prints the unit of measurement
    delay(100); //waits for 100 milliseconds
  }  
  
  for(int j=165; j>=15; j--){
  
    
    distanceCm = distCalc();
    distanceIn = distCalc();
    

    
    //To display value on the lcd
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance: " on the LCD
    lcd.print(distanceCm); // Prints the distance value from the sensor
    lcd.print("cm"); // Prints the unit of measurement
    delay(100); //waits for 100 milliseconds
    
    lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance: " on the LCD
    lcd.print(distanceIn); // Prints the distance value from the sensor
    lcd.print("in"); // Prints the unit of measurement
    delay(100); //waits for 100 milliseconds
  }  }
