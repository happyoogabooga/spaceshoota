#include "projectiles.h"
void addNode(projectiles_list *plist, projectile *p){
    if(p == NULL){
        return;
    }

    p->next = NULL;

    if(plist->head == NULL){
        plist->head = p;
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
        SDL_DestroyTexture(temp->next->S.flocation);
        temp->next = temp->next->next;
    }
    // If p wasn't found in the list, do nothing
}
//there is a problem here
void displaynode(projectile *p, SDL_Renderer *renderer){
    if(p == NULL || p->S.flocation == NULL) return;
    if(p->D == north){
        SDL_RenderCopyEx(renderer, p->S.flocation,& p->S.structurelookpos,&p->S.hitbox, 270,NULL, 0);
    }
    else{
        SDL_RenderCopyEx(renderer, p->S.flocation,& p->S.structurelookpos,&p->S.hitbox, 90,&(SDL_Point){p->S.hitbox.x, p->S.hitbox.y}, 0);
    }
    //SDL_RenderCopy(renderer, p->S.flocation,&p->S.structurelookpos,&p->S.hitbox);
}

void displaynodes(projectiles_list *p, SDL_Renderer * renderer){
    if(p->head == NULL || p == NULL) return;
    projectile *Node = p->head;
    while(Node != NULL){
        displaynode(Node,renderer);
        Node = Node->next;
    }
}
projectile* createNode(structures S, direction Dir) {
    projectile* p = malloc(sizeof(projectile));

    if (p == NULL) {   // always check malloc
        return NULL;
    }

    p->next = NULL;
    p->S = S;
    p->D = Dir;

    return p;
}

//functionalities/actions section:
void moveprojectiles(projectiles_list *plist, float deltatime){
    if(plist->head == NULL) return;
    printf("%d",plist->head->S.hitbox.y);
    projectile *ptemp = plist->head;
    if(plist == NULL || ptemp == NULL){
        return;
    }
    while(ptemp != NULL){
        //if the bullet is going north
        if(ptemp->D == north){
            //item->hitbox.y += speed * deltatime;
            ptemp->S.hitbox.y -= 400 *deltatime;
        }
        //if the bullet is going south
        else{
            ptemp->S.hitbox.y += 400 *deltatime;
        }
        ptemp = ptemp->next;
    }
}
void ProjectileCollision(projectiles_list *plist, int Screen_width, int Screen_height){
    if(plist == NULL) return;
    projectile *curr = plist->head;
    projectile *prev = NULL;

    while(curr != NULL){

        if(!Projectile_in_screen(Screen_width, Screen_height, curr->S)){
            projectile *temp = curr;

            if(prev == NULL){
                plist->head = curr->next;
                curr = plist->head;
            }
            else{
                prev->next = curr->next;
                curr = curr->next;
            }

            free(temp);
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}