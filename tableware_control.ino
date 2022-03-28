#include <Servo.h>

Servo myservo_R;  // 建立一個 servo 物件，最多可建立 12個 servo
Servo myservo_L;  // 建立一個 servo 物件，最多可建立 12個 servo
Servo myservo_M;

int R_pos = 90;    // 設定 Servo 位置的變數
int L_pos = 0;
int M_pos = 0;

int leftout = 0;
int midout = 0;
int rightout = 0;

//#define VDD 53

void setup() {
  Serial.begin(9600);
  myservo_R.attach(9);  // 將 servo 物件連接到 pin 9
  myservo_L.attach(8);
  myservo_M.attach(7);
  
  myservo_R.write(R_pos);
  myservo_L.write(L_pos);
  myservo_M.write(M_pos);
  delay(5000); 
}

void loop() {
  int big = digitalRead(30);
  int middle = digitalRead(28);
  int small = digitalRead(26);
  go(big, middle, small);
  delay(2000);
}

void  go(int big, int middle, int small){
  if (big + middle + small != 1){
    return;
  }
  Serial.print("big");
  Serial.println(big);
  Serial.print("mid");
  Serial.println(middle);
  Serial.print("small");
  Serial.println(small);
  if (middle == 1){
    if (leftout < 1k){
      left_up();
      delay(1000);
      left_down();
      leftout ++;
    }
  }
  else if (big == 1){
    if (midout < 1){
      mid_up();
      Serial.println("9999999");
      delay(1000);
      mid_down();
      midout ++;
    }
  }
  else if (small == 1){
    if (rightout < 1){
      right_up();
      delay(1000);
      right_down();
      rightout ++;
    }
  }
}

void left_up(){
  // 正轉 180度，從 0 度旋轉到 180 度，每次 1 度
    for (L_pos = 0; L_pos <= 150; L_pos += 1)
    {
      myservo_L.write(L_pos);    // 告訴 servo 走到 'pos' 的位置
      delay(15);        // 等待 15ms 讓 servo 走到指定位置
    }
}

void right_up(){
  // 反轉 180度，從 180 度旋轉到 0 度，每次 1 度
  for (R_pos = 90; R_pos >= 0; R_pos -= 1)
  {
    myservo_R.write(R_pos);   // 告訴 servo 走到 'pos' 的位置
    delay(15);   // 等待 15ms 讓 servo 走到指定位置
  }
}

void left_down(){
  // 正轉 180度，從 0 度旋轉到 180 度，每次 1 度
    for (L_pos = 150; L_pos >= 0; L_pos -= 1)
    {
      myservo_L.write(L_pos);    // 告訴 servo 走到 'pos' 的位置
      delay(15);        // 等待 15ms 讓 servo 走到指定位置
    }
}

void right_down(){
  // 反轉 180度，從 180 度旋轉到 0 度，每次 1 度
  for (R_pos = 0; R_pos <= 90; R_pos += 1)
  {
    myservo_R.write(R_pos);   // 告訴 servo 走到 'pos' 的位置
    delay(15);   // 等待 15ms 讓 servo 走到指定位置
  }
}

void mid_up(){
  // 正轉 180度，從 0 度旋轉到 180 度，每次 1 度
  for (M_pos = 0; M_pos <= 180; M_pos += 1)
  {
    myservo_M.write(M_pos);    // 告訴 servo 走到 'pos' 的位置
    delay(15);        // 等待 15ms 讓 servo 走到指定位置
  }
}

void mid_down(){
  // 反轉 180度，從 180 度旋轉到 0 度，每次 1 度
  for (M_pos = 180; M_pos >= 0; M_pos -= 1)
  {
    myservo_M.write(M_pos);    // 告訴 servo 走到 'pos' 的位置
    delay(15);        // 等待 15ms 讓 servo 走到指定位置
  }
}
