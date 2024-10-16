# include "table.h"

void Table :: drawTable() {

	// glTranslatef(0.0f, 0.0f, -14.0f);


	glBegin(GL_QUADS);

	//Front
	//
	glColor3f(1.0f, 0.95f, 0.9f); // Cream White
	glVertex3f(-4.0f, 1.0f, 2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(2.0f, 0.5f, 2.0f);
	glVertex3f(-4.0f, 0.5f, 2.0f);

	//Back
	//;
	glVertex3f(-4.0f, 1.0f, -2.0f);
	glVertex3f(-4.0f, 0.5f, -2.0f);
	glVertex3f(2.0f, 0.5f, -2.0f);
	glVertex3f(2.0f, 1.0f, -2.0f);

	//Right
	//
	glVertex3f(2.0f, 1.0f, -2.0f);
	glVertex3f(2.0f, 0.5f, -2.0f);
	glVertex3f(2.0f, 0.5f, 2.0f);
	glVertex3f(2.0f, 1.0f, 2.0f);


	//Left
	;
	glVertex3f(-4.0f, 1.0f, -2.0f);
	glVertex3f(-4.0f, 1.0f, 2.0f);
	glVertex3f(-4.0f, 0.5f, 2.0f);
	glVertex3f(-4.0f, 0.5f, -2.0f);

	//top
	glColor3f(0.4f, 0.2f, 0.0f); // Dark Wood Varnish
	glVertex3f(2.0f, 0.5f, 2.0f);
	glVertex3f(-4.0f, 0.5f, 2.0f);
	glVertex3f(-4.0f, 0.5f, -2.0f);
	glVertex3f(2.0f, 0.5f, -2.0f);

	//bottom
	glVertex3f(2.0f, 1.0f, 2.0f);
	glVertex3f(-4.0f, 1.0f, 2.0f);
	glVertex3f(-4.0f, 1.0f, -2.0f);
	glVertex3f(2.0f, 1.0f, -2.0f);

	//table front leg
	//front
	//
	glColor3f(0.0f, 0.0f, 0.0f); // Black
	glVertex3f(1.8f, 1.0f, 1.6f);
	glVertex3f(1.4f, 1.0f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(1.8f, 1.0f, 1.2f);
	glVertex3f(1.4f, 1.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glVertex3f(1.8f, 1.0f, 1.6f);
	glVertex3f(1.8f, 1.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glVertex3f(1.4f, 1.0f, 1.6f);
	glVertex3f(1.4f, 1.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;
	glVertex3f(1.8f, 1.0f, -1.2f);
	glVertex3f(1.4f, 1.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glVertex3f(1.8f, 1.0f, -1.6f);
	glVertex3f(1.4f, 1.0f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glVertex3f(1.8f, 1.0f, -1.6f);
	glVertex3f(1.8f, 1.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glVertex3f(1.4f, 1.0f, -1.6f);
	glVertex3f(1.4f, 1.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	
	glVertex3f(-3.8f, 1.0f, 1.6f);
	glVertex3f(-3.4f, 1.0f, 1.6f);
	glVertex3f(-3.4f, -3.0f, 1.6f);
	glVertex3f(-3.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(-3.8f, 1.0f, 1.2f);
	glVertex3f(-3.4f, 1.0f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.2f);

	//right


	glVertex3f(-3.8f, 1.0f, 1.6f);
	glVertex3f(-3.8f, 1.0f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.6f);

	//left
	;

	glVertex3f(-3.4f, 1.0f, 1.6f);
	glVertex3f(-3.4f, 1.0f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;
	//glColor3f(1,1,1);
	glVertex3f(-3.8f, 1.0f, -1.2f);
	glVertex3f(-3.4f, 1.0f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.2f);

	//back
	;

	glVertex3f(-3.8f, 1.0f, -1.6f);
	glVertex3f(-3.4f, 1.0f, -1.6f);
	glVertex3f(-3.4f, -3.0f, -1.6f);
	glVertex3f(-3.8f, -3.0f, -1.6f);

	//right


	glVertex3f(-3.8f, 1.0f, -1.6f);
	glVertex3f(-3.8f, 1.0f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-3.4f, 1.0f, -1.6f);
	glVertex3f(-3.4f, 1.0f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.6f);



	glEnd();
}
