
void money1_loop() {
  for(int j = 0; j < 1; j++) {
    // 全てのLEDを消灯
    for(int i = 0; i < NUM_LEDS_100; i++) {
      strip1.setPixelColor(i, strip1.Color((j*100)%255, 100, 0));
      strip2.setPixelColor(i, strip2.Color((j*100)%255, 100, 0));
      strip3.setPixelColor(i, strip3.Color((j*100)%255, 100, 0));
      strip4.setPixelColor(i, strip4.Color((j*100)%255, 100, 0));
      // LEDテープの更新
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      // 少し待機
      for(int k=0;k<10;k++){
    delayMicroseconds(1000);
  }
    }
  }
  // 少し待機
  for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
}
