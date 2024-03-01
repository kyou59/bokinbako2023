//いっぱい流れてるアニメーション(炎)

void money5_loop() {
  fireAnimation(55, 150); // 炎のアニメーション
}

void fireAnimation(int Cooling, int Sparking) {
  static byte heat[NUM_LEDS_100];
  int cooldown;

  // 熱を冷ます
  for(int i = 0; i < NUM_LEDS_100; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS_100) + 2);

    if(cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] -= cooldown;
    }
  }

  // 熱を上に移動
  for(int k = NUM_LEDS_100 - 1; k >= 2; k--) {
    heat[k] = heat[k - 1];
  }

  // 新しい火花を追加
  if(random(255) < Sparking) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    // 火花の温度を調整
    if(heat[y] > 255) heat[y] = 255;
  }

  // 色を設定
  for(int j = 0; j < NUM_LEDS_100; j++) {
    setPixelInAllStrips_5(j, HeatColor(heat[j]));
  }
  showAllStrips_5();
  for(int k=0;k<50;k++){
    delayMicroseconds(1000);
  }
}

uint32_t HeatColor(byte temperature) {
  // 熱に基づいて色を計算
  byte t192 = round((temperature / 255.0) * 191);

  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // 4倍に拡大

  if(t192 > 0x80) { // 最も熱い
    return strip1.Color(255, 255, heatramp);
  } else if(t192 > 0x40 ) { // 中間
    return strip1.Color(255, heatramp, 0);
  } else { // 冷ややか
    return strip1.Color(heatramp, 0, 0);
  }
}


void setPixelInAllStrips_5(int i, uint32_t color) {
  strip1.setPixelColor(i, color);
  strip2.setPixelColor(i, color);
  strip3.setPixelColor(i, color);
  strip4.setPixelColor(i, color);
}

void showAllStrips_5() {
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
}
