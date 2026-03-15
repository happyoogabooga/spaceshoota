#include "structure.h"
#include "trianglecoli.h"
#include "projectiles.h"
#include <stdbool.h>
//this is a simple project, make that one space atari game
//before doing this work on the traingle col function and perfect it
//main character class
//depending on the type of saucer, display a different saucer
typedef enum {
    long_range, short_range, medium_range, mini_boss, player
} typeofsaucer;
typedef struct saucer{
    typeofsaucer Type;
    structures saucerstructure;
    struct saucer *next;
}saucer;
void display(saucer* S, SDL_Renderer * renderer);
saucer* createsaucer(structures S, struct saucer *next, int SaucerType);
void shoot(saucer sc, bool shoot, projectiles_list *plist, float deltatime, SDL_Renderer * renderer);