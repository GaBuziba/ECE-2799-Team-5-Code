#include <Adafruit_NeoPixel.h>

// Setting Pins
#define LONGPIN 23
#define LINEA 25
#define LINEB 27
#define LINEC 29
#define LINED 31
#define LINEE 33
#define LINEF 35
#define LINEG 37
#define LINEH 39
#define LINEI 41
#define LINEJ 43
#define TITLE 45

// Setting Lines
// #LEDs, pin, Color(don't change)
// Need 6 Interupts (User Caused)
Adafruit_NeoPixel long_strip = Adafruit_NeoPixel(122, LONGPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LINE1 = Adafruit_NeoPixel(8, LINEA, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LINE2 = Adafruit_NeoPixel(3, LINEB, NEO_GRB + NEO_KHZ800); // Tile 1
Adafruit_NeoPixel LINE3 = Adafruit_NeoPixel(6, LINEC, NEO_GRB + NEO_KHZ800); // Tile 2
Adafruit_NeoPixel LINE4 = Adafruit_NeoPixel(9, LINED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LINE5 = Adafruit_NeoPixel(3, LINEE, NEO_GRB + NEO_KHZ800); // Tile 3
Adafruit_NeoPixel LINE6 = Adafruit_NeoPixel(3, LINEF, NEO_GRB + NEO_KHZ800); // Tile 4 
Adafruit_NeoPixel LINE7 = Adafruit_NeoPixel(13, LINEG, NEO_GRB + NEO_KHZ800); // Tile 5
Adafruit_NeoPixel LINE8 = Adafruit_NeoPixel(2, LINEH, NEO_GRB + NEO_KHZ800); // Tile 6
Adafruit_NeoPixel LINE9 = Adafruit_NeoPixel(2, LINEI, NEO_GRB + NEO_KHZ800); // Tile 6
Adafruit_NeoPixel LINE10 = Adafruit_NeoPixel(3, LINEJ, NEO_GRB + NEO_KHZ800); // Tile 6
Adafruit_NeoPixel title = Adafruit_NeoPixel(52, TITLE, NEO_GRB + NEO_KHZ800);

void setup() {
  long_strip.begin();
  long_strip.setBrightness(50);
  long_strip.show(); // Initialize all pixels to 'off'

  LINE1.begin();
  LINE1.setBrightness(50);
  LINE1.show(); // Initialize all pixels to 'off'

  LINE2.begin();
  LINE2.setBrightness(50);
  LINE2.show(); // Initialize all pixels to 'off'

  LINE3.begin();
  LINE3.setBrightness(50);
  LINE3.show(); // Initialize all pixels to 'off'

  LINE4.begin();
  LINE4.setBrightness(50);
  LINE4.show(); // Initialize all pixels to 'off'

  LINE5.begin();
  LINE5.setBrightness(50);
  LINE5.show(); // Initialize all pixels to 'off'

  LINE6.begin();
  LINE6.setBrightness(50);
  LINE6.show(); // Initialize all pixels to 'off'

  LINE7.begin();
  LINE7.setBrightness(50);
  LINE7.show(); // Initialize all pixels to 'off'

  LINE8.begin();
  LINE8.setBrightness(50);
  LINE8.show(); // Initialize all pixels to 'off'

  LINE9.begin();
  LINE9.setBrightness(50);
  LINE9.show(); // Initialize all pixels to 'off'

  LINE10.begin();
  LINE10.setBrightness(50);
  LINE10.show(); // Initialize all pixels to 'off'

  title.begin();
  title.setBrightness(50);
  title.show(); // Initialize all pixels to 'off'
}

void loop() {
  longFlow(long_strip.Color(127, 127, 0), 50, 6);
  forwardFlow(LINE1, LINE1.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE2, LINE2.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE3, LINE3.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE4, LINE4.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE5, LINE5.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE1, LINE1.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE2, LINE2.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE3, LINE3.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE4, LINE4.Color(127, 200, 0), 50, 3);
  forwardFlow(LINE5, LINE5.Color(127, 200, 0), 50, 3);
  //reverseFlow(LINE2, LINE2.Color(127, 200, 0), 50, 3);
}

void longFlow(uint32_t c, uint8_t wait, uint16_t boop) {
  // Set start points
  uint16_t sml_start = 36;
  uint16_t med_start = 37;
  uint16_t lrg_start = 122;
  uint16_t sml_boop, med_boop, lrg_boop; // Boops

  
  sml_boop = sml_start + boop; // Sets boop, main, line
  med_boop = med_start - boop;
  lrg_boop = lrg_start + boop;

  for (uint16_t i=0; i<=48; i++) { // Cycle through at least the longest strand
    if (sml_start >= 0) // Small Line
      long_strip.setPixelColor(sml_start, c); // Signal line
      if (sml_boop <= 36) // Only runs when "boop" is on the correct line
        long_strip.setPixelColor(sml_boop, long_strip.Color(0, 0, 0)); // Sets main line
      sml_start--;
      sml_boop = sml_start + boop;

    if (med_start <= 76) // Medium Line
      long_strip.setPixelColor(med_start, c);
      long_strip.setPixelColor(med_boop, long_strip.Color(0, 0, 0));
      med_start++;
      med_boop = med_start - boop;

    if (lrg_start >= 77) // Large Line
      //lrg_boop = lrg_start + boop; // Sets boop, main, line
      long_strip.setPixelColor(lrg_start, c); // Signal line
      if (lrg_boop <= 122) // Only runs when "boop" is on the correct line
        long_strip.setPixelColor(lrg_boop, long_strip.Color(0, 0, 0)); // Sets main line
      lrg_start--;
      lrg_boop = lrg_start + boop;

    long_strip.show();
    delay(wait);
  }
}

void forwardFlow(Adafruit_NeoPixel line, uint32_t c, uint8_t wait, uint16_t boop) {
  uint16_t numPixels = line.numPixels();
  uint16_t line_boop;

  for(uint16_t i=0; i<= numPixels; i++) {
    line.setPixelColor(i, c);
    line_boop = i-boop;
    line.setPixelColor(line_boop, line.Color(0, 0, 0));
    line.show();
    delay(wait);
  }
  for (uint16_t j = 0; j<=boop; j++) {
    line.setPixelColor(line_boop, line.Color(0, 0, 0));
    line_boop++;
    line.show();
    delay(wait);
  }
}

void reverseFlow(Adafruit_NeoPixel line, uint32_t c, uint8_t wait, uint16_t boop) {
  uint16_t numPixels = line.numPixels();
  uint16_t line_boop;

  for(uint16_t i=numPixels; i>= 0; i--) {
    line.setPixelColor(i, c);
    line_boop = i+boop;
    line.setPixelColor(line_boop, line.Color(0, 0, 0));
    line.show();
    delay(wait);
  }
  for (uint16_t j = 0; j<=boop; j++) {
    line.setPixelColor(line_boop, line.Color(0, 0, 0));
    line_boop++;
    line.show();
    delay(wait);
  }
}
