#include <LiquidCrystal.h>

const int trigPin = 8;
const int echoPin = 9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const long maxDistance = 200; // max dopuszczalny dystans (200cm)
long minimum = 201, maximum = -1;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration / 2 / 29.1;

  if(distance > maximum)
    maximum = distance;

  if(distance<minimum)
    minimum = distance;

  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("Min: ");
  lcd.print(minimum);
  lcd.print("  ");
  lcd.print("Max: ");
  lcd.print(maximum);
  
  lcd.setCursor(0, 0);

  if (distance >= maxDistance || distance == 0)
    lcd.print("OoR");

  else
  {
    lcd.print("Dystans: ");
    lcd.print(distance);
    lcd.print("cm");
    
  }

  delay(1000);
}
