#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include <string>

class Grid {
  std::vector<std::vector<char>> grid;

  int count_neighbours(int row, int col); // Count adjacent live cells.
  char get_new_cell(char curr_cell, int neighbours); // Determine if the cell
  // is dead or live in the next generation.
 public:
  void setup(std::string filename); // Create the initial configuration.
  void step(); // Calculate the next generation.
  void print(); // Print the grid.
};

#endif
