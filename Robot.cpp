#include "Robot.h"   // Include the header file for Robot class

Robot::Robot() : x(0), y(0) {}  // Constructor initializes x and y to 0

void Robot::move(char direction) {
    // Base robot doesn't implement movement; function is virtual
}

int Robot::getX() const {
    return x;  // Return the x-coordinate
}

int Robot::getY() const {
    return y;  // Return the y-coordinate
}

Robot::~Robot() {
    // Virtual destructor; no dynamic memory to clean up
}
