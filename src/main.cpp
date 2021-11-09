#include "main.h"
#include "control.h"
#include "draw.h"
#include "gameresult.h"
#include "gameover.h"
#include "gamestart.h"
#include "init.h"
#include "ball.h"
#include "laberynth.h"
using namespace std;

bool replay = false;
bool over = true;
float squareSize = 100.0;
float xIncrement = 0;
float yIncrement = 0;
int rotation = 0;
vector<int> border = {0, 0, 6, 1, 6, 6, 5, 1, 0, 5, 5, 6, 1, 5, 0, 1}; //coordinate of the wall
vector<int> obstaclesTop = {1, 4, 2, 5, 2, 2, 3, 3, 3, 2, 4, 4}; //coordinate of the obstacle
vector<vector<bool>> bitmap; //2d vector for storing obstacle (obstacle = T, path = F)
vector<vector<int>> fillmap; //2d vector for storing wall, not filled, filled (wall = -1, not filled = 0, filled = 1)
bool* keyStates = new bool[256];

//main method
int main(int argc, char** argv){
    //initialization and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Fill Maze Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);

    //run the game
    init();
    glutMainLoop();
    return 0;
}
