#include "dynarr.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//this is really needed, get it working as soon as possible

void addnode(int index, saucer *n, linkedlist *l) {
    if (!l || !n || index < 0) return;

    if (index == 0) {
        n->next = l->head;
        l->head = n;
        return;
    }

    saucer *curr = l->head;
    for (int i = 0; i < index - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) return; // index out of range

    n->next = curr->next;
    curr->next = n;
}
void push_back(saucer * n, linkedlist *l){
    if(l->head == NULL){
    l->head = n;
    return;
    }

    n->next = NULL;
    
    saucer * curr = l->head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = n;
}
void removenode(saucer *n, linkedlist *l) {
    if (!l || !l->head || !n) return;

    // case 1: removing head
    if (l->head == n) {
        l->head = l->head->next;
        // deallocate the saucer
        if (n->saucerstructure.flocation) {
            SDL_DestroyTexture(n->saucerstructure.flocation);
        }
        free(n);
        return;
    }

    saucer *curr = l->head;

    while (curr->next != NULL && curr->next != n) {
        curr = curr->next;
    }

    // saucer not found
    if (curr->next == NULL) return;

    // unlink saucer
    curr->next = curr->next->next;
    // deallocate the saucer
    if (n->saucerstructure.flocation) {
        SDL_DestroyTexture(n->saucerstructure.flocation);
    }
    free(n);
}
//hope this is good 
void displayitems(linkedlist *l, SDL_Renderer * renderer){
    saucer *H = l->head;
    while(H != NULL){
        display(H, renderer);
        H = H->next;
    }
}
//I might not always want to do things this way, I might in stead for example want to
//decrement the health of my saucer instead of instantly deleting it, then have a checkhealth function
///that deletes the node it its health is next
void collision_n(projectiles_list *plist, linkedlist *l){
    saucer *H = l->head;
    saucer *prev = NULL;
    while(H != NULL){
        saucer *next = H->next;
        if(collision(plist, H) == 1){
            prev = H;
            H->health--;
            if(H->health <= 0){
                removenode(H, l);
            }
            H = next;
            continue;
        }
        H = H->next;
    }
}