#include <GL/glut.h>
#include "MobileScreen.h"

MobileScreen::MobileScreen() : isOn(false) {}

void MobileScreen::draw() {
    // Draw the border
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the border
    glTranslatef(-10.0f, 3.0f, 0.0f); // Position the border
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotate to face the class
    glScalef(3.1f, 2.1f, 0.1f); // Slightly larger than the screen
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the screen
    glPushMatrix();
    if (isOn) {
        glColor3f(0.0f, 0.5f, 1.0f); // Blue color for the screen when on
    }
    else {
        glColor3f(0.1f, 0.1f, 0.1f); // Dark gray color for the screen when off
    }
    glTranslatef(-10.0f, 3.0f, 0.0f); // Position the screen
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotate to face the class
    glScalef(3.0f, 2.0f, 0.1f); // Size of the screen
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the "down T" stand
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color for the stand
    glTranslatef(-10.0f, 1.0f, 0.0f); // Position the stand
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotate to match the screen's orientation
    // Vertical part of the "T"
    glPushMatrix();
    glScalef(0.1f, 2.0f, 0.1f); // Size of the vertical part
    glutSolidCube(1.0);
    glPopMatrix();
    // Horizontal part of the "T" at the bottom
    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f); // Position the horizontal part at the bottom
    glScalef(3.0f, 0.1f, 0.1f); // Make the horizontal part as wide as the screen
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
}

void MobileScreen::togglePower() {
    isOn = !isOn; // Toggle the power state
}

void MobileScreen::setPower(bool powerState) {
    isOn = powerState; // Set the power state explicitly
}
