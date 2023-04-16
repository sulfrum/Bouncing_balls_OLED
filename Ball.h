#ifndef Ball_h
#define Ball_h
#include "Arduino.h"

class Ball {

public:
  Ball(float x, float y, float vx, float vy, float acc);
  void nextFrame();
  void printDot();
  void bounce();
  int putX();
  int putY();
  // variabili di classe da mettere sia in heder che nel cpp
  static int screenWidth;
  static int screenHeight;


private:
  float _x;
  float _y;
  float _vx;
  float _vy;
  float _acc;
};

#endif