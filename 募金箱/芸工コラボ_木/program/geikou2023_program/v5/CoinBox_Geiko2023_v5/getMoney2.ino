void money2_loop() {
  // 電源の遠い方から順に処理
  for(int j = NUM_LEDS_100 - 1; j >= 0; j--) {
    // 10個のLEDを緑色に点灯
    for(int i = j; i < j + NUM_LEDS; i++) {
      if(i < NUM_LEDS_100) {
        strip1.setPixelColor(i, strip1.Color(0, 100, 0));
        strip2.setPixelColor(i, strip2.Color(0, 100, 0));
        strip3.setPixelColor(i, strip3.Color(0, 100, 0));
        strip4.setPixelColor(i, strip4.Color(0, 100, 0));
        strip5.setPixelColor(i, strip5.Color(0, 100, 0));
      }
    }

    // LEDテープの更新
    strip1.show();
    strip2.show();
    strip3.show();
    strip4.show();
    strip5.show();

    // 少し待機
    delay(10);
  }

  // 電源の近い方から順に処理
  for(int j = 0; j < NUM_LEDS_100; j++) {
    // 10個のLEDを赤色に点灯
    for(int i = j; i < j-1 + NUM_LEDS; i++) {
      if(i < NUM_LEDS_100) {
        strip1.setPixelColor(i, strip1.Color(100, 0, 0));
        strip2.setPixelColor(i, strip2.Color(100, 0, 0));
        strip3.setPixelColor(i, strip3.Color(100, 0, 0));
        strip4.setPixelColor(i, strip4.Color(100, 0, 0));
        strip5.setPixelColor(i, strip5.Color(0, 0, 100));
      }
    }

    // LEDテープの更新
    strip1.show();
    strip2.show();
    strip3.show();
    strip4.show();
    strip5.show();

    // 少し待機
    delay(10);
  }
}



void clearAllStrips() {
  for(int i = 0; i < NUM_LEDS_100; i++) {
    strip1.setPixelColor(i, 0);
    strip2.setPixelColor(i, 0);
    strip3.setPixelColor(i, 0);
    strip4.setPixelColor(i, 0);
    strip5.setPixelColor(i, 0);
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
}
