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
int Projectile_in_screen(int screenwidth, int screenheight, structures projectile){
    //if the projectile is in the screen
    if(projectile.hitbox.y + projectile.hitbox.h > 0 &&
        projectile.hitbox.y < screenheight &&
        projectile.hitbox.x < screenwidth &&
        projectile.hitbox.x + projectile.hitbox.w > 0 
    ) return 1; //we are in the screen

    //if the projectile is out of the screen
    return 0;
}