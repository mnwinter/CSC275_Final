#include "Grid.h"       // Include the header file
#include <iostream>     // Include iostream for console output
#include <cstdlib>      // Include cstdlib for rand and srand
#include <ctime>        // Include ctime for time function

Grid::Grid(int w, int h) : width(w), height(h) {
    // Initialize the grid with empty spaces represented by '.'
    grid.resize(height, std::vector<char>(width, '.'));
}

void Grid::placeObstacles(int count) {
    // Place a specified number of obstacles represented by '#'
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    for (int i = 0; i < count; ++i) {
        int obsX = rand() % width;    // Generate a random x-coordinate
        int obsY = rand() % height;   // Generate a random y-coordinate
        grid[obsY][obsX] = '#';       // Place an obstacle at the random position
    }
}

void Grid::displayGrid(int robotX, int robotY) {
    // Display the grid with the robot's current position
    for (int y = 0; y < height; ++y) {         // Loop through each row
        for (int x = 0; x < width; ++x) {      // Loop through each column
            if (x == robotX && y == robotY) {
                std::cout << 'R' << ' ';       // Display 'R' where the robot is
            }
            else {
                std::cout << grid[y][x] << ' ';  // Display the grid cell
            }
        }
        std::cout << '\n';  // Newline after each row
    }
}

bool Grid::isObstacle(int x, int y) {
    // Check if the given position has an obstacle or is outside the grid
    if (x < 0 || x >= width || y < 0 || y >= height)
        return true;  // Outside the grid is considered an obstacle
    return grid[y][x] == '#';  // Return true if there's an obstacle
}

