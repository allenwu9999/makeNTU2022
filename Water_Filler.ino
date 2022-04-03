/*
  本範例為HX711簡單示範，會把重量顯示在監控視窗中
  
  需先安裝Bogdan Necula的HX711函式庫
  https://github.com/bogde/HX711
  
  傑森創工製作
  
  粉絲團：
  https://www.facebook.com/jasonshow
  
  傑森創工部落格：
  https://blog.jmaker.com.tw/

  傑森創工賣場：https://goo.gl/EWoPQ4

 */
 // 空杯483 滿杯609
 // full321 none233
#include "HX711.h"
#include <Servo.h>

Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo
Servo myservo2;
int pos = 0;    // 設定 Servo 位置的變數
// 接線設定
const int DT_PIN = 6;
const int SCK_PIN = 5;

const int scale_factor = -239; //比例參數，從校正程式中取得

HX711 scale;
int ctrl = -1;
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing the scale");
  myservo.attach(9);  // 將 servo 物件連接到 pin 9
  myservo2.attach(10);
  myservo2.write(0);
  scale.begin(DT_PIN, SCK_PIN);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale.get_units(5), 0);  //未設定比例參數前的數值

  scale.set_scale(scale_factor);       // 設定比例參數
  scale.tare();               // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
}

void loop() {
  int val = scale.get_units(10);
  Serial.println(val);
  if(val < 250 && val> 220){
    ctrl = 1;//去裝水
    myservo.write(315);
    delay(5800);
    myservo.write(90);
    delay(3000);
    myservo2.write(0);
    delay(1500);
    while(val < 325){
      val = scale.get_units(10);
      myservo2.write(70);
    }
    myservo2.write(0);
    myservo.write(45);
    delay(5700);
    myservo.write(90);
  }
  
//  scale.power_down();             // 進入睡眠模式
//  delay(1000);
//  scale.power_up();               // 結束睡眠模式
}
