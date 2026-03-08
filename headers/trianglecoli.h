#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "structure.h"

#ifndef TRIANGLECOLI_H
#define TRIANGLECOLI_H

float heronstheorem(float a, float b, float c);
float specradius(int px, int py,int obx,int oby);
//this function takes a singular rectangle and return true if some other rectangle collides with it.
int StructureCollision(structures player, structures opposition);
#endif