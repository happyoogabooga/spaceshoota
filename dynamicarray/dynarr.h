#include <stdlib.h>
#include "../headers/saucer.h"
//this is really needed, get it working as soon as possible
struct saucerlist{
    struct saucer *head;
    saucer* searchsaucer(saucer *player){
        saucer *dummy = head;
        while(dummy != NULL){
            if(dummy == player){
                return dummy;
            }
            dummy = dummy->next;
        }
        return NULL;
    }
    //need to do cleanup with this
    void removesaucer(saucer *player){
        saucer *dummy = head;
        while(dummy->next  != player || dummy->next != NULL){
            dummy = dummy->next;
        }
        if(dummy->next == player){
            dummy->next = dummy->next->next;
        }
    }
    void addsaucer(saucer *player){
        saucer *dummy = head;
        while(dummy->next != NULL)dummy = dummy->next;
        dummy->next = player;
    }
}saucerlist;
//this is a dynamic array for saucers