
void loop_g1() {
  // 各セグメントでアニメーションを実行
  for(int j = 0; j < SEGMENT_SIZE; j++) {
    clearAllstrip5s();

    // セグメント1のアニメーション
    animateSegment(0, j, strip5.Color(255, 0, 0)); // 赤色

    // セグメント2のアニメーション
    animateSegment(SEGMENT_SIZE, j, strip5.Color(0, 255, 0)); // 緑色

    // セグメント3のアニメーション
    animateSegment(SEGMENT_SIZE * 2, j, strip5.Color(0, 0, 255)); // 青色

    // セグメント4のアニメーション
    animateSegment(SEGMENT_SIZE * 3, j, strip5.Color(255, 255, 0)); // 黄色

    // LEDテープの更新
    strip5.show();

    // 少し待機
    delay(100);
  }
}

void clearAllstrip5s() {
  for(int i = 0; i < NUM_LEDS_100; i++) {
    strip5.setPixelColor(i, strip5.Color(100, 100, 100)); // 消灯
  }
}

void animateSegment(int start, int position, uint32_t color) {
  for(int i = position; i < position + NUM_LEDS_GROUP; i++) {
    if(i < SEGMENT_SIZE) {
      strip5.setPixelColor(start + i, color);
    }
  }
}
