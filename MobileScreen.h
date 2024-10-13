#ifndef MOBILESCREEN_H
#define MOBILESCREEN_H

class MobileScreen {
public:
    MobileScreen(); // Constructor
    void draw();    // Method to draw the screen
    void togglePower(); // Method to toggle the power state
    void setPower(bool powerState); // Method to set the power state explicitly

private:
    bool isOn; // State of the screen (on/off)
};

#endif // MOBILESCREEN_H
