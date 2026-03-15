#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "structure.h"
#include "trianglecoli.h"
//functionality for both a single projectile and multiple projectiles
#ifndef PROJECTILES_H
#define PROJECTILES_H
//if north then the projectile is headed north
//if south it is going south
typedef enum{
    north, south
}direction;
typedef struct projectile{
    structures S;
    direction D;
    struct projectile * next;
}projectile;
 
typedef struct projectiles_list{
    projectile *head;
}projectiles_list;
//add and remove functionality
//these can be unordered
void addNode(projectiles_list *plist, projectile *p);
void deleteNode(projectiles_list *plist, projectile *p );
void displaynodes(projectiles_list *p, SDL_Renderer *renderer);
void displaynode(projectile *p, SDL_Renderer *renderer);
projectile* createNode(structures S, direction Dir);



void moveprojectiles(projectiles_list *plist,float deltatime);
void ProjectileCollision(projectiles_list *plist, int Screen_width, int Screen_height);
#endif