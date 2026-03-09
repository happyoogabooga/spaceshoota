#include "trianglecoli.h"
int StructureCollision(structures a, structures b) {

    if (a.hitbox.x < b.hitbox.x + b.hitbox.w &&
        a.hitbox.x + a.hitbox.w > b.hitbox.x &&
        a.hitbox.y < b.hitbox.y + b.hitbox.h &&
        a.hitbox.y + a.hitbox.h > b.hitbox.y)
    {
        //a collision has occured
        return 1;
    }
    //no collision
    return 0;
}