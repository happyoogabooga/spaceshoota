#include "saucer.h"
//SDL_Renderer might just be temporary
//maybe make this an integer that returns false if not displayed dunno
void display(saucer *S, SDL_Renderer *renderer){
    if (!S->saucerstructure.flocation) {
        SDL_Log("failed to load texture '%s': %s", S->saucerstructure.flocation, SDL_GetError());
        return;
    }
    SDL_RenderCopy(renderer, S->saucerstructure.flocation, &S->saucerstructure.structurelookpos, &S->saucerstructure.hitbox);
}

saucer* createsaucer(structures S, struct saucer *next, int SaucerType){
    printf("hi");
    saucer *new = malloc(sizeof(saucer));
    if (!new) return NULL;
    new->Type = player;
    new->saucerstructure = S;
    new->next = next;
    new->Type = SaucerType;
    return new;
}
//idea, i could have a global list or projectiles,
//and basically make each each suacer be able to generate a new
//projectile, projectiles can either go north to south or south to north
//so make a global list of two types of projectiles and increment/decrement them
//with respect to time each frame
void shoot(saucer sc, bool shoot, projectiles_list *plist, float deltatime, SDL_Renderer * renderer){
    if(sc.Type != player){
        //if i am shooting then add another projectile to the screen starting where
        //the saucer is and put it in the global list
        if(shoot){
        addNode (plist,createNode(makestructure((SDL_Rect){sc.saucerstructure.hitbox.x, sc.saucerstructure.hitbox.y, 32,32},
            (SDL_Rect){0,64,16,16},"C:/Users/brubr/projects/cprojects/spaceshoota/sprites/spaceships.png", renderer),north));
        }
        moveprojectiles(plist, deltatime);
    }
    else{
        if(shoot){
            addNode (plist,createNode(makestructure((SDL_Rect){sc.saucerstructure.hitbox.x, sc.saucerstructure.hitbox.y, 32,32},
            (SDL_Rect){0,64,16,16},"C:/Users/brubr/projects/cprojects/spaceshoota/sprites/spaceships.png", renderer),south));
        }
        moveprojectiles(plist, deltatime);
    }
}