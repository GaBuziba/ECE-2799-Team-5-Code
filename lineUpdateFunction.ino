oid lineUpdate (Adafruit_NeoPixel line; uint16_t = button; uint16_t boop; uint16_t wait) { // Takes the line used, button case, boop length, and delay time
  switch (button) {
    case 1: // Forward
      for(uint16_t i=0; i<=line.numPixels(); i++) {
        boop = i+boop;
        line.setPixelColor(i, line.Color(127, 127, 0));
        line.setPixelColor(i+boop, line.Color(0, 0, 0));    
        line.show();
        delay(wait);        
      }
      for(uint16_t j=line.numPixels()-boop; j<=line.numPixels(); j++) { // Correction
        line.setPixelColor(j, line.Color(0, 0, 0));
        line.show();
      }

    case -1: // Reverse
      for(uint16_t i=line.numPixels; i>=0; i--) {
        line.setPixelColor(i, line.Color(127, 127, 0));
        line.setPixelColor(i-boop, line.Color(0, 0, 0));           
        line.show();
        delay(wait);
      }
      for(uint16_t j=boop; j>=0; j--) { // Correction
        line.setPixelColor(j, line.Color(0, 0, 0));
        line.show();
      }

    case 0: // Off
      for(uint16_t i=0; i<=line.numPixels(); i++) {
        line.setPixelColor(i, line.Color(0, 0, 0));   
        line.show();
      }

    case 3; // Wrong
      for(uint16_t i=0; i<=line.numPixels(); i++) {
        line.setPixelColor(i, line.Color(127, 0, 0));   
        line.show();
        delay(wait);
      }

  }
}
