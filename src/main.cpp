#include <iostream>
#include "canvas.h"
using namespace std;

int main(){
  canvas::SVG c(600, 600);

  // A line
  c.setStrokeColor(canvas::Colors::blue);
  c.setStrokeWidth(5);
  c.strokeLine(10, 10, 350, 350);

  // A circle
  c.setFillColor(canvas::Color(145, 67, 180));
  c.fillCircle(300, 300, 150);

  c.draw();
  return 0;
}

