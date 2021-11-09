#include "init.h"
#include "main.h"

//game initialization
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	for (int i = 0; i < 256; i++){
		keyStates[i] = false;
	}

	//set 2d vector "bitmap" for storing obstacle (obstacle = T, path = F): column based, from left to right up to down
	bitmap.push_back({true, true, true, true, true, true});
	bitmap.push_back({true, false, false, false, true, true});
	bitmap.push_back({true, false, true, false, false, true});
	bitmap.push_back({true, false, true, true, false, true});
	bitmap.push_back({true, false, false, false, false, true});
    bitmap.push_back({true, true, true, true, true, true});
    initialmap();
}

//2d vector "tempmap" and "fillmap" for storing wall, not filled, filled (wall = -1, not filled = 0, filled = 1)
void initialmap(){
    vector<vector<int>> tempmap;
    tempmap.push_back({-1, -1, -1, -1, -1, -1});
    tempmap.push_back({-1, 0, 0, 0, -1, -1});
    tempmap.push_back({-1, 0, -1, 0, 0, -1});
    tempmap.push_back({-1, 0, -1, -1, 0, -1});
    tempmap.push_back({-1, 0, 0, 0, 0, -1});
    tempmap.push_back({-1, -1, -1, -1, -1, -1});
    fillmap = tempmap;
}