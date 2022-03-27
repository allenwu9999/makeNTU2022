#include<Servo.h>
Servo myservo;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}

void loop() {
  myservo.write(0);
  delay(1500);
  myservo.write(70);
  delay(10000);
}
