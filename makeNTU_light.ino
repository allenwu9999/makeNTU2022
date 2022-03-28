
#include "HX711.h"
#include <SoftwareSerial.h>
#define LIGHT 13
SoftwareSerial NXP(9, 10);

int NXP_index_0 = 0;
int NXP_index_1 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT, OUTPUT);
  NXP.begin(115200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  
