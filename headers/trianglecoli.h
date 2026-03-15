#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "structure.h"

#ifndef TRIANGLECOLI_H
#define TRIANGLECOLI_H
int StructureCollision(structures player, structures opposition);
int Projectile_in_screen(int screenwidth, int screenheight, structures projectile);
#endif