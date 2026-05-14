#include "structure.h"
#include "trianglecoli.h"
#include "projectiles.h"
#include <stdbool.h>
#ifndef SAUCER_H
#define SAUCER_H
//this is a simple project, make that one space atari game
//before doing this work on the traingle col function and perfect it
//main character class
//depending on the type of saucer, display a different saucer
typedef enum {
    long_range, short_range, medium_range, mini_boss, player
} typeofsaucer;

typedef enum states{
    idle_s, movetowards_s, runaway_s, attack_s, passive_s
} states;

typedef struct saucer{
    int ammunition; //this is how much ammo you have, can grow and shrink in size;
    int health; //this is how much healt you have, once again can grow and shrink in size
    states state; //This is what you are currently doing, are you attacking or passive for example.
    typeofsaucer Type; //this is what you are
    structures saucerstructure;
    struct saucer *next;
}saucer;
void display(saucer* S, SDL_Renderer * renderer);
saucer* createsaucer(structures S, struct saucer *next, int SaucerType);
void shoot(saucer *sc, bool shoot, projectiles_list *plist, float deltatime, SDL_Renderer * renderer);
int collision(projectiles_list *plist , saucer *S);
#endif