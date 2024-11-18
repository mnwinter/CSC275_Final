#ifndef WHEELEDROBOT_H   // Include guard
#define WHEELEDROBOT_H

#include "Robot.h"       // Include the base class Robot

// Derived class WheeledRobot inherits from Robot
class WheeledRobot : public Robot {
public:
    WheeledRobot();                 // Constructor
    void move(char direction) override;  // Override the move function
};

#endif // WHEELEDROBOT_H

