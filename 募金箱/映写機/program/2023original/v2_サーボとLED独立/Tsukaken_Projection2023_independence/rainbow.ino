void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip0.numPixels(); i++) {
      strip0.setPixelColor(i, Wheel((i+j) & 255, 0));
    }
    strip0.show();
    for(int k=0;k<wait;k++){
    delayMicroseconds(1000);
  }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos, int num) {
  WheelPos = 255 - WheelPos;
  if(num == 0){
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
}
