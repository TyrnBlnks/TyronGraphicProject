#ifndef COMPUTER_H
#define COMPUTER_H 

class Computer {
public:
    bool isOn; // A variable to track if the computer is on or off

    // Constructor to initialize the computer's state
    Computer() : isOn(false) {}

    // Method to draw the computer
    void drawComputer();

    // Method to toggle the computer's power state
    void togglePower();

    // Method to draw the computer tower
    void drawTower(); // Add this line
};

#endif // COMPUTER_H
