#include "person.h"

void Person :: drawPerson(float red, float green, float blue) {
    //glColor3f(0.0f, 0.0f, 0.5f);
    glColor3f(red, green, blue);

    // Draw Body (Cube-like)
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.65f, 0.75f, 0.4f);
    glutSolidCube(1.5f);  // Draw a cube for the body
    glPopMatrix();

    // Draw Head
    glPushMatrix();
    glColor3f(0.8f, 0.6f, 0.4f);
    glTranslatef(0.0f, 0.85f, 0.0f);
    glutSolidSphere(0.275f, 20, 20);  // Head remains a sphere
    glPopMatrix();

    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to black for eyes
    glTranslatef(0.1f, 1.0f, 0.2f);
    glutSolidSphere(0.05f, 10, 10);  // Right eye
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);  // Left eye
    glPopMatrix();

    // Draw Nose
    glColor3f(0.9f, 0.6f, 0.4f);   // Set color to red for the nose
    glPushMatrix();
    glTranslatef(0.0f, 0.85f, 0.25f);
    glutSolidCone(0.075f, 0.1f, 10, 2);
    glPopMatrix();

    // Draw Arms (Rectangles)
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown or peach skin tone
    glPushMatrix();
    glTranslatef(0.75f, 0.09f, 0.0f);
    glRotatef(190.0f, 0.0f, 0.0f, 1.0f);  // Rotate the arm
    glScalef(0.25f, 1.0f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Right arm
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.75f, 0.09f, 0.0f);
    glRotatef(170.0f, 0.0f, 0.0f, 1.0f);  // Rotate the arm
    glScalef(0.25f, 1.0f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Left arm
    glPopMatrix();

    // Draw Legs (Rectangles)
    glColor3f(0.0f, 0.1f, 0.3f);
    glPushMatrix();
    glTranslatef(0.3f, -1.2f, 0.0f);
    glScalef(0.25f, 1.35f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Right leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, -1.2f, 0.0f);
    glScalef(0.25f, 1.35f, 0.25f);  // Scale to create a rectangle
    glutSolidCube(1.0f);  // Left leg
    glPopMatrix();

}


