/*
Matthew Winter
CSC 275 Final Project
11/17/2024

Final Project Overview
	Create a final project of your choice which meets the expectations below.

Guidelines
	Some examples are:

	Chatbot
	Adventure Game
	Simulator
	Create your own working computer language like Basic, Python, C, or a make up a new one.


Expectations:
	The application should not be something just to demonstrate the requirements, it should "do" something, be innovative.
	Be clever, not complex.
	This application is required to have a good UX.
	This application is required to be over commented.
	The organization and file names must make sense and describe their purpose and the code contained in them.

Create a C++ application or game of your choice. It must meet each the requirements of the items listed below:
Note: You can opt-out of a maximum of 2 items below which don't fit into your project, but not more than 2.

	Opening screen with a description of the application and instructions
	Menu for the user to choose options
	At least 4 classes total
	Inheritance (minimum 2 derived classes)
	Polymorphism (Overloading and overriding)
	Encapsulation
	File input and output processing
	Multi-Threading
	Exception handling
	Abstraction

Deliverables

	A video or screenshots of your application in action.
	The project source code files.



*/
#include <iostream>     // Include the input/output stream library
#include <fstream>      // Include the file stream library for file I/O
#include <exception>    // Include the exception handling library
#include "Robot.h"      // Include the header file for the Robot class
#include "WheeledRobot.h"  // Include the header file for the WheeledRobot class
#include "TrackedRobot.h"  // Include the header file for the TrackedRobot class
#include "Grid.h"          // Include the header file for the Grid class

// Function declarations
void displayOpeningScreen();  // Function to display the opening screen
void displayMenu();           // Function to display the main menu
void runSimulation();         // Function to run the simulation
void loadSession();           // Function to load a previous session

int main() {
    // Display the opening screen with instructions
    displayOpeningScreen();

    int choice;  // Variable to store the user's menu choice
    do {
        // Show the menu and get user's choice
        displayMenu();
        std::cin >> choice;  // Read the user's choice

        // Handle user's choice using a switch statement
        switch (choice) {
        case 1:
            runSimulation();  // Start a new simulation
            break;
        case 2:
            loadSession();    // Load a previous session
            break;
        case 3:
            std::cout << "Exiting application. Goodbye!\n";  // Exit message
            break;
        default:
            std::cerr << "Invalid choice. Please try again.\n";  // Error message for invalid input
        }
    } while (choice != 3);  // Continue until the user chooses to exit

    return 0;  // Return 0 to indicate successful execution
}

// Function to display the opening screen with instructions
void displayOpeningScreen() {
    std::cout << "====================================\n";  // Display decorative line
    std::cout << "     Robot Navigation Simulator     \n";  // Display title
    std::cout << "====================================\n";  // Display decorative line
    std::cout << "Welcome to the Robot Navigation Simulator!\n";  // Welcome message
    std::cout << "In this application, you can control a robot\n";  // Brief description
    std::cout << "to navigate through a grid with obstacles.\n";    // Continue description
    std::cout << "Avoid obstacles and reach your goal!\n\n";        // Instructions
    std::cout << "Press Enter to continue...\n";                    // Prompt to continue
    std::cin.ignore();  // Ignore any leftover characters in the input buffer
    std::cin.get();     // Wait for the user to press Enter
}

// Function to display the main menu
void displayMenu() {
    std::cout << "\nMain Menu:\n";                      // Display menu header
    std::cout << "1. Start New Simulation\n";          // Option 1
    std::cout << "2. Load Previous Session\n";         // Option 2
    std::cout << "3. Exit\n";                          // Option 3
    std::cout << "Enter your choice: ";                // Prompt for user input
}

// Function to run the simulation
void runSimulation() {
    try {
        // Create a grid of size 10x10
        Grid grid(10, 10);
        grid.placeObstacles(15);  // Place 15 random obstacles on the grid

        // Let user choose the robot type
        std::cout << "\nChoose Robot Type:\n";               // Prompt for robot type
        std::cout << "1. Wheeled Robot\n";                   // Option 1
        std::cout << "2. Tracked Robot\n";                   // Option 2
        std::cout << "Enter your choice: ";
        int robotChoice;                                     // Variable to store robot choice
        std::cin >> robotChoice;                             // Read robot choice from user

        Robot* robot = nullptr;  // Pointer to a Robot object, initialized to nullptr

        // Instantiate the chosen robot type
        if (robotChoice == 1) {
            robot = new WheeledRobot();  // Create a WheeledRobot object
        }
        else if (robotChoice == 2) {
            robot = new TrackedRobot();  // Create a TrackedRobot object
        }
        else {
            std::cerr << "Invalid robot type selected. Defaulting to Wheeled Robot.\n";  // Error message
            robot = new WheeledRobot();  // Default to WheeledRobot
        }

        // Simulation loop
        char command;  // Variable to store user's move command
        while (true) {
            grid.displayGrid(robot->getX(), robot->getY());  // Display the grid with the robot's position
            std::cout << "Enter command (W/A/S/D to move, Q to quit): ";  // Prompt for move command
            std::cin >> command;  // Read the command from the user

            if (command == 'Q' || command == 'q') {
                break;  // Exit the simulation loop
            }

            robot->move(command);  // Move the robot based on the command

            // Check for collisions with obstacles
            if (grid.isObstacle(robot->getX(), robot->getY())) {
                std::cout << "Collision detected! Simulation over.\n";  // Collision message
                break;  // Exit the simulation loop
            }
        }

        // Save the robot's position to a file
        std::ofstream outFile("session.dat");  // Create an output file stream
        if (!outFile) {
            throw std::ios_base::failure("Failed to open file for writing.");  // Throw exception if file fails to open
        }
        outFile << robot->getX() << ' ' << robot->getY() << '\n';  // Write the robot's position to the file
        outFile.close();  // Close the file

        delete robot;  // Free the dynamically allocated memory
    }
    catch (const std::exception& e) {
        // Handle any exceptions that occurred during the simulation
        std::cerr << "Error: " << e.what() << '\n';  // Display the error message
    }
}

// Function to load a previous session
void loadSession() {
    try {
        std::ifstream inFile("session.dat");  // Create an input file stream
        if (!inFile) {
            throw std::ios_base::failure("Failed to open session file.");  // Throw exception if file fails to open
        }
        int x, y;  // Variables to store the robot's position
        inFile >> x >> y;  // Read the position from the file
        inFile.close();  // Close the file

        std::cout << "Previous session loaded. Robot was at position (" << x << ", " << y << ").\n";  // Display the loaded position
    }
    catch (const std::exception& e) {
        // Handle any exceptions that occurred during loading
        std::cerr << "Error: " << e.what() << '\n';  // Display the error message
    }
}

