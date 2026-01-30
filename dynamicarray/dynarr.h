#include <stdlib.h>
#include "../headers/saucer.h"
//this is really needed, get it working as soon as possible
struct saucerlist{
    struct saucer *head;
    struct saucer *next;
    //search for player
    bool searchsaucer(saucer *player){
        saucerlist *saucerlist = this;
        saucer *current = head;
        while(current != NULL){
            if(current == player){
                return true;
            };
            current = current->next;
        }
        return false;
    }
}saucerlist;
//this is a dynamic array for saucers