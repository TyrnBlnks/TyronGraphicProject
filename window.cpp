#include "window.h" 

void Window :: drawWindow1(){
//Window 1
glColor3f(0.6f, 0.7333f, 1.0f);
glBegin(GL_QUADS);
glVertex3f(-17.0f, 2.0f, -19.99f);
glVertex3f(-17.0f, 6.0f, -19.99f);
glVertex3f(-13.0f, 6.0f, -19.99f);
glVertex3f(-13.0f, 2.0f, -19.99f);
glEnd();

glColor3f(0.149f, 0.149f, 0.149f);
glLineWidth(10.0f);
glBegin(GL_LINES);
//left
glVertex3f(-17.0f, 2.0f, -19.98f);
glVertex3f(-17.0f, 6.0f, -19.98f);
//top
glVertex3f(-17.0f, 6.0f, -19.98f);
glVertex3f(-13.0f, 6.0f, -19.98f);
//right
glVertex3f(-13.0f, 2.0f, -19.98f);
glVertex3f(-13.0f, 6.0f, -19.98f);
//bottom
glVertex3f(-17.0f, 2.0f, -19.98f);
glVertex3f(-13.0f, 2.0f, -19.98f);
glEnd();

//Cross
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex3f(-15.0f, 2.0f, -19.98f);
glVertex3f(-15.0f, 6.0f, -19.98f);
glEnd();
}

void Window :: drawWindow2(){
//Window 2
glColor3f(0.6f, 0.7333f, 1.0f);
glBegin(GL_QUADS);
glVertex3f(-11.0f, 2.0f, -19.99f);
glVertex3f(-11.0f, 6.0f, -19.99f);
glVertex3f(-7.0f, 6.0f, -19.99f);
glVertex3f(-7.0f, 2.0f, -19.99f);
glEnd();

glColor3f(0.149f, 0.149f, 0.149f);
glLineWidth(10.0f);
glBegin(GL_LINES);
//left
glVertex3f(-11.0f, 2.0f, -19.98f);
glVertex3f(-11.0f, 6.0f, -19.98f);
//top
glVertex3f(-11.0f, 6.0f, -19.98f);
glVertex3f(-7.0f, 6.0f, -19.98f);
//right
glVertex3f(-7.0f, 2.0f, -19.98f);
glVertex3f(-7.0f, 6.0f, -19.98f);
//bottom
glVertex3f(-11.0f, 2.0f, -19.98f);
glVertex3f(-7.0f, 2.0f, -19.98f);
glEnd();

//Cross
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex3f(-9.0f, 2.0f, -19.98f);
glVertex3f(-9.0f, 6.0f, -19.98f);
glEnd();
}

void Window::drawWindow3() {
	//Window 3
	glColor3f(0.6f, 0.7333f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f, 2.0f, -19.99f);
	glVertex3f(-5.0f, 6.0f, -19.99f);
	glVertex3f(-1.0f, 6.0f, -19.99f);
	glVertex3f(-1.0f, 2.0f, -19.99f);
	glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	//left
	glVertex3f(-5.0f, 2.0f, -19.98f);
	glVertex3f(-5.0f, 6.0f, -19.98f);
	//top
	glVertex3f(-5.0f, 6.0f, -19.98f);
	glVertex3f(-1.0f, 6.0f, -19.98f);
	//right
	glVertex3f(-1.0f, 2.0f, -19.98f);
	glVertex3f(-1.0f, 6.0f, -19.98f);
	//bottom
	glVertex3f(-5.0f, 2.0f, -19.98f);
	glVertex3f(-1.0f, 2.0f, -19.98f);
	glEnd();

	//Cross
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex3f(-3.0f, 2.0f, -19.98f);
	glVertex3f(-3.0f, 6.0f, -19.98f);
	glEnd();
}

void Window::drawWindow4() {
	//Window 4
	glColor3f(0.6f, 0.7333f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0f, 2.0f, -19.99f);
	glVertex3f(1.0f, 6.0f, -19.99f);
	glVertex3f(5.0f, 6.0f, -19.99f);
	glVertex3f(5.0f, 2.0f, -19.99f);
	glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	//left
	glVertex3f(1.0f, 2.0f, -19.98f);
	glVertex3f(1.0f, 6.0f, -19.98f);
	//top
	glVertex3f(1.0f, 6.0f, -19.98f);
	glVertex3f(5.0f, 6.0f, -19.98f);
	//right
	glVertex3f(5.0f, 2.0f, -19.98f);
	glVertex3f(5.0f, 6.0f, -19.98f);
	//bottom
	glVertex3f(1.0f, 2.0f, -19.98f);
	glVertex3f(5.0f, 2.0f, -19.98f);
	glEnd();

	//Cross
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex3f(3.0f, 2.0f, -19.98f);
	glVertex3f(3.0f, 6.0f, -19.98f);
	glEnd();
}

void Window::drawWindow5() {
	//Window 5
	glColor3f(0.6f, 0.7333f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(7.0f, 2.0f, -19.99f);
	glVertex3f(7.0f, 6.0f, -19.99f);
	glVertex3f(11.0f, 6.0f, -19.99f);
	glVertex3f(11.0f, 2.0f, -19.99f);
	glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	//left
	glVertex3f(7.0f, 2.0f, -19.98f);
	glVertex3f(7.0f, 6.0f, -19.98f);
	//top
	glVertex3f(7.0f, 6.0f, -19.98f);
	glVertex3f(11.0f, 6.0f, -19.98f);
	//right
	glVertex3f(11.0f, 2.0f, -19.98f);
	glVertex3f(11.0f, 6.0f, -19.98f);
	//bottom
	glVertex3f(7.0f, 2.0f, -19.98f);
	glVertex3f(11.0f, 2.0f, -19.98f);
	glEnd();

	//Cross
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex3f(9.0f, 2.0f, -19.98f);
	glVertex3f(9.0f, 6.0f, -19.98f);
	glEnd();
}

void Window::drawWindow6() {
	//Window 6
	glColor3f(0.6f, 0.7333f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(13.0f, 2.0f, -19.99f);
	glVertex3f(13.0f, 6.0f, -19.99f);
	glVertex3f(17.0f, 6.0f, -19.99f);
	glVertex3f(17.0f, 2.0f, -19.99f);
	glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	//left
	glVertex3f(13.0f, 2.0f, -19.98f);
	glVertex3f(13.0f, 6.0f, -19.98f);
	//top
	glVertex3f(13.0f, 6.0f, -19.98f);
	glVertex3f(17.0f, 6.0f, -19.98f);
	//right
	glVertex3f(17.0f, 2.0f, -19.98f);
	glVertex3f(17.0f, 6.0f, -19.98f);
	//bottom
	glVertex3f(13.0f, 2.0f, -19.98f);
	glVertex3f(17.0f, 2.0f, -19.98f);
	glEnd();

	//Cross
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex3f(15.0f, 2.0f, -19.98f);
	glVertex3f(15.0f, 6.0f, -19.98f);
	glEnd();
}

void Window :: drawWindowSill(){
glColor3f(0.8f, 0.8f, 0.8f);
glBegin(GL_QUADS);
glVertex3f(-9.99f, 2.0f, -6.0f);
glVertex3f(-9.99f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -6.0f);

glColor3f(0.2f, 0.2f, 0.2f);
glVertex3f(-9.5f, 2.0f, -6.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 1.8f, -2.0f);
glVertex3f(-9.5f, 1.8f, -6.0f);

glColor3f(0.1f, 0.1f, 0.1f);
glVertex3f(-9.99f, 2.0f, -6.0f);
glVertex3f(-9.5f, 2.0f, -6.0f);
glVertex3f(-9.5f, 1.8f, -6.0f);
glVertex3f(-9.99f, 1.8f, -6.0f);

glColor3f(0.2f, 0.2f, 0.2f);
glVertex3f(-9.99f, 2.0f, -2.0f);
glVertex3f(-9.5f, 2.0f, -2.0f);
glVertex3f(-9.5f, 1.8f, -2.0f);
glVertex3f(-9.99f, 1.8f, -2.0f);

glEnd();
}


