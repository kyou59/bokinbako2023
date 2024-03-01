#define NUM_LEDS    10 //繰り返し回数，使わなくても大丈夫

void set3() {
  setRainbowCycle();
  setSequentialFlash();
  setRandomFlash();
}

// LEDが虹のような色で光り、徐々に色が変わります。
void setRainbowCycle() {
  int wait = 10; // 色の変化のスピード調整

  for(int j = 0; j < 256; j++) {
    for(int i = 0; i <strip0.numPixels() ; i++) {
      strip0.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip0.show();
    for(int k=0;k<wait;k++){
    delayMicroseconds(1000);
  }
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip0.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip0.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip0.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// LEDが順番に点滅し、その後全消灯するサイクルを繰り返します。
void setSequentialFlash() {
  int flashDuration = 40; // 点滅の速さ調整

  for(int i = 0; i < strip0.numPixels(); i++) {
    strip0.setPixelColor(i, strip0.Color(255, 255, 255)); // 白色
    strip0.show();
    for(int k=0;k<flashDuration;k++){
    delayMicroseconds(1000);
  }
    strip0.setPixelColor(i, strip0.Color(0, 0, 0)); // 消灯
    strip0.show();
  }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }
}


// LEDがランダムな場所で点滅し、その後全消灯するサイクルを繰り返します。

void setRandomFlash() {
  int flashDuration = 40; // 点滅の速さ調整

  for(int i = 0; i < 20; i++) { // ランダムな点滅を5回繰り返す
    int randomPixel = random(strip0.numPixels());
    strip0.setPixelColor(randomPixel, strip0.Color(255, 255, 255)); // 白色
    strip0.show();
    for(int k=0;k<flashDuration;k++){
    delayMicroseconds(1000);
  }
    strip0.setPixelColor(randomPixel, strip0.Color(255, 255, 255)); // 全灯
    strip0.show();
  }
  for(int k=0;k<500;k++){
    delayMicroseconds(1000);
  }
}