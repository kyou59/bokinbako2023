#define NUM_LEDS    10 //繰り返し回数，使わなくても大丈夫

void stay1() { //待機時の動作を設計
  flag = true;

  //グラデーションやアニメーションを作る時は色を変えるごとにstrip1.showする必要あり
  for(int i = 0; i < strip0.numPixels(); i++) { //LED全部赤に
      strip0.setPixelColor(i, strip0.Color(255, 0, 0));
    }
  strip0.show();  
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }
  
  for(int i = 0; i < NUM_LEDS; i++) {
      for(int j = 0; j < strip0.numPixels(); j++) {   //LEDの偶数箇所を徐々に白く 
        strip0.setPixelColor(j*2, strip0.Color(255, 0+16*i, 0+16*i));
      }
      strip0.show(); 
      for(int k=0;k<80;k++){
    delayMicroseconds(1000);
  }
    }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }

  for(int i = 0; i < NUM_LEDS; i++) {
      for(int j = 0; j < strip0.numPixels(); j++) {    //LEDの偶数箇所を徐々に元に戻す 
        strip0.setPixelColor(j*2, strip0.Color(255, 144-16*i, 144-16*i));
      }
      strip0.show();
      for(int k=0;k<80;k++){
    delayMicroseconds(1000);
  }
    }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }

  for(int i = 0; i < NUM_LEDS; i++) {
      for(int j = 0; j < strip0.numPixels(); j++) {    //LEDの奇数箇所を徐々に黄色く 
        strip0.setPixelColor(j*2+1, strip0.Color(255, 0+16*i, 0));
      }
      strip0.show();
      for(int k=0;k<80;k++){
    delayMicroseconds(1000);
  }
    }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }

  for(int i = 0; i < NUM_LEDS; i++) {
      for(int j = 0; j < strip0.numPixels(); j++) {    //LEDの奇数箇所を徐々に元に戻す 
        strip0.setPixelColor(j*2+1, strip0.Color(255, 144-16*i, 0));
      }
      strip0.show();
      for(int k=0;k<80;k++){
    delayMicroseconds(1000);
  }
    }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }
  
}
