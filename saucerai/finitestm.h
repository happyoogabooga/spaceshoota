#include "../headers/movestruct.h"
#ifndef FINITESTM_H
#define FINITESTM_H
void statehandler(structures *main_character, structures * enemy, int deltatime);
void movetowards(structures *main_character,structures *enemy, float deltatime);
void runaway(structures *main_character, structures *enemy, float deltatime);
#endif