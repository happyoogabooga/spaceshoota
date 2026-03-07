#include <stdlib.h>
#include "../headers/saucer.h"
#include <stdio.h>
//this is really needed, get it working as soon as possible
typedef struct linkedlist{
    saucer* head;
    //need to do cleanup with this
}linkedlist;
void addnode(int index, saucer *n, linkedlist *l);
void push_back(saucer * n, linkedlist *l);
void removenode(saucer *n, linkedlist *l);
void displayitems(linkedlist *l, SDL_Renderer * renderer);
//define movement before collision
//display the saucer to the screen before you define movement 