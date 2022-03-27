#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

// light 

#include "HX711.h"
#include <SoftwareSerial.h>
#define LIGHT 13
SoftwareSerial NXP(9, 10);

int NXP_index_0 = 0;
int NXP_index_1 = 0;
int light_state = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4); 
  lcd.setCursor(3,0);
  lcd.print("Hello YouTube!");
  lcd.setCursor(8,1);
  lcd.print("****");
  lcd.setCursor(0,2);
  lcd.print("This is a demo text");
  lcd.setCursor(8,3);
  lcd.print("****");

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

  // light 
  pinMode(LIGHT, OUTPUT);
  NXP.begin(115200);
  Serial.begin(9600); 
}

String setMiddle(String s) {
  int l = s.length();
  String st;
  for (int i = 0; i < (20 - l)/2; i++) {
    st += ' ';
  }
  st += s;
  if (l % 2 == 0) {
    for (int i = 0; i < (20 - l)/2; i++) {
      st += ' ';
    }
  }
  else {
    for (int i = 0; i < (20 - l)/2 + 1; i++) {
      st += ' ';
    }
  }
  return st;
}

void show(String a="", String b="", String c="", String d="") {
  lcd.setCursor(0,0);
  lcd.print(setMiddle(a));
  lcd.setCursor(0,1);
  lcd.print(setMiddle(b));
  lcd.setCursor(0,2);
  lcd.print(setMiddle(c));
  lcd.setCursor(0,3);
  lcd.print(setMiddle(d));
}
bool ordered = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (!light_state){
    if (!ordered) {
      bool step[3] = {false};
      while(!step[0]) {
        show("---Soup---", "please choose:", "1.tomato  2.seafood", "3.mushroom  4.corn");
        int status = -1;
        if (digitalRead(2)) status = 1;
        else if (digitalRead(3)) status = 2;
        else if (digitalRead(4)) status = 3;
        else if (digitalRead(5)) status = 4;
        if (status > 0) {
          String select_string = "You choose " + String(status);
          show(select_string);
          step[0] = true;
          delay(2000);
        }
      }
      while (!step[1]) {
        show("---Main Dish---", "please choose:", "1.steak  2.fish", "3.pork  4.chicken");
        int status = -1;
        if (digitalRead(2)) status = 1;
        else if (digitalRead(3)) status = 2;
        else if (digitalRead(4)) status = 3;
        else if (digitalRead(5)) status = 4;
        if (status > 0) {
          String select_string = "You choose " + String(status);
          show(select_string);
          step[1] = true;
          delay(2000);
        }
      }
      while (!step[2]) {
        show("---Dessert---", "please choose:", "1.cake 2.ice cream", "3.brownie  4.pancake");
        int status = -1;
        if (digitalRead(2)) status = 1;
        else if (digitalRead(3)) status = 2;
        else if (digitalRead(4)) status = 3;
        else if (digitalRead(5)) status = 4;
        if (status > 0) {
          String select_string = "You choose " + String(status);
          show(select_string);
          step[2] = true;
          delay(2000);
        }
      }
      ordered = true;
    }
    show("Order Succeed!", "Thank you!", "1.Service 2.Check", "3.Return 4.Exit");
    int status = -1;
    if (digitalRead(2)) status = 1;
    else if (digitalRead(3)) status = 2;
    else if (digitalRead(4)) status = 3;
    else if (digitalRead(5)) status = 4;
    if (status == 3){
      ordered = false;
      delay(2000);
    }
    else if (status == 1 || status == 2) {
      show("On your service", "please wait");
      delay(20000);
      light_state = 1;
    }

  }
  else{
    // light 
    if(NXP.available()){
      char content = NXP.read();
      Serial.println(content);
      if(content == '0'){
        NXP_index_0++;
        NXP_index_1 = 0;
        if(NXP_index_0 >= 5){
          // Turn on the light
          digitalWrite(LIGHT, HIGH);
        }
      }
      else{
        NXP_index_0 = 0;  
        NXP_index_1++;
        if(NXP_index_1 >= 10){
          // Turn off the light
          digitalWrite(LIGHT, LOW);
        }
      }
    }
  }
}
