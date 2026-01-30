#include <SDL2/SDL.h>
#ifndef structure_h
#define structure_h
typedef struct structures{
    //this is where it is displayed when we play
    SDL_Rect hitbox;
    //this is where to look in the spritesheet for the sprite
    SDL_Rect structurelookpos;
    //this is the file location which will be used in rendering the structure
    const char* flocation;
}structures;
#endif