#include "saucer.h"
//SDL_Renderer might just be temporary
//maybe make this an integer that returns false if not displayed dunno
void display(saucer *S, SDL_Renderer *renderer){
    if (!S->saucerstructure.flocation) {
        SDL_Log("failed to load texture '%s': %s", S->saucerstructure.flocation, SDL_GetError());
        return;
    }
    if(S->Type == player){
        SDL_RenderCopyEx(renderer, S->saucerstructure.flocation, &S->saucerstructure.structurelookpos, &S->saucerstructure.hitbox,0, NULL, SDL_FLIP_NONE);
    }
    else{
        SDL_RenderCopyEx(renderer, S->saucerstructure.flocation, &S->saucerstructure.structurelookpos, &S->saucerstructure.hitbox,180, NULL, SDL_FLIP_NONE);
    }
}

saucer* createsaucer(structures S, struct saucer *next, int SaucerType){
    saucer *new = malloc(sizeof(saucer));
    if (!new) return NULL;
    new->Type = player;
    new->saucerstructure = S;
    new->next = next;
    new->Type = SaucerType;
    new->health = 10;
    new->ammunition = 100;
    return new;
}

void shoot(saucer *sc, bool shoot, projectiles_list *plist, float deltatime, SDL_Renderer * renderer){
    if(sc->Type == player){
        //if my ammo is greater than 0, then shoot, if not do not shoot
        if(shoot && sc->ammunition > 0){
        addNode (plist,createNode(makestructure((SDL_Rect){sc->saucerstructure.hitbox.x, sc->saucerstructure.hitbox.y - 30, 32,32},
            (SDL_Rect){0,64,16,16},"sprites/spaceships.png", renderer),north));
        addNode (plist,createNode(makestructure((SDL_Rect){sc->saucerstructure.hitbox.x + 96, sc->saucerstructure.hitbox.y - 30, 32,32},
            (SDL_Rect){0,64,16,16},"sprites/spaceships.png", renderer),north));
            sc->ammunition-=11;
        }
        if(sc->ammunition <= 100)sc->ammunition++;
        moveprojectiles(plist, deltatime);
    }
    else{
        if(shoot && sc->ammunition > 0){
            addNode (plist,createNode(makestructure((SDL_Rect){sc->saucerstructure.hitbox.x, sc->saucerstructure.hitbox.y +100, 32,32},
            (SDL_Rect){16,64,16,16},"sprites/spaceships.png", renderer),south));
            sc->ammunition-=11;
        }
        if(sc->ammunition <= 100)sc->ammunition++;
        moveprojectiles(plist, deltatime);
    }
}
int collision(projectiles_list *plist , saucer *S){
    int T_F = 0; //if there is no collision with the saucer return 0, if there is a collision return 1
    projectile *p = plist->head;
    projectile *prev = NULL;
    //fix this
    while(p != NULL){
        projectile *next = p->next;  // save next BEFORE possible deletion
        if(StructureCollision(p->S, S->saucerstructure) == 1){
            //save the next node
            //save the previous node in prev
            //delete the privious node,
            //continue back up to the top, by setting p = next
            prev = p;
            T_F = 1;
            deleteNode(plist,prev);
            p = next;
            continue;
        } 
        p = next;  // move forward safely
    }
    return T_F;
}