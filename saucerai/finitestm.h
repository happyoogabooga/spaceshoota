#include "../headers/movestruct.h"
#include "../headers/saucer.h"
#include "../headers/projectiles.h"
#ifndef FINITESTM_H
#define FINITESTM_H
void statehandler(structures *main_character, structures * enemy, int deltatime);
void movetowards(structures *main_character,structures *enemy, float deltatime);
void runaway(structures *main_character, structures *enemy, float deltatime);
void attack(saucer *main_character, saucer *enemy,projectiles_list * plist, SDL_Renderer *renderer, float deltatime);
#endif