#include <SDL.h>
#include <stdio.h>
#include "board.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main(int argc, char *argv[]){

    //SDL Init Failure
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    //Create Window Variable
    SDL_Window *win = SDL_CreateWindow(
            "Chess Game",//window name
            SDL_WINDOWPOS_CENTERED,//xpos
            SDL_WINDOWPOS_CENTERED,//ypos
            SCREEN_WIDTH,//width
            SCREEN_HEIGHT,//height
            SDL_WINDOW_SHOWN//show window after creating
    );
    //Failed to create window err
    if(win==NULL){
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Failed to create renderer err
    if(renderer==NULL){
        printf("SDL_Renderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    //Main loop flag
    int quit = 0;
    //Event object
    SDL_Event e;

    //While app running
    while(!quit){

        //Handle events on queue
        while(SDL_PollEvent(&e)!=0){
            if(e.type == SDL_QUIT){
                quit = 1;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        //Draw game board
        drawGameBoard(renderer);

        //Update screen
        SDL_RenderPresent(renderer);
    }

    //Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
