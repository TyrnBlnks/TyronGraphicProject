#include <GL/glut.h> // Include OpenGL Utility Toolkit
#include "computer.h" // Include the Computer class header

void Computer::drawComputer() {
    // Draw the monitor frame (border)
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray color for the frame
    glTranslatef(0.0f, 1.0f, 0.0f);
    glScalef(1.4f, 0.8f, 0.1f); // Slightly larger than the screen to create a border
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the screen
    glPushMatrix();
    if (isOn) {
        glColor3f(0.0f, 1.0f, 0.0f); // Green color for the screen when on
    }
    else {
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for the screen when off
    }
    glTranslatef(0.0f, 1.0f, 0.05f);
    glScalef(1.3f, 0.7f, 0.01f); // Keep the screen size as is
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the base
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray color for the base
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(0.5f, 0.1f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Computer::drawTower() {
    // Draw the tower
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color for the tower
    glTranslatef(-1.0f, 0.8f, 0.0f); // Position the tower to the left of the PC
    glScalef(0.3f, 1.0f, 0.5f); // Increase the scaling factors for a bulkier tower
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the light on the tower
    glPushMatrix();
    if (isOn) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red color when the computer is on
    }
    else {
        glColor3f(0.2f, 0.2f, 0.2f); // Same as tower color when off
    }
    glTranslatef(-1.10f, 1.15f, 0.24f); // Adjust Z to 0.24f to bring the light closer to the tower
    glutSolidSphere(0.020, 20, 20); // Decrease the sphere radius to 0.025 for a smaller light
    glPopMatrix();
}




void Computer::togglePower() {
    isOn = !isOn; // Toggle the power state
}

