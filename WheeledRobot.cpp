#include "WheeledRobot.h"  // Include the header file
#include <iostream>        // Include iostream for console output

WheeledRobot::WheeledRobot() : Robot() {
    // Constructor calls base class constructor
}

void WheeledRobot::move(char direction) {
    // Move the robot based on the input direction
    switch (direction) {
    case 'W':
    case 'w':
        y--;  // Move up
        break;
    case 'S':
    case 's':
        y++;  // Move down
        break;
    case 'A':
    case 'a':
        x--;  // Move left
        break;
    case 'D':
    case 'd':
        x++;  // Move right
        break;
    default:
        std::cerr << "Invalid move command.\n";  // Error message for invalid input
    }
}
