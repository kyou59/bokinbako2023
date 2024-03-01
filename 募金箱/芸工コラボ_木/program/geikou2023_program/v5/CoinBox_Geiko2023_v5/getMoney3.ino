//レインボー

void money3_loop() {
  // strip1〜4を消灯
  clearAllStrips_3();
  for(int i = 0; i <2; i++) {
  // strip5だけ光らせる（電源から遠い方から）
    strip5RainbowCycle(1, true);
  }
  // 0.5秒待機
  delay(500);
  
  // strip1〜4も光らせる（電源から近い方から）
  rainbowCycle(1, false);
}

void strip5RainbowCycle(int SpeedDelay, bool reverse) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 5回のサイクル
    for(i=0; i< NUM_LEDS_100; i++) {
      if (reverse) {
        strip5.setPixelColor(i, Wheel(((NUM_LEDS_100 - 1 - i) * 256 / NUM_LEDS_100) + j) & 255);
      } else {
        strip5.setPixelColor(i, Wheel((i * 256 / NUM_LEDS_100) + j) & 255);
      }
    }
    strip5.show();
    delay(SpeedDelay);
  }
}



void rainbowCycle(int SpeedDelay, bool reverse) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 5回のサイクル
    for(i=0; i< NUM_LEDS_100; i++) {
      if (reverse) {
        setPixelInAllStrips(NUM_LEDS_100 - 1 - i, Wheel(((i * 256 / NUM_LEDS_100) + j) & 255));
      } else {
        setPixelInAllStrips(i, Wheel(((i * 256 / NUM_LEDS_100) + j) & 255));
      }
    }
    showAllStrips();
    for(int k=0; k<SpeedDelay; k++){
      delayMicroseconds(1000);
    }
  }
}

void setPixelInAllStrips(int i, uint32_t color) {
  strip1.setPixelColor(i, color);
  strip2.setPixelColor(i, color);
  strip3.setPixelColor(i, color);
  strip4.setPixelColor(i, color);
  strip5.setPixelColor(i, color);
}

void showAllStrips() {
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();  
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void clearAllStrips_3() {
  for(int i = 0; i < NUM_LEDS_100; i++) {
    setPixelInAllStrips(i, 0);  // 0は消灯を表します
  }
  showAllStrips();
}
