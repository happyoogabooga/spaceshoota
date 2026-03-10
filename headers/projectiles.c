#include "projectiles.h"
void addNode(projectiles_list *plist, projectile *p){
    if(plist->head == NULL){
        plist->head = p;
    }
    if(p == NULL){
        return;
    }
    projectile *ptemp = plist->head;
    while(ptemp->next != NULL){
        ptemp = ptemp->next;
    }
    ptemp->next = p;
}
//if the node to be deleted is head then restructure, and make head equal to next;
void deleteNode(projectiles_list *plist, projectile *p){
    if (p == NULL) {
        return; // Nothing to delete
    }
    
    // Special case: deleting the head node
    if (plist->head == p) {
        plist->head = plist->head->next;
        return;
    }
    
    // Find the node before the one to delete
    projectile *temp = plist->head;
    while (temp->next != NULL && temp->next != p) {
        temp = temp->next;
    }
    
    // If we found the node to delete
    if (temp->next == p) {
        temp->next = temp->next->next;
    }
    // If p wasn't found in the list, do nothing
}

void displaynode(projectile *p, SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, IMG_LoadTexture(renderer, p->S.flocation),&p->S.structurelookpos ,&p->S.hitbox);
}

void displaynodes(projectiles_list *p, SDL_Renderer * renderer){
    projectile *Node = p->head;
    while(Node != NULL){
        display(Node,renderer);
        Node = Node->next;
    }
}
projectile* createNode(structures S, direction Dir){
    projectile *p;
    p->next == NULL;
    p->S;
    p->D = Dir;
    return p;
}
//obviously i can add a speed parameter to this later
void moveprojectiles(projectiles_list *plist, int deltatime){
    projectile *ptemp = plist->head;
    if(plist == NULL || ptemp == NULL){
        return;
    }
    while(ptemp != NULL){
        //if the bullet is going north
        if(ptemp->D == north){
            //item->hitbox.y += speed * deltatime;
            ptemp->S.hitbox.y -= 50 *deltatime;

        }
        //if the bullet is going south
        else{
            ptemp->S.hitbox.y += 50 * deltatime;
        }
    }
}