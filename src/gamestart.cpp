#include "gamestart.h"
#include "ball.h"
#include "laberynth.h"
#include "main.h"
#include "gameover.h"
#include "draw.h"
#include "gameresult.h"
#include "control.h"

//display welcome screen when game starts
void welcomeScreen(){
	glClearColor(0.8, 0.8, 0.8, 1.0);
    string message = "********************************";
	string::iterator it = message.begin();
	glRasterPos2f(60, 75);
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "Fill Maze Game";
	glColor3f(0.3, 0.4, 0.3);
	glRasterPos2f(190, 120);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "********************************";
	glRasterPos2f(60, 175);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "A: go right   D: go left   W: go up   S: go down";
	glRasterPos2f(68, 230);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	message = "To start or restart the game, press Space";
	glRasterPos2f(93, 273);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}

//display welcome screen, game screen, result screen based on game logic
void display(){
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);
	gameOver();
	if (replay){
		if (!over){
			drawLaberynth();
            drawPassed();
            drawBall(1.5 + xIncrement, 1.5 + yIncrement, rotation);
		}
		else {
			resultsDisplay();
		}
	}
	else {
		welcomeScreen();
	}
	glutSwapBuffers();
}

void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 600, 600, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
