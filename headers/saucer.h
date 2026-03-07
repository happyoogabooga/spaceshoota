#include "structure.h"
//this is a simple project, make that one space atari game
//before doing this work on the traingle col function and perfect it
//main character class
//depending on the type of saucer, display a different saucer
enum typeofsaucer{
    long_range, short_range, medium_range, mini_boss
}typeofsaucer;
typedef struct saucer{
    enum typeofsaucer Type;
    structures saucerstructure;
    structures projectile;
    struct saucer *next;
}saucer;
void display(saucer* S, SDL_Renderer * renderer);