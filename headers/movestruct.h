#include "structure.h"
#include <stdbool.h>
#ifndef MOVESTRUCT_H
#define MOVESTRUCT_H
//to make this as generic as possible, it will move BUT
//this will not handle collision, that will be handled later.
//velocity = displacement / time
//for this to work i need speed direction and time, so i need a keyhandler,
static inline void move(structures *item, float speed, float deltatime, bool up, bool down, bool left, bool right){
    // deltatime is already in seconds (converted in main loop)
    //this is where the movement will be handled, it will be based on the direction and speed
    //for example, if the direction is up, the y coordinate will be decreased by the speed multiplied by the time
    //if the direction is down, the y coordinate will be increased by the speed multiplied by the time
    //if the direction is left, the x coordinate will be decreased by the speed multiplied by the time
    //if the direction is right, the x coordinate will be increased by the speed multiplied by the time
    if (up) {
        item->hitbox.y -= speed * deltatime;
    }
    if (down) {
        item->hitbox.y += speed * deltatime;
    }
    if (left) {
        item->hitbox.x -= speed * deltatime;
    }
    if (right) {
        item->hitbox.x += speed * deltatime;
    }
}
#endif