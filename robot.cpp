#include "robot.h"

void Robot::drawRobot() {

    // Draw Body (Cube-like)
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.65f, 0.75f, 0.35f);
    glutSolidCube(1.5f);  // Draw a cube for the body
    glPopMatrix();

    // Draw Head

    glPushMatrix();
    glColor3f(1.0f, 0.8f, 0.0f);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glScalef(0.45f, 0.45f, 0.45f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to black for eyes
    glTranslatef(0.1f, 0.8f, 0.2f);
    glutSolidSphere(0.05f, 10, 10);  // Right eye
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);  // Left eye
    glPopMatrix();

    // Draw Arms (Rectangles)

    glColor3f(1.0f, 0.8f, 0.0f);
    /*glPushMatrix();
    glTranslatef(0.65f, 0.4f, 0.35f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);  // Rotate the arm
    glScalef(0.25f, 1.0f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Right arm
    glPopMatrix();*/

    glPushMatrix();
    glTranslatef(-0.65f, 0.4f, 0.35f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);  // Rotate the arm
    glScalef(0.25f, 1.0f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Left arm
    glPopMatrix();

    // Draw Legs (Rectangles)
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.3f, -0.7f, 0.55f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.25f, 1.35f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Right leg
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.3f, -0.7f, 0.55f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.25f, 1.35f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Left leg
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.65f, 0.4f, 0.0f);
    glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glColor3f(1.0f, 0.8f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.35f); // Translate to the desired position
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);// Rotate around the x-axis
    glScalef(0.25f, 1.0f, 0.25f);
    glutSolidCube(1.0f); // Create a rectangular arm
    glPopMatrix();

    glPopMatrix();
}

void Robot::rotateRobot()
{
    rotationAngle += 0.25f;
}