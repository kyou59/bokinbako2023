void set1() { //コイン認識時の動作を設計
  //グラデーションやアニメーションを作る時は色を変えるごとにstrip1.showする必要あり
  for(int i = 0; i < strip0.numPixels(); i++) { //全消灯
      strip0.setPixelColor(i, strip0.Color(0, 0, 0));
    }
  strip0.show();

  
    for(int i = 0; i < strip0.numPixels(); i++) { //赤～緑のグラデーションが駆け抜ける感じ
        strip0.setPixelColor(i, strip0.Color(255, 0, 0));
        strip0.setPixelColor(i+1, strip0.Color(255, 165, 0));
        strip0.setPixelColor(i+2, strip0.Color(255, 255, 0));
        strip0.setPixelColor(i+3, strip0.Color(154, 205, 50));
        strip0.setPixelColor(i+4, strip0.Color(0, 255, 0));
        strip0.show();
        for(int k=0;k<10;k++){
    delayMicroseconds(1000);
  }
      }
    

  for(int j = 0; j < 8; j++) {    
   for(int i = 0; i < strip0.numPixels(); i++) { //赤と緑でチカチカ
     if(i % 6 < 3) {
       strip0.setPixelColor(i, strip0.Color(255, 0, 0));
     }
     else {
       strip0.setPixelColor(i, strip0.Color(0, 255, 0));
     }
   }
     strip0.show();
      for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
   for(int i = 0; i < strip0.numPixels(); i++) {
     if(i % 6 < 3) {
       strip0.setPixelColor(i, strip0.Color(0, 255, 0));
     }
     else {
       strip0.setPixelColor(i, strip0.Color(255, 0, 0));
     }
   }
   strip0.show();
      for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
   }
  for(int k=0;k<100;k++){
    delayMicroseconds(1000);
  }
}
