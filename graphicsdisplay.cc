#include "graphicsdisplay.h"

GraphicsDisplay::GraphicsDisplay(int windowSize, int gridSize)
  : windowSize {windowSize},
    gridSize {gridSize},
    cellSize {windowSize / gridSize}
{}

void GraphicsDisplay::notify(std::vector<std::vector<char>> grid) {
  for (int row = 0; row < gridSize; ++row) {
    for (int col = 0; col < gridSize; ++col) {
      if (grid[row][col] == '#') {
        w.fillRectangle(col * cellSize, row * cellSize,
          cellSize - 1, cellSize - 1, Xwindow::Black);
      } else if (grid[row][col] == '.'){
        w.fillRectangle(col * cellSize, row * cellSize,
          cellSize - 1, cellSize - 1, Xwindow::White);
      }
    }
  }
}
