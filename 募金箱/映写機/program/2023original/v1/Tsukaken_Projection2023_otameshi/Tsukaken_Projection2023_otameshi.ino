#include <VarSpeedServo.h>       // ライブラリのインクルード
#include <Adafruit_NeoPixel.h>

VarSpeedServo myservo;  
Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(100, 4, NEO_GRB + NEO_KHZ800);

//servoピン設定
#define Servo_Pin   7
boolean flag = false;

void setup() {
  // put your setup code here, to run once:
  strip0.begin();
  strip0.show();
  
  myservo.attach(Servo_Pin);     // サーボ接続ピンをD7に
  
  attachInterrupt(0, Interrupt, FALLING); // 認識部がさえぎられた時にInterrupt関数に飛ぶ
  attachInterrupt(1, Interrupt, FALLING); // スイッチが押された時にInterrupt関数に飛ぶ
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
  int value = digitalRead(2);
  // 認識部がさえぎられると1になる
  Serial.println(value);

  if(flag == true){
    rainbow(2);
    myservo.write(0, 10, true); 
    myservo.write(90, 10, true);
    myservo.write(180, 10, true);  // 速度10で180°まで動かし完了を待つ
    myservo.write(90, 10, true);
    myservo.write(0, 10, true);
    flag = false;
  }
  delay(100);
}

void Interrupt(){
  Serial.println("star");
  flag = true;
}
