#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <vector>
#include "window.h"

class GraphicsDisplay {
  Xwindow w;
  const int windowSize;
  const int gridSize;
  const int cellSize;

 public:
  GraphicsDisplay(int windowSize, int gridSize); // Create grid.
  void notify(std::vector<std::vector<char>> grid); // Update grid.
};
#endif
