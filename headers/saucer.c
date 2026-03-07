#include "saucer.h"
#include "trianglecoli.h"
#include "structure.h"
//SDL_Renderer might just be temporary
//maybe make this an integer that returns false if not displayed dunno
void display(saucer *S, SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, IMG_LoadTexture(renderer, S->saucerstructure.flocation), &S->saucerstructure.structurelookpos, &S->saucerstructure.hitbox);
}