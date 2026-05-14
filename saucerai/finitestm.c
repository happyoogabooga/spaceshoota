#include "finitestm.h"
void movetowards(structures *main_character,structures *enemy, float deltatime){
    //if my chacter is lower than my enemy
    if(main_character->hitbox.x == enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy, 200.0, deltatime,false, true, false, false);
    }
    //if my character is higher than my enemy
    if(main_character->hitbox.x == enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 200.0, deltatime, true, false, false, false);
    }
    //if my character is to the right of my enemy, and my character is lower than my enemy
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy,200.0,deltatime, false, true, false, true);
    }
    //if mt character is to the right of my enemy and my character is higher than my enemy
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 200.0, deltatime,true, false, false,true);
    }
    //if my character is to the left of my enemy and my character is lower than my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy, 200.0, deltatime,false,true,true, false);
    }
    //if my character is to the left of my enemy and my character is higher than my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 200.0, deltatime, true, false, true, false);
    }
    //if my character is to the right of my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y == enemy->hitbox.y){
        move(enemy, 200.0, deltatime, false, false, true, false);
    }
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y == enemy->hitbox.y){
        move(enemy, 200.0, deltatime, false, false, false, true);
    }
}
void runaway(structures * main_character, structures *enemy, float deltatime){
    //if my chacter is lower than my enemy
    if(main_character->hitbox.x == enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy, 100.0, deltatime,true, false, false, false);
    }
    //if my character is higher than my enemy
    if(main_character->hitbox.x == enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 100.0, deltatime, false, true, false, false);
    }
    //if my character is to the right of my enemy, and my character is lower than my enemy
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy, 100.0,deltatime, true, false, true, false);
    }
    //if mt character is to the right of my enemy and my character is higher than my enemy
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 100.0, deltatime,false, true, true,false);
    }
    //if my character is to the left of my enemy and my character is lower than my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y > enemy->hitbox.y){
        move(enemy, 100.0, deltatime,true,false,false, true);
    }
    //if my character is to the left of my enemy and my character is higher than my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y < enemy->hitbox.y){
        move(enemy, 100.0, deltatime, false, true, false, true);
    }
    //if my character is to the right of my enemy
    if(main_character->hitbox.x < enemy->hitbox.x && main_character->hitbox.y == enemy->hitbox.y){
        move(enemy, 100.0, deltatime, false, false, false, true);
    }
    if(main_character->hitbox.x > enemy->hitbox.x && main_character->hitbox.y == enemy->hitbox.y){
        move(enemy, 100.0, deltatime, false, false, true, false);
    }
}
void attack(saucer *main_character, saucer *enemy, projectiles_list * plist, SDL_Renderer *renderer, float deltatime){
    shoot(enemy, true, plist, deltatime, renderer);
}