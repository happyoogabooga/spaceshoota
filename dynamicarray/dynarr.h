#include <stdlib.h>
#include "../headers/saucer.h"
#include <stdio.h>
#ifndef DYNARR_H
#define DYNARR_H
//this is really needed, get it working as soon as possible
typedef struct linkedlist{
    saucer* head;
    //need to do cleanup with this
}linkedlist;
void addnode(int index, saucer *n, linkedlist *l);
void push_back(saucer * n, linkedlist *l);
void removenode(saucer *n, linkedlist *l);
void displayitems(linkedlist *l, SDL_Renderer * renderer);
void collision_n(projectiles_list *plist, linkedlist *l);
void checkhealth(linkedlist *l);
#endif
//define movement before collision
//display the saucer to the screen before you define movement 