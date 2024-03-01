void money4_loop() {
  for (int j = 0; j < NUM_LEDS_100 * 2; j++) {
    // clearAllStrips()を呼び出さないように変更

    // LEDグループを左から右に流す
    for (int groupStart = j; groupStart < j + NUM_LEDS_100; groupStart += GROUP_SPACING) {
      if (groupStart < NUM_LEDS_100) {
        int colorIndex = groupStart / GROUP_SPACING;
        lightGroup(groupStart, colorIndex);
      }
    }

    showAllStrips_4();
  }
}

void lightGroup(int groupStart, int colorIndex) {
  // ランダムな色を生成
  uint8_t red = random(256);
  uint8_t green = random(256);
  uint8_t blue = random(256);

  // 各グループに同じ色を設定
  uint32_t color = strip1.Color(red, green, blue);
  for (int i = groupStart; i < groupStart + NUM_LEDS; i++) {
    if (i < NUM_LEDS_100) {
      strip1.setPixelColor(i, color);
      strip2.setPixelColor(i, color);
      strip3.setPixelColor(i, color);
      strip4.setPixelColor(i, color);
      strip5.setPixelColor(i, color);
    }
  }
}


// clearAllStrips()関数を削除

void showAllStrips_4() {
  // 各LEDストリップを表示
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
}
