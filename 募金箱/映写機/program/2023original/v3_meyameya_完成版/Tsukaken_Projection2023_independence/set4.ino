#define SCANNER_COLOR  strip0.Color(255, 0, 0)  // Red color for the scanner
#define STANDBY_COLOR  strip0.Color(255, 255, 255)  // White color for standby LEDs

void set4() {
  scannerAnimation(30);  // Adjust the delay for the speed of the scanner
}

void scannerAnimation(int delayTime) {
  static int position = 0;
  static bool direction = true;  // Direction of the scanner

  // Set all LEDs to standby color (white)
  strip0.fill(STANDBY_COLOR);

  for (int i = 0; i < strip0.numPixels(); i++) {
    // Set the LED at the current position to the scanner color
  strip0.setPixelColor(i, SCANNER_COLOR);
  for(int k=0;k<delayTime;k++){
    delayMicroseconds(1000);
  }
  // Show the changes on the strip1
  strip0.show();
  }

  for (int i = strip0.numPixels(); i >= 0; i--) {
    // Set the LED at the current position to the scanner color
  strip0.setPixelColor(i, STANDBY_COLOR);
  for(int k=0;k<delayTime;k++){
    delayMicroseconds(1000);
  }
  // Show the changes on the strip1
  strip0.show();
  }
}
