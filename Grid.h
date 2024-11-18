#ifndef GRID_H     // Include guard
#define GRID_H

#include <vector>  // Include vector for dynamic arrays

// Class representing the grid environment
class Grid {
private:
    int width;  // Width of the grid
    int height; // Height of the grid
    std::vector<std::vector<char>> grid;  // 2D vector representing the grid cells
public:
    Grid(int w, int h);            // Constructor
    void placeObstacles(int count);        // Function to place obstacles on the grid
    void displayGrid(int robotX, int robotY);  // Function to display the grid
    bool isObstacle(int x, int y);         // Function to check for obstacles
};

#endif // GRID_H

