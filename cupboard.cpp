#include "cupboard.h"

void Cupboard :: drawCupboard() {

	glColor3f(0.6f, 0.6f, 0.6f); // Darker Metallic Silver
	glBegin(GL_QUADS);

    // Back
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 4.5f, -1.5f);
	glVertex3f(1.5, 4.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);

    // Left Side
    glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 4.5f, -1.5f);
	glVertex3f(-1.5, 4.5f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);

    // Right Side
    glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 4.5f, -1.5f);
	glVertex3f(1.5, 4.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);

    // Front
    glVertex3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.5f, 4.5f, 0.5f);
	glVertex3f(1.5, 4.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);

	glColor3f(0.65f, 0.65f, 0.65f); // Chrome Finish
    // Left Support
	glVertex3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.2, 0.5f, -1.5f);
	glVertex3f(-1.2f, 0.0f, -1.5f);

    glVertex3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5, 0.5f, 0.5f);
	glVertex3f(-1.5f, 0.0f, 0.5f);

    glVertex3f(-1.2f, 0.0f, -1.5f);
	glVertex3f(-1.2f, 0.5f, -1.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

    glVertex3f(-1.5f, 0.0f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

    // Right Support
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.0f, -1.5f);

    glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.5f);

    glVertex3f(1.2f, 0.0f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

    glVertex3f(1.5f, 0.0f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

    glEnd();

    //lines
    glColor3f(0.12f, 0.12f, 0.12f);
    glLineWidth(5.0f);
    glBegin(GL_LINES);

    glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(-1.4f, 4.4f, 0.501f);

	glVertex3f(-1.4f, 4.4f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

    glVertex3f(1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

    glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 0.6f, 0.501f);

    //middle line
    glVertex3f(0.0f, 0.6f, 0.501f);
	glVertex3f(0.0f, 4.4f, 0.501f);

    glEnd();

    // Handles
	glColor3f(0.8f, 0.8f, 0.8f); // Chrome Finish
    glPushMatrix();
    glTranslatef( 0.1f, 2.5f, 0.5f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutSolidTorus(0.03f, 0.1f, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( -0.1f, 2.5f, 0.5f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutSolidTorus(0.03f, 0.1f, 100, 100);
    glPopMatrix();
}

