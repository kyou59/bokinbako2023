//レインボー

void money3_loop() {
  rainbowCycle(1);
}

void rainbowCycle(int SpeedDelay) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5回のサイクル
    for(i=0; i< NUM_LEDS_100; i++) {
      setPixelInAllStrips(i, Wheel(((i * 256 / NUM_LEDS_100) + j) & 255));
    }
    showAllStrips();
    delay(SpeedDelay);
  }
}

void setPixelInAllStrips(int i, uint32_t color) {
  strip1.setPixelColor(i, color);
  strip2.setPixelColor(i, color);
  strip3.setPixelColor(i, color);
  strip4.setPixelColor(i, color);
}

void showAllStrips() {
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
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
