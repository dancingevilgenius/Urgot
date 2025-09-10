// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define DATA_PIN 6
#define TILE_HEIGHT 8
#define TILE_WIDTH 8
#define NUM_TILES 1
#define BRIGHTNESS 4 // 40 be enough for most purposes
#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  TILE_WIDTH * NUM_TILES, TILE_HEIGHT,
  DATA_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT + // Originally NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0),    // Red
  matrix.Color(0, 255, 0),    // Green
  matrix.Color(0, 0, 255) };  // Blue

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(BRIGHTNESS);
  matrix.setTextColor(colors[COLOR_BLUE]);
}

bool isOdd(int16_t n){
  return n % 2;
}

void drawCorrectPixel(int16_t x, int16_t y, uint16_t color){
    if(isOdd(x)){
        matrix.drawPixel(x, y+7, color);
    } else {
        matrix.drawPixel(x, y, color);
    }
}

void loop() {
  matrix.fillScreen(0);

  //matrix.fillRect(0, 0, 4, 4, colors[0]);
  //matrix.drawLine(0, 0, 3, 1, colors[COLOR_BLUE]);
  //matrix.drawPixel(0, 0, colors[COLOR_BLUE]);
  //matrix.drawPixel(1, 0, colors[COLOR_BLUE]);
  //matrix.drawPixel(2, 0, colors[COLOR_BLUE]);

  drawCorrectPixel(0, 0, colors[COLOR_BLUE]);
  drawCorrectPixel(1, 0, colors[COLOR_BLUE]);
  drawCorrectPixel(2, 0, colors[COLOR_BLUE]);
  drawCorrectPixel(3, 0, colors[COLOR_BLUE]);
  drawCorrectPixel(4, 0, colors[COLOR_BLUE]);

  drawCorrectPixel(0, 2, colors[COLOR_RED]);
  drawCorrectPixel(1, 2, colors[COLOR_RED]);
  drawCorrectPixel(2, 2, colors[COLOR_RED]);
  drawCorrectPixel(3, 2, colors[COLOR_RED]);
  drawCorrectPixel(4, 2, colors[COLOR_RED]);



  matrix.show();
  delay(100);
}
