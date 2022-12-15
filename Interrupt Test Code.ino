#include <Adafruit_NeoPixel.h>

#define LONGPIN 23
#define LINEA 25

float value0 = 3035; // 4 Seconds
float value1 = 16900; // 2.5 Seconds

Adafruit_NeoPixel long_strip = Adafruit_NeoPixel(122, LONGPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LINE1 = Adafruit_NeoPixel(6, LINEA, NEO_GRB + NEO_KHZ800);

void setup() {
  long_strip.begin();
  LINE1.begin();
  long_strip.setBrightness(50);
  LINE1.setBrightness(50);
  long_strip.show(); // Initialize all pixels to 'off'
  LINE1.show(); // Initialize all pixels to 'off'

  // Initialize Timers
  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = value1;

  TCCR1B |= (1 << CS10)|(1<<CS12); // Prescaler Value is set in register
  TIMSK1 |= (1 << TOIE1); // Timer overflow enabled
  
  /*TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = value0;

  TCCR0B |= (1 << CS10)|(1<<CS12); // Prescaler Value is set in register
  TIMSK0 |= (1 << TOIE0); // Timer overflow enabled*/
  
  interrupts();  // Interrupts enabled
}

//ISR(TIMER0_COMPA_vect) { // Check inputs 
  
//}

ISR(TIMER1_OVF_vect) { // Tile Test
  TCNT1 = value1;
  uint16_t boop = 3;
  for(uint16_t i=0; i<LINE1.numPixels()+boop; i++) {
    LINE1.setPixelColor(i, LINE1.Color(0, 0, 200));
    LINE1.setPixelColor(i-boop, LINE1.Color(0, 0, 0));
    LINE1.show();
    delay(50);
  }  

  /*for(uint16_t i=boop; boop<LINE1.numPixels(); i++) {
    LINE1.setPixelColor(i, LINE1.Color(0, 0, 0));
    LINE1.show();
    delay(50);
  }*/
}

//ISR3(TIMER2_OVF_vect)

void loop() {
  longFlow(long_strip.Color(127, 127, 0), 50, 6);
  //forwardFlow(long_strip, long_strip.Color(127, 200, 0), 50, 3);
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

  for(uint16_t i=0; i< numPixels; i++) {
    line.setPixelColor(i, c);
    line_boop = i-boop;
    //line.setPixelColor(line_boop, line.Color(0, 0, 0));
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

void colorWipe(Adafruit_NeoPixel strip, uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
