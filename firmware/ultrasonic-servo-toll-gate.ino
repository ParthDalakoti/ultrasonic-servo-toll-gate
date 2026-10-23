#include <Servo.h> 
 
Servo myservo;  // Create servo object 
 
const int trigPin = 11; 
const int echoPin = 10; 
const int redLed = 2; 
const int yellowLed = 3; 
const int servoPin = 9; 
 
const int thresholdDistance = 20;  // Distance in cm to detect car (change if needed) 
 
void setup() { 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(redLed, OUTPUT); 
  pinMode(yellowLed, OUTPUT); 
   
  myservo.attach(servoPin); 
  myservo.write(90);  // Initial position: gate closed 
   
  digitalWrite(redLed, LOW); 
  digitalWrite(yellowLed, HIGH);  // Yellow on when gate closed 
} 
 
void loop() { 
  long duration; 
  int distance; 
   
  // Trigger ultrasonic sensor 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
   
  // Read echo 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2;  // Distance in cm 
   
  if (distance < thresholdDistance && distance > 0) {  // Car detected 
    digitalWrite(yellowLed, LOW);   // Yellow off 
    digitalWrite(redLed, HIGH);     // Red on (gate opening/open) 
    myservo.write(0);               // Open gate to 0 degree 
    delay(5000);                    // Gate khula 4 second tak 

    myservo.write(90);              // Close gate back to 90 
    digitalWrite(redLed, LOW);      // Red off 
    digitalWrite(yellowLed, HIGH);  // Yellow on again 
     
    delay(1000);  // Thoda wait taaki turant dobara trigger na ho 
  } 
   
  delay(100);  // Loop stable rakhne ke liye chhota delay 
}