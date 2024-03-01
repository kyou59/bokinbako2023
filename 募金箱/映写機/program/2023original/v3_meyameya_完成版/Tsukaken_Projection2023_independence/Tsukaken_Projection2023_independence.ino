#include <VarSpeedServo.h>       // ライブラリのインクルード
#include <Adafruit_NeoPixel.h>
#define NUM_LEDS_99    99 //LEDの個数
#define SET_NUM 5

VarSpeedServo myservo;  
Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(100, 4, NEO_GRB + NEO_KHZ800);

//servoピン設定
#define Servo_Pin   7
boolean flag = false;
int count = 0;

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
  //Serial.println(value);
  stay1();
  
  for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
}

void off() {
  for(int i = 0; i < NUM_LEDS_99; i++) { //全消灯
      strip0.setPixelColor(i, strip0.Color(255, 0, 0));
    }
  strip0.show();
}

void Interrupt(){
  if(flag){
    count += 1;
    Serial.println(count);
    flag = false;
  
    if (count % SET_NUM == 0) {
      Serial.println("star");
      rainbow(2);
      servo();
      off();
    }
    else if (count % SET_NUM == 1) {
      Serial.println("set1");
      set1();
      servo();
      off();
    }
    else if (count % SET_NUM == 2) {
      Serial.println("set2");
      set2();
      servo();
      off();
    }
    else if (count % SET_NUM == 3) {
      Serial.println("set3");
      set3();
      servo();
      off();
    }
    else if (count % SET_NUM == 4) {
      Serial.println("set4");
      set4();
      servo();
      off();
    }
  }
  
}

void servo() {
    myservo.write(0, 10, true); 
    myservo.write(90, 10, true);
    myservo.write(180, 10, true);  // 速度10で180°まで動かし完了を待つ
    myservo.write(90, 10, true);
    myservo.write(0, 10, true);
}