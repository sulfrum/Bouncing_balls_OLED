#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
// OLED display
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (o;;r -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // value cheked with script, differet from the default
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "Ball.h"

#define acc 0.07  // balls acceleration
#define drops 10  // balls number

Ball *balls[drops];  //declare an array of Ball

void setup() {
  Serial.begin(9600);
  randomSeed(43);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;  // Don't proceed, loop forever
  }
  //  Accesso alle variabili di classe
  Ball::screenWidth = SCREEN_WIDTH;
  Ball::screenHeight = SCREEN_HEIGHT;

  // array init
  for (int i = 0; i < drops; i++) {
    float posX = float(random(0, SCREEN_WIDTH) * 1000) / 1000;
    float posY = float(random(0, 10 * 1000)) / 1000;
    float volY = float(random(0, 2 * 1000)) / 1000;
    float volX = float(random(-1 * 1000, 2 * 1000)) / 1000;
    balls[i] = new Ball(posX, posY, volX, 0, acc);
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(200);
}

void loop() {

  display.clearDisplay();
  for (int i = 0; i < drops; i++) {
    // TODO
    // create a class function to display
    // maybe not, due to different class interaction: the display and the bass
    balls[i]->nextFrame();
    balls[i]->bounce();

    int x = balls[i]->putX();
    int y = balls[i]->putY();

    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
  delay(20);
}