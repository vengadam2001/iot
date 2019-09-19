/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
#include<Servo.h>
// defines pins numbers
const int trigPin = 5;
const int echoPin = 6;
const int pir=4;
Servo myservo;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(pir,INPUT);
myservo.attach(9);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
label:
  Serial.print(digitalRead(pir));
  Serial.print(" -> ");
  if(digitalRead(pir)==1)
  {
    Serial.print("i am working");
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
//myservo.write(map(distance,0,2500,0,90));
// Calculating the distance
distance= duration*0.034/2;
//else if(distance > 50 && distance < 100)
//{
// digitalWrite(9,LOW);
//  digitalWrite(8,LOW);
//  digitalWrite(7,HIGH);
//}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance<100)
{
  myservo.write(110);
  delay(10000);
  goto label;
}

  }
 else
 {
  Serial.println("i am sleeping");
 }
 
}
