#ifndef TRACKEDROBOT_H  // Include guard
#define TRACKEDROBOT_H

#include "Robot.h"      // Include the base class Robot

// Derived class TrackedRobot inherits from Robot
class TrackedRobot : public Robot {
public:
    TrackedRobot();                 // Constructor
    void move(char direction) override;  // Override the move function
};

#endif // TRACKEDROBOT_H

