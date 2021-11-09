#include "gameresult.h"
#include "main.h"

//display result screen when game ends
void resultsDisplay(){
	if (over == true){
        glClearColor(0.8, 0.8, 0.8, 1.0);
        string message = "********************************";
        string::iterator it = message.begin();
        glRasterPos2f(60, 75);
        while (it!=message.end())
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
        message = "CONGRATULATIONS, YOU WON!";
        glColor3f(0.3, 0.4, 0.3);
        glRasterPos2f(68, 120);
        it = message.begin();
        while (it!=message.end())
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
        message = "********************************";
        glRasterPos2f(60, 175);
        it = message.begin();
        while (it!=message.end())
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
        message = "To start or restart the game, press Space";
        glRasterPos2f(93, 250);
        it = message.begin();
        while (it!=message.end())
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}
}