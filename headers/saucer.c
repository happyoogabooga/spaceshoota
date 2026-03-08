#include <stdlib.h>
#include "saucer.h"
#include "trianglecoli.h"
#include "structure.h"
//SDL_Renderer might just be temporary
//maybe make this an integer that returns false if not displayed dunno
void display(saucer *S, SDL_Renderer *renderer){
    SDL_Texture *tex = IMG_LoadTexture(renderer, S->saucerstructure.flocation);
    if (!tex) {
        SDL_Log("failed to load texture '%s': %s", S->saucerstructure.flocation, SDL_GetError());
        return;
    }
    SDL_RenderCopy(renderer, tex, &S->saucerstructure.structurelookpos, &S->saucerstructure.hitbox);
    SDL_DestroyTexture(tex);
}

saucer* createsaucer(structures S, struct saucer *next){
    saucer *new = malloc(sizeof(saucer));
    if (!new) return NULL;
    new->Type = long_range;
    new->saucerstructure = S;
    new->projectile = S;
    new->next = next;
    return new;
}