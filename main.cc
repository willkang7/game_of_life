#include <iostream>
#include <unistd.h>
#include "grid.h"
#include "graphicsdisplay.h"
#include "window.h"


int main() {
  Grid g;

  g.setup("configurations/glider.txt");

  GraphicsDisplay graphics(500, g.getGrid().size());

  for (int i = 0; i < 100; ++i) {
    graphics.notify(g.getGrid());
  	g.step();
    sleep(1);
  }
}
