#include <iostream>
#include <fstream>
#include <stdexcept>
#include "grid.h"

void Grid::setup(std::string filename) {
  std::string line;
  std::ifstream file (filename);

  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::vector<char> row(line.begin(), line.end());
      grid.push_back(row);
    }
    file.close();
  } else {
    std::cout << "Unable to open file." << std::endl;
  }
}

void Grid::step() {
  std::vector<std::vector<char>> new_grid;
  
  for (std::size_t row = 0; row < grid.size(); ++row) {
    std::vector<char> new_row;
    for (std::size_t col = 0; col < grid[0].size(); ++col) {
      int neighbours = count_neighbours(row, col);
      char new_cell = get_new_cell(grid[row][col], neighbours);
      new_row.push_back(new_cell);
    }
    new_grid.push_back(new_row);
  }

  grid = new_grid;
}

int Grid::count_neighbours(int row, int col) {
  int count = 0;

  for (int dr = -1; dr <= 1; ++dr) {
    for (int dc = -1; dc <= 1; ++dc) {
      if (!(dr == 0 && dc == 0)) {
        try {
          char neighbour = grid.at(row + dr).at(col + dc);
          if (neighbour == '#') {
            ++count;
          }
        } catch (std::out_of_range r) {}
      }
    }
  }

  return count;
}

char Grid::get_new_cell(char curr_cell, int neighbours) {
  char new_cell;

  // Case 1: Cell is live.
  if (curr_cell == '#') {
    if (neighbours == 2 || neighbours == 3) {
      new_cell = '#';
    } else {
      new_cell = '.';
    }
  }
  // Case 2: Cell is dead.
  else if (curr_cell == '.') {
    if (neighbours == 3) {
      new_cell = '#';
    } else {
      new_cell = '.';
    }
  }

  return new_cell;
}

void Grid::print() {
  for (auto row : grid) {
    for (auto cell : row) {
      std::cout << cell;
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<char>> Grid::getGrid() {
  return grid;
}
