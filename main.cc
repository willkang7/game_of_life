#include <iostream>
#include <unistd.h>
#include "grid.h"
#include "graphicsdisplay.h"
#include "window.h"

int main() {
  Grid g;

  g.setup("configurations/gosper_glider_gun.txt");

  GraphicsDisplay graphics(500, g.getGrid().size());

  for (int i = 0; i < 1000; ++i) {
    graphics.notify(g.getGrid());
  	g.step();
  	usleep(100000);
  }
}
