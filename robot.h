#ifndef ROBOT_H
#define ROBOT_H

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <math.h>

#define DEF_D 5

class Robot {
private:
    float rotationAngle = 0.0f;

public:
    void drawRobot();
    void rotateRobot();
};

#endif