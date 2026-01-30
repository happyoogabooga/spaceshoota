#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/structure.h"
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
SDL_Renderer *renderer;
void keyhandler(SDL_Event ev, saucer *player){
    switch(ev.key.keysym.sym){
        case SDLK_SPACE:
        break;
        case SDLK_a:
            player->saucerstructure.hitbox.x -=10;
        break;
        case SDLK_d:
            player->saucerstructure.hitbox.x +=10;
        break;
    }
}
int main(int argc, char** argv)
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_Window* window = SDL_CreateWindow( "SHOOTA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xF1, 0xFF, 0xFF );
    return 0;
}