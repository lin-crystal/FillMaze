#include "laberynth.h"
#include "main.h"

//draw maze
void drawLaberynth(){
	glColor3f(0.4, 0.4, 0.4);

    //draw wall
	for (vector<int>::size_type i = 0; i < border.size(); i = i + 4){
		glRectf(border.at(i) * squareSize, border.at(i + 1)*squareSize, border.at(i + 2)*squareSize, border.at(i + 3)*squareSize);
	}

    //draw obstacle
	for (vector<int>::size_type p = 0; p < obstaclesTop.size(); p = p + 4){
		glRectf(obstaclesTop.at(p) * squareSize, obstaclesTop.at(p + 1)*squareSize, obstaclesTop.at(p + 2)*squareSize, obstaclesTop.at(p + 3)*squareSize);
	}
}