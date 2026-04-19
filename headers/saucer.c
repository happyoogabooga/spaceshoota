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
    return new;
}
//idea, i could have a global list or projectiles,
//and basically make each each suacer be able to generate a new
//projectile, projectiles can either go north to south or south to north
//so make a global list of two types of projectiles and increment/decrement them
//with respect to time each frame
int stutter = 0;
void shoot(saucer sc, bool shoot, projectiles_list *plist, float deltatime, SDL_Renderer * renderer){
    if(sc.Type == player){
        //if i am shooting then add another projectile to the screen starting where
        //the saucer is and put it in the global list=
        if(shoot && stutter <= 0){
        addNode (plist,createNode(makestructure((SDL_Rect){sc.saucerstructure.hitbox.x, sc.saucerstructure.hitbox.y - 30, 32,32},
            (SDL_Rect){0,64,16,16},"C:/Users/brubr/projects/cprojects/spaceshoota/sprites/spaceships.png", renderer),north));
            stutter += 20;
        }
        if(stutter >= 0)stutter--;
        moveprojectiles(plist, deltatime);
    }
    else{
        if(shoot && stutter <= 0){
            printf("%d\n%d", sc.Type, player);
            addNode (plist,createNode(makestructure((SDL_Rect){sc.saucerstructure.hitbox.x, sc.saucerstructure.hitbox.y +100, 32,32},
            (SDL_Rect){0,64,16,16},"C:/Users/brubr/projects/cprojects/spaceshoota/sprites/spaceships.png", renderer),south));
            stutter += 20;
        }
        moveprojectiles(plist, deltatime);
        if(stutter >= 0)stutter--;
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