// Bokinbako2023のコード
#include <Adafruit_NeoPixel.h>

#define WAITING 0
#define GET_MONEY 1

#define GROUP_SPACING 1
#define SEGMENT_SIZE 1
#define NUM_LEDS_GROUP 1

// LEDテープの設定
#define LED_PIN4    4
#define LED_PIN5    5
#define LED_PIN6    6
#define LED_PIN7    7
#define LED_PIN8    8
#define NUM_LEDS_100    100
#define NUM_LEDS    100

// LEDテープのオブジェクトを作成(幹)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS_100, LED_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS_100, LED_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS_100, LED_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUM_LEDS_100, LED_PIN7, NEO_GRB + NEO_KHZ800);
//(枝のLED)
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUM_LEDS_100, LED_PIN8, NEO_GRB + NEO_KHZ800);

int state = WAITING;
int sub_state = 0;

void setup() {

  attachInterrupt(0, Interrupt, FALLING); // 認識部がさえぎられた時にInterrupt関数に飛ぶ
  attachInterrupt(1, Interrupt, FALLING); // スイッチが押された時にInterrupt関数に飛ぶ
  
  // 初期化
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
  strip4.begin();
  strip4.show();
  strip5.begin();
  strip5.show();
  Serial.begin(9600);
}

void loop() {
  switch(state){
    // コインを認識するごとに待機時の点灯パターンが変わる
    case WAITING:
    
      if(sub_state == 0){
        Serial.println("wait1");
        money2_loop();
        break;
      }else if(sub_state == 1){
        Serial.println("wait2");
        money2_loop();
        break;
      }else if(sub_state == 2){
        Serial.println("get1");
        money2_loop();
        break;
      }else if(sub_state == 3){
        Serial.println("get2");
        money2_loop();
        break;
      }else if(sub_state == 4){
        Serial.println("get3");
        money2_loop();
        break;
      }else{
        Serial.println("wait1");
        money2_loop();
        break;
      }
    case GET_MONEY:
      if(sub_state == 0){
        Serial.println("sr");
        for(int i = 0; i < 2; i++){
          money5_loop();
        }
        ResetState();
        break;
      }else if(sub_state == 1){
        Serial.println("shige");
          money1_loop();
        ResetState();
        break;
      }else if(sub_state == 2){
        Serial.println("gradation");
          money3_loop();
        ResetState();
        break;
      }else if(sub_state == 3){
        Serial.println("wave");
          money4_loop();
        ResetState();
        break;
      }else if(sub_state == 4){
        Serial.println("sakana");
          money1_loop();
        ResetState();
        break;
      }else{
        Serial.println("star_else");
          money5_loop();
        ResetState();
        break;
      }
  }
}

void Interrupt(){
  state = GET_MONEY;
  Serial.println("star");
  Serial.write(1);
}

void ResetState(){
  //FlexiTimer2::stop();
  state = WAITING;
  sub_state = (sub_state + 1) % 5;
}
