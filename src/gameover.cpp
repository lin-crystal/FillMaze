#include "gameover.h"
#include "main.h"

//game is over if all blocks are filled
void gameOver(){
    //check if there is no block marked with 0 in fillmap
    for (int c = 0; c < fillmap.size(); c = c + 1) {
        for (int r = 0; r < fillmap.at(c).size(); r = r + 1) {
            if (fillmap.at(c).at(r) == 0) {
                return;
            }
        }
    }
    over = true;
}
