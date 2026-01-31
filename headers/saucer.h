#include "structure.h"
void attack(saucer *player);
//this is a simple project, make that one space atari game
//before doing this work on the traingle col function and perfect it
//main character class
typedef struct saucer{
    structures saucerstructure;
    structures projectile;
    void attack(saucer *player);
    saucer *next;
}saucer;