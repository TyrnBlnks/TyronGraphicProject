#define _USE_MATH_DEFINES
#include <iostream>
#include <stb/stb_image.h>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "chair.h"
#include "table.h"
#include "cupboard.h"
#include "window.h"
#include "person.h"
#include "fan.h"
#include "robot.h"
#include "shaderClass.h"
#include "computer.h"
#include "MobileScreen.h"
#include "door.h"


#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;
GLuint textureID_wall, textureID_sb;

void loadTextures() {
	glGenTextures(1, &textureID_wall);
	glBindTexture(GL_TEXTURE_2D, textureID_wall); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char* data = stbi_load("wall_texture.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glEnable(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

// build and compile shader program
// ------------------------------------
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Load and compile shaders here
	vertexFile = "default.vert";
	fragmentFile = "default.frag";
	// Create shader program, attach shaders, and link program
}

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH/2.0);
float halfHeight = (float)(WINDOW_HEIGHT/2.0);
float mouseX = 0.0f, mouseY = 0.0f;

//Fan
Fan f;
Fan f1;
Fan f2;
Fan f3;
Fan f4;

//robot
Robot b;

//Computer instances
Computer computers[4]; 

// Declare a global instance of MobileScreen
MobileScreen mobileScreen;


void interactWithPerson2(){
	char str1[] = "Most of the Desktops at the back dont work.";
	char str2[] = "Yeah, it seems as if theres a power issue";
	int l1 = strlen(str1); // see how many characters are in text string.
	int l2 = strlen(str2); // see how many characters are in text string.
	glPushMatrix();

	glColor3f(1.0f, 0.5f, 0.0f);

	glRasterPos3f(0.5f, 4.0f, -15.0f); // location to start printing text
	for( int i=0; i < l1; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]); // Print a character on the screen
	}
	glPopMatrix();

	glPushMatrix();

	glColor3f(1.0f, 0.8f, 0.0f);

	glRasterPos3f(0.5f, 3.75f, -10.0f); // location to start printing text
	for (int i = 0; i < l2; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]); // Print a character on the screen
	}
	glPopMatrix();
}

void interactWithPerson1() {
	char str1[] = "Welcome ARM Labs, please sign!";
	int l1 = strlen(str1); // see how many characters are in text string.
	glPushMatrix();

	glColor3f(0.95f, 0.0f, 0.0f);

	glRasterPos3f(-9.5f, 2.75f, 10.5f); // location to start printing text
	for (int i = 0; i < l1; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]); // Print a character on the screen
	}
	glPopMatrix();
}

void renderScene(void) {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.5f, z,
		x + lx, 2.5f + ly, z + lz,
		roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glColor3f(0.77f, 0.77f, 0.77f);
	glBegin(GL_QUADS);
	glVertex3f(-25.0f, 0.0f, -25.0f);
	glVertex3f(-25.0f, 0.0f, 25.0f);
	glVertex3f(25.0f, 0.0f, 25.0f);
	glVertex3f(25.0f, 0.0f, -25.0f);
	glEnd();

    //wall
	glColor3f(1.0f, 0.9f, 0.7f);
    // Bind the wall texture
	glBindTexture(GL_TEXTURE_2D, textureID_wall);
	// Draw the wall with texture and texture coordinates
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-20.0f, 7.0f, -20.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(20.0f, 7.0f, -20.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();

	//wall
	glColor3f(1.0f, 0.9f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 7.0f, -20.0f);
	glVertex3f(-20.0f, 7.0f, 20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glEnd();

	//wall with door
	glColor3f(1.0f, 0.9f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(-20.0f, 7.0f, 20.0f);
	glVertex3f(-10.0f, 7.0f, 20.0f);
	glVertex3f(-10.0f, 0.0f, 20.0f);
	glEnd();

	// Draw the first door (left-hinged)
	drawDoor(-8.0f, 0.0f, 20.0f, 3.8f, 4.84f); // Adjusted to fit the space

	// Draw the second door (right-hinged)
	drawDoor(-5.0f, 0.0f, 20.0f, 3.8f, 4.84f); // Adjusted to fit the space


	glColor3f(1.0f, 0.9f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 0.0f, 20.0f);
	glVertex3f(-3.0f, 7.0f, 20.0f);
	glVertex3f(20.0f, 7.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	glColor3f(1.0f, 0.9f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, 20.0f);
	glVertex3f(-10.0f, 5.0f, 20.0f);
	glVertex3f(-3.0f, 5.0f, 20.0f);
	glVertex3f(-3.0f, 7.0f, 20.0f);
	glEnd();

	glColor3f(1.0f, 0.9f, 0.7f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
    glVertex3f(-10.0f, 5.0f, 20.01f);
	glVertex3f(-3.0f, 5.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
    glVertex3f(-10.0f, 5.0f, 20.01f);
	glVertex3f(-10.0f, 0.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
    glVertex3f(-3.0f, 0.0f, 20.01f);
	glVertex3f(-3.0f, 5.0f, 20.01f);
	glEnd();

	//wall
	glColor3f(1.0f, 0.9f, 0.7f);
	glBindTexture(GL_TEXTURE_2D, textureID_wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(20.0f, 7.0f, -20.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(20.0f, 7.0f, 20.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	//ceiling
	glColor3f(0.965f, 0.965f, 0.965f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 7.0f, -20.0f);
	glVertex3f(20.0f, 7.0f, -20.0f);
	glVertex3f(20.0f, 7.0f, 20.0f);
	glVertex3f(-20.0f, 7.0f, 20.0f);
	glEnd();

	mobileScreen.draw(); // Add this line to render the mobile screen

	// Draw lecturer's chair
	Chair profChair;
	glPushMatrix();
	glTranslatef( -16.0f, 1.0f, 5.0f);
	glScalef(0.35f, 0.35f, 0.25f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	profChair.drawChair();
	glPopMatrix();

	// Draw lecturer's table
	Table profTable;
	glPushMatrix();
	glTranslatef( -15.0f, 1.4f, 5.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	profTable.drawTable();
	glPopMatrix();

	// Draw student chairs
	Chair studentChair[4][4];
	for (int i = -1; i <= 5; i+=2){
		for (int j = -1; j <= 2; j+=2) {
			glPushMatrix();
			glTranslatef(i * 4.0 + -7.00f, 0.8f, j * 10.0 + 2.2f);
			glScalef(0.35f, 0.35f, 0.25f);
			glRotatef(270.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student tables
	Table studentTable[4][4];
	for (int i = -1; i <= 5; i+=2){
		for (int j = -1; j <= 2; j+=2) {
			glPushMatrix();
			glTranslatef(i*4.0 + -8.00f, 1.2f, j * 10.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.8f);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			studentTable[i][j].drawTable();
			glPopMatrix();
		}
	}

	//Draw computers on desks
	for (int i = -1; i <= 5; i += 2) {
		for (int j = -1; j <= 2; j += 2) {
			glPushMatrix();
			// Position computers on the desks in front of the chairs
			glTranslatef(i * 4.0 + -8.00f, 1.2f, j * 10.0 + 1.2f); // Adjust Y to sit on desk
			glRotatef(90.0, 0.0, 1.0, 0.0); // Rotate 90 degrees to show the side
			computers[(i + 1) / 2 * 2 + (j + 1) / 2].drawComputer();
			glPopMatrix();

			glPushMatrix();
			// Position towers on the desks next to the computers
			glTranslatef(i * 4.0 + -8.00f, 1.2f, j * 10.0 + 1.2f); // Adjust Y to sit on desk
			glRotatef(90.0, 0.0, 1.0, 0.0); // Rotate 90 degrees to show the side
			computers[(i + 1) / 2 * 2 + (j + 1) / 2].drawTower(); // Draw the tower next to the PC
			glPopMatrix();
		}
	}

	// Draw cupboard
	Cupboard cupboard;
	glPushMatrix();
	glTranslatef(-18.40f, 0.0f, 16.00f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	cupboard.drawCupboard();
	glPopMatrix();

	// Draw cupboard
	Cupboard cupboard1;
	glPushMatrix();
	glTranslatef(-18.40f, 0.0f, 12.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	cupboard1.drawCupboard();
	glPopMatrix();

	// Draw cupboard
	Cupboard cupboard2;
	glPushMatrix();
	glTranslatef(-18.40f, 0.0f, -16.00f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	cupboard2.drawCupboard();
	glPopMatrix();

	// Draw cupboard
	Cupboard cupboard3;
	glPushMatrix();
	glTranslatef(-18.40f, 0.0f, -12.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	cupboard3.drawCupboard();
	glPopMatrix();

	// Draw blackboard
	glColor3f(0.75f, 0.75f, 0.75f);
	glBegin(GL_QUADS);
	glVertex3f(-19.99f, 2.0f, -6.0f);
	glVertex3f(-19.99f, 5.5f, -6.0f);
	glVertex3f(-19.99f, 5.5f, 6.0f);
	glVertex3f(-19.99f, 2.0f, 6.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, textureID_sb);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-19.986f, 2.2f, -5.8f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-19.986f, 5.3f, -5.8f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-19.986f, 5.3f, 5.8f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-19.986f, 2.2f, 5.8f);
	glEnd();

	//Floor pattern
	glColor3f(0.4f, 0.4f, 0.4f);
	glLineWidth(3.0f);
	for(int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f + i, 0.001f, -20.01f);
		glVertex3f(-20.0f + i, 0.001f, 20.01f);
		glEnd();
	}
	for(int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f, 0.001f, -20.01f + i);
		glVertex3f(20.0f, 0.001f, -20.01f + i);
		glEnd();
	}

	//windows
	Window w;
	w.drawWindow1();
	w.drawWindow2();
	w.drawWindow3();
	w.drawWindow4();
	w.drawWindow5();
	w.drawWindow6();
	//w.drawWindowSill();
	glPushMatrix();
	glTranslatef(-10.0f, -1.0f, -22.5f);
	glScalef(3.0f, 1.5f, 2.5f);
    glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, 1.0f, -22.5f);
	glScalef(3.0f, 1.5f, 2.5f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, -1.0f, -9.5f);
	glScalef(3.0f, 1.5f, 2.5f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, 1.0f, -9.5f);
	glScalef(3.0f, 1.5f, 2.5f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, -1.0f, 3.5f);
	glScalef(3.0f, 1.5f, 2.5f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, 1.0f, 3.5f);
	glScalef(3.0f, 1.5f, 2.5f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	w.drawWindowSill();
	glPopMatrix();

	
	//Draw Person
	Person a;
	glPushMatrix();
	glTranslatef(4.0f, 2.0f, -11.0);
	a.drawPerson(1.0f, 0.5f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5f, 2.0f, -9.5);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	a.drawPerson(0.7f, 0.7f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.5f, 2.0f, 16.5);
	glRotatef(-120.0, 0.0, 1.0, 0.0);
	a.drawPerson(0.0f, 0.7f, 0.0f);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-10.0f, 2.0f, 10.5);
	glRotatef(30.0, 0.0, 1.0, 0.0);
	a.drawPerson(0.7f, 0.0f, 0.0f);
	glPopMatrix();
	
	/*
	glPushMatrix();
	glTranslatef(4.0f, 1.95f, -9.5);
	glScalef(0.4f, 0.4f, 0.4f);
	glRotatef(-140.0, 0.0, 1.0, 0.0);
	b.drawRobot();
	glPopMatrix(); */

	if (x < -5.0 && x > -15.0 && z < 25.0 && z > 10.0) {
		interactWithPerson1();
	}

	if ( x < 7.0 && x > 4.0 && z < -2.0 && z > -10.0) {
		interactWithPerson2();
	}


	//Fans
	glPushMatrix();
	glTranslatef(0.0f, 7.0f, 0.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f.drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, 7.0f, 10.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f1.drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0f, 7.0f, -10.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f2.drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0f, 7.0f, 10.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f3.drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0f, 7.0f, -10.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f4.drawFan();
	glPopMatrix();

	if(abs(mouseX) > 0.3){
		angle -= (0.004f * mouseX);
		lx = sin(angle);
		lz = -cos(angle);
	}
	if(abs(mouseY) > 0.3){
		if(abs(yAngle) < (M_PI/2)){
			yAngle += (0.002f * mouseY);
		}
		ly = sin(yAngle);
	}

	glutSwapBuffers();
}

// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

void toggleComputerPower(int index) {
	if (index >= 0 && index < 4) {
		computers[index].togglePower();
	}
}



// Handles the events triggered when any key on the keyboard is pressed.
//Specifically, handles w,a,s,d and Esc.
// moves the camera forward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy) {
	float fraction = 0.1f;

	if (key == 'w') {
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a') {
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's') {
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd') {
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x') {
		roll += 0.5f;
	}
	else if (key == 'z') {
		roll -= 0.5f;
	}
	else if (key == '1') {
		toggleComputerPower(0); // Toggle power for the first computer
	}
	else if (key == '2') {
		toggleComputerPower(1); // Toggle power for the second computer
	}
	else if (key == '3') {
		toggleComputerPower(2); // Toggle power for the third computer
	}
	else if (key == '4') {
		toggleComputerPower(3); // Toggle power for the fourth computer
	}
	else if (key == 'm') {
		mobileScreen.togglePower(); // Toggle power for the mobile screen
	}
	else if (key == 27) { // ESC key
		exit(0);
	}
}



 // Handles the events triggered when the mouse is moved in the window area. 
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy){

	mouseX = (float)(halfWidth - xx)/halfWidth;
	mouseY = (float)(halfHeight - yy)/halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if(abs(yAngle) < (M_PI/2)){
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}

 // Adjusts the viewport sie when the window size is changed and sets the projection.
 // @param w : new width of window
 // @param h : new height of window
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w/2.0);
	halfHeight = (float)(h/2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate () {
    f.rotateFan();
	f1.rotateFan();
	f2.rotateFan();
	f3.rotateFan();
	f4.rotateFan();

	b.rotateRobot();

    /* refresh screen */
    glutPostRedisplay();
}

int main(int argc, char **argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");

	// register callbacks
	glutDisplayFunc(renderScene);
	//loadTextures();
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	
	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}