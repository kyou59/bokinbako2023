//いっぱい流れる

void money4_loop(){
  for(int j = 0; j < NUM_LEDS_100 + GROUP_SPACING; j++) {
    // 全てのLEDを消灯
    clearAllStrips();

    // 複数のLEDグループを点灯
    for(int groupStart = j - NUM_LEDS; groupStart < NUM_LEDS_100; groupStart += GROUP_SPACING) {
      if(groupStart >= 0) {
        lightGroup(groupStart, (groupStart / GROUP_SPACING) % 3); // グループごとに色を変更
      }
    }

    // LEDテープの更新
    showAllStrips_4();

    // 少し待機
    for(int k=0;k<50;k++){
    delayMicroseconds(1000);
  }
  }
}

void clearAllStrips() {
  for(int i = 0; i < NUM_LEDS_100; i++) {
    strip1.setPixelColor(i, strip1.Color(0, 0, 0));
    strip2.setPixelColor(i, strip2.Color(0, 0, 0));
    strip3.setPixelColor(i, strip3.Color(0, 0, 0));
    strip4.setPixelColor(i, strip4.Color(0, 0, 0));
  }
}

void lightGroup(int groupStart, int colorIndex) {
  uint32_t color;
  switch(colorIndex) {
    case 0: color = strip1.Color(100, 0, 0); break; // 赤色
    case 1: color = strip1.Color(0, 100, 0); break; // 緑色
    case 2: color = strip1.Color(0, 0, 100); break; // 青色
    default: color = strip1.Color(100, 100, 100); // 白色
  }

  for(int i = groupStart; i < groupStart + NUM_LEDS; i++) {
    if(i < NUM_LEDS_100) {
      strip1.setPixelColor(i, color);
      strip2.setPixelColor(i, color);
      strip3.setPixelColor(i, color);
      strip4.setPixelColor(i, color);
    }
  }
}

void showAllStrips_4() {
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
}
