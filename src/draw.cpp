#include "draw.h"
#include "main.h"

//fill block passed with color
void drawPassed(){
    vector<int> initial = {1, 1, 2, 2};
    glColor3f(0.5, 0.6, 0.5);

    //initialization: fill the block in the position where the ball initialized
    for (vector<int>::size_type p = 0; p < initial.size(); p = p + 4) {
        glRectf(initial.at(p) * squareSize, initial.at(p + 1) * squareSize, initial.at(p + 2) * squareSize,
                initial.at(p + 3) * squareSize);
    }

    //if block is marked with 1 in fillmap, fill the block with color
    for (int c = 0; c < fillmap.size(); c = c + 1) {
        for (int r = 0; r < fillmap.at(c).size(); r = r + 1) {
            if (fillmap.at(c).at(r) == 1) {
                glRectf(c * squareSize, r * squareSize, (c + 1) * squareSize, (r + 1) * squareSize);
            }
        }
    }
}