//this must be minimal, and superimposed over everything
#include "../headers/structure.h"
#include <stdlib.h>
#ifndef HUD_H
#define HUD_H
structures* makeheart(int x, int y, SDL_Renderer *renderer);
void displayhearts(int health, SDL_Renderer *renderer);
void displayammo(int ammocount, SDL_Renderer *renderer);
void displayhud(int health, int ammocount, SDL_Renderer *renderer);
#endif