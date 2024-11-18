#ifndef ROBOT_H       // Include guard to prevent multiple inclusions
#define ROBOT_H

// Base class Robot
class Robot {
protected:
    int x;  // Robot's x-coordinate position
    int y;  // Robot's y-coordinate position
public:
    Robot();                      // Constructor
    virtual void move(char direction);  // Virtual function to move the robot
    int getX() const;             // Getter for x-coordinate
    int getY() const;             // Getter for y-coordinate
    virtual ~Robot();             // Virtual destructor
};

#endif // ROBOT_H
