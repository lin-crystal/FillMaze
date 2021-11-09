#ifndef _MAIN_H_
#define _MAIN_H_
#include <vector>
#include <GLUT/glut.h>
#include <iostream>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <deque>
#include <stdlib.h>
using namespace std;

extern bool replay;
extern bool over;
extern float squareSize;
extern float xIncrement;
extern float yIncrement;
extern int rotation;
extern vector<int> border;
extern vector<int> obstaclesTop;
extern vector<vector<bool>> bitmap;
extern vector<vector<int>> fillmap;
extern bool* keyStates; 

#endif