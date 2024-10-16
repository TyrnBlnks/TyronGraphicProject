#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include "door.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawDoor(float x, float y, float z, float width, float height) {
    // Door color (dark blue)
    glColor3f(0.1f, 0.1f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(x - width / 2, y, z);
    glVertex3f(x + width / 2, y, z);
    glVertex3f(x + width / 2, y + height, z);
    glVertex3f(x - width / 2, y + height, z);
    glEnd();

    // Draw door handle
    glColor3f(0.8f, 0.5f, 0.2f); // Brown color for handle
    glBegin(GL_QUADS);
    glVertex3f(x - 0.1f, y + height / 2 - 0.2f, z + 0.02f); // Slightly offset z
    glVertex3f(x + 0.1f, y + height / 2 - 0.2f, z + 0.02f);
    glVertex3f(x + 0.1f, y + height / 2 + 0.2f, z + 0.02f);
    glVertex3f(x - 0.1f, y + height / 2 + 0.2f, z + 0.02f);
    glEnd();

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw transparent glass circle
    glColor4f(0.5f, 0.5f, 0.5f, 0.3f); // Light gray with transparency
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * M_PI / 180.0f;
        float cx = x + 0.5f * cos(theta);
        float cy = y + height / 2 + 0.5f * sin(theta);
        glVertex3f(cx, cy, z + 0.02f); // Slightly offset z
    }
    glEnd();

    // Disable blending after drawing
    glDisable(GL_BLEND);
}

