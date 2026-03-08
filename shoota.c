#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dynamicarray/dynarr.h"
#include "headers/trianglecoli.h"
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
SDL_Renderer *renderer;
int main(int argc, char** argv)
{
    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init(IMG_INIT_PNG);            // initialize SDL_image for PNG support
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_Window* window = SDL_CreateWindow( "SHOOTA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xF1, 0xFF, 0xFF );

    saucer *player = createsaucer(makestructure((SDL_Rect){100, 100, 128, 128},(SDL_Rect){0, 0, 64, 64}, "C:/Users/Owner/projects/cprojects/spaceshoota/sprites/spaceships.png", NULL), NULL);
    linkedlist *saucerlist = malloc(sizeof(linkedlist));
    saucer *newsauc = createsaucer(makestructure((SDL_Rect){300, 300, 128, 128},(SDL_Rect){0, 0, 64, 64}, "C:/Users/Owner/projects/cprojects/spaceshoota/sprites/spaceships.png", NULL), NULL);
    saucerlist->head = NULL;
    push_back(player, saucerlist);   // first node is assigned, pointer->next will be cleared by push_back
    push_back(newsauc, saucerlist);
    //this is just for testing purposes, make sure to clean up the code and make it more efficient
    while(true){
        SDL_RenderClear(renderer);
        displayitems(saucerlist, renderer);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderPresent(renderer);
    }
    return 0;
}