#include "structure.h"
structures makestructure(SDL_Rect hitbox, SDL_Rect structurelookpos, const char* flocation, SDL_Renderer * renderer){
    structures new;
    new.hitbox = hitbox;
    new.structurelookpos = structurelookpos;
    new.flocation = IMG_LoadTexture(renderer, flocation);
    return new;
}