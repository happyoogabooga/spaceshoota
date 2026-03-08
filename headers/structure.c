#include "structure.h"
structures makestructure(SDL_Rect hitbox, SDL_Rect structurelookpos, const char* flocation, structures *next){
    structures new;
    new.hitbox = hitbox;
    new.structurelookpos = structurelookpos;
    new.flocation = flocation;
    new.next = next;
    return new;
}