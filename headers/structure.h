#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#ifndef structure_h
#define structure_h
#define true 1
#define false 0
typedef struct structures{
    //this is where it is displayed when we play
    SDL_Rect hitbox;
    //this is where to look in the spritesheet for the sprite
    SDL_Rect structurelookpos;
    //this is the file location which will be used in rendering the structure
    SDL_Texture *flocation;
}structures;
//every single displayable thing in this game will have its hitbox in here
typedef struct listofstructures{
    structures * head;    
} listofstructures;
structures makestructure(SDL_Rect hitbox, SDL_Rect structurelookpos, const char* flocation, SDL_Renderer * renderer);
#endif