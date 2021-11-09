#include "ball.h"
#include <GLUT/glut.h>
#include "main.h"

//draw the ball with radius = 80 and degree = 400
void drawBall(float positionX, float positionY, float rotation){
	int x, y;
	glBegin(GL_LINES); //start drawing
	glColor3f(1.0, 1.0, 0.0);
	for (int k = 0; k < 80; k++){
		x = (float)k / 2.0 * cos((30) * M_PI / 180.0) + (positionX*squareSize);
		y = (float)k / 2.0 * sin((30) * M_PI / 180.0) + (positionY*squareSize);
		for (int i = 0; i < 400; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos((i) * M_PI / 180.0) + (positionX*squareSize);
			y = (float)k / 2.0* sin((i) * M_PI / 180.0) + (positionY*squareSize);
			glVertex2f(x, y);
		}
	}
	glEnd(); //end drawing
}