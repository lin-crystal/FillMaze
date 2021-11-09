#include "control.h"
#include "main.h"
#include "init.h"

//define flags
bool flagA = false;
bool flagD = false;
bool flagW = false;
bool flagS = false;

void keyPressed(unsigned char key, int x, int y){
	keyStates[key] = true;
}
void keyUp(unsigned char key, int x, int y){
	keyStates[key] = false;
}

//reset game then start the game
void resetGame(){
	over = false;
	xIncrement = 0;
	yIncrement = 0; 
	rotation = 0;
	for (int i = 0; i < 256; i++){
		keyStates[i] = false;
	}
    initialmap();
}

//left movement
void pressedA(){
    //get current location
    float x = (1.5 + xIncrement) * squareSize;
    float y = (1.5 + yIncrement) * squareSize;
    int indexX = 1.5 + xIncrement;
    int indexY = 1.5 + yIncrement;
    int x1Quadrant = (int)((x - 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
    if(!bitmap.at(x1Quadrant).at((int)y/squareSize)){
        //update: passed blocks are marked with 1 in fillmap
        if(fillmap.at(indexX).at(indexY) == 0){
            fillmap.at(indexX).at(indexY) = 1;
        }
        xIncrement -= 6 / squareSize;
        rotation = 2;
    } else {
        //complete movement
        flagA = false;
    }
}
//right movement
void pressedD(){
    //get current location
    float  x = (1.5 + xIncrement) * squareSize;
    float y = (1.5 + yIncrement) * squareSize;
    int indexX = 1.5 + xIncrement;
    int indexY = 1.5 + yIncrement;
    int x2Quadrant = (int)((x + 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
    if (!bitmap.at(x2Quadrant).at((int)y / squareSize)){
        // update: passed blocks are marked with 1 in fillmap
        if(fillmap.at(indexX).at(indexY) == 0){
            fillmap.at(indexX).at(indexY) = 1;
        }
        xIncrement += 6 / squareSize;
        rotation = 0;
    } else {
        //complete movement
        flagD = false;
    }
}
//up movement
void pressedW(){
    //get current location
    float  x = (1.5 + xIncrement) * squareSize;
    float y = (1.5 + yIncrement) * squareSize;
    int indexX = 1.5 + xIncrement;
    int indexY = 1.5 + yIncrement;
    int y1Quadrant = (int)((y - 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
    if (!bitmap.at((int)x/squareSize).at(y1Quadrant)){
        //update: passed blocks are marked with 1 in fillmap
        if(fillmap.at(indexX).at(indexY) == 0){
            fillmap.at(indexX).at(indexY) = 1;
        }
        yIncrement -= 6 / squareSize;
        rotation = 3;
    } else {
        //complete movement
        flagW = false;
    }
}
//down movement
void pressedS(){
    //get current location
    float  x = (1.5 + xIncrement) * squareSize;
    float y = (1.5 + yIncrement) * squareSize;
    int indexX = 1.5 + xIncrement;
    int indexY = 1.5 + yIncrement;
    int y2Quadrant = (int)((y + 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
    if (!bitmap.at((int)x / squareSize).at(y2Quadrant)){
        //update: passed blocks are marked with 1 in fillmap
        if(fillmap.at(indexX).at(indexY) == 0){
            fillmap.at(indexX).at(indexY) = 1;
        }
        yIncrement += 6 / squareSize;
        rotation = 1;
    } else {
        //complete movement
        flagS = false;
    }

}

//polling the flag and update the flag if key pressed
void keyOperations(){
    if(flagA == true)
    {
        pressedA();
        return;
    } else if(flagD == true) {
        pressedD();
        return;
    } else if(flagW == true) {
        pressedW();
        return;
    } else if(flagS == true) {
        pressedS();
        return;
    }

	if (keyStates['a']){
        flagA = true;
	}
    if (keyStates['d']){
        flagD = true;

    }
    if (keyStates['w']){
        flagW = true;
    }
    if (keyStates['s']){
        flagS = true;
    }
	if (keyStates[' ']){
		if (!replay && over){
			resetGame();
			replay = true;
		}
		else if (replay && over){
			replay = false;
		}
	}
}