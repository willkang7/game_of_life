#include <iostream>
#include "grid.h"

int main() {
  Grid g;
  g.setup("configurations/glider.txt");

  for (int i = 0; i < 10; ++i) {
  	g.print();
  	std::cout << std::endl;
  	g.step();
  }
}
