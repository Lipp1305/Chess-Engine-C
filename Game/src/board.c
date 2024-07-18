#include "board.h"

const int SCREEN_WIDTH = 800;
const int BOARD_SIZE = 8;
int square_size = SCREEN_WIDTH / BOARD_SIZE;





//draw the game board once
void drawGameBoard(SDL_Renderer *renderer){

    SDL_Rect square;
    square.w = square_size;
    square.h = square_size;

    for(int row = 0; row < BOARD_SIZE; ++row){
        for(int col = 0; col < BOARD_SIZE; ++col){
            square.x = col * square_size; //move n pixels to the right col times
            square.y = row * square_size; //move m pixels down row times

            //color based on pos
            if((row + col) % 2 == 0){
                SDL_SetRenderDrawColor(renderer, 100, 50, 0, 255); //white
            }else{
                SDL_SetRenderDrawColor(renderer, 255, 150, 100, 255); //black
            }
            SDL_RenderFillRect(renderer, &square);
        }
    }
}
//Draw pieces on top?


