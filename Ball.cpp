#include "Arduino.h"
#include "Ball.h"

Ball::Ball(float x, float y, float vx, float vy, float acc) {
  _x = x;
  _y = y;
  _vx = vx;
  _vy = vy;
  _acc = acc;
}

// variabili di classe da mettere sia in heder che in cpp
// in cpp ci puo essere l'init
static int Ball::screenWidth = 128;
static int Ball::screenHeight = 64;

void Ball::nextFrame() {
  _x += _vx;
  _y += _vy;
  _vy += _acc;
};

void Ball::bounce() {
  if (_y >= screenHeight) {
    _y = screenHeight;
    //_y -= _vy;
    _vy *= -1*0.9;
  }

  if (_x <= 0) {
    _x = 0;
    _vx *= -1;
  }

  else if (_x >= screenWidth) {
    _x = screenWidth;
    _vx *= -1;
  }
}

void Ball::printDot() {
}

int Ball::putX() {
  return int(_x);
};

int Ball::putY() {
  return int(_y);
};