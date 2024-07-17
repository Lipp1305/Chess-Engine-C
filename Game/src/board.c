#include "board.h"

void drawGameBoard(SDL_Renderer *renderer){

    //Total width in pixels
    const int SCREEN_WIDTH = 800;
    //Width in squares
    const int BOARD_SIZE = 8;
    //Evenly draw squares along width
    int square_size = SCREEN_WIDTH / BOARD_SIZE;

    //create square object 
    //used like a stamp, same object but positions and colors move
    //then gets drawn
    SDL_Rect square;
    square.w = square_size;
    square.h = square_size;

    //loop through each square drawing appropreate space
    for(int row = 0; row < BOARD_SIZE; ++row){
        for(int col = 0; col < BOARD_SIZE; ++col){
            //position square
            square.x = col * square_size; //move n pixels to the right col times
            square.y = row * square_size; //move m pixels down row times

            //color based on pos
            if((row + col) % 2 == 0){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
            }else{
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //black
            }
            SDL_RenderFillRect(renderer, &square);
        }
    }
}

