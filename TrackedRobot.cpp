#include "TrackedRobot.h"  // Include the header file
#include <iostream>        // Include iostream for console output

TrackedRobot::TrackedRobot() : Robot() {
    // Constructor calls base class constructor
}

void TrackedRobot::move(char direction) {
    // Move the robot with different movement rules
    switch (direction) {
    case 'W':
    case 'w':
        y -= 2;  // Move up faster
        break;
    case 'S':
    case 's':
        y += 2;  // Move down faster
        break;
    case 'A':
    case 'a':
        x -= 1;  // Move left
        break;
    case 'D':
    case 'd':
        x += 1;  // Move right
        break;
    default:
        std::cerr << "Invalid move command.\n";  // Error message for invalid input
    }
}

