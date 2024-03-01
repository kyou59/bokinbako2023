void set2() {
  // 全消灯
  for(int i = 0; i < strip0.numPixels(); i++) {
      strip0.setPixelColor(i, strip0.Color(0, 0, 0));
    }
  strip0.show();

  // シャンパンゴールドとシルバーのグラデーション
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < strip0.numPixels(); j++) {
        strip0.setPixelColor(j, strip0.Color(218, 165, 32)); // シャンパンゴールド
        strip0.setPixelColor(j+1, strip0.Color(192, 192, 192)); // シルバー
        strip0.setPixelColor(j+2, strip0.Color(192, 192, 192)); // シルバー
        strip0.show();
        for(int k=0;k<3;k++){
    delayMicroseconds(1000);
  }
      }
  }

  // シャンパンゴールドとシルバーでチカチカ
  for(int j = 0; j < 8; j++) {    
   for(int i = 0; i < strip0.numPixels(); i++) {
     if(i % 2 == 0) {
       strip0.setPixelColor(i, strip0.Color(218, 165, 32)); // シャンパンゴールド
     }
     else {
       strip0.setPixelColor(i, strip0.Color(192, 192, 192)); // シルバー
     }
   }
   strip0.show();
   for(int k=0;k<200;k++){
    delayMicroseconds(1000);
  }
   for(int i = 0; i < strip0.numPixels(); i++) {
     if(i % 2 == 0) {
       strip0.setPixelColor(i, strip0.Color(192, 192, 192)); // シルバー
     }
     else {
       strip0.setPixelColor(i, strip0.Color(218, 165, 32)); // シャンパンゴールド
     }
   }
   strip0.show();
   for(int k=0;k<200;k++){
    delayMicroseconds(1000);
  }
  }
  for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
}
