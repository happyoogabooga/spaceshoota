#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "structure.h"
#define true 1;
#define false 0;

#ifndef trianglecoli_h
#define trianglecoli_h
//****** this should probably go in the class */
typedef struct triangles{
    SDL_Vertex base1;
    SDL_Vertex base2;
    SDL_Vertex height;
}triangle;
float heronstheorem(float a, float b, float c){
    float s = 1/2 * (a + b + c);
    return sqrt(s * (s-a) * (s-b) * (s-c));
}
float specradius(int px, int py,int obx,int oby){
    return sqrt(((obx-px)*(obx-px))+((oby-py)*(oby-py)));
}
//this function takes a singular rectangle and return true if some other rectangle collides with it.
int StructureCollision(structures player, structures opposition){
    //get the lines and then get the subareas, after that compare them to the area of S
    //to make this algorithm more efficient, check which point is the closest first and then make the check

    //these are my lines drawn from the upper left of a rectangle to the vertices of another
    float p11 = specradius(player.hitbox.x, player.hitbox.y, opposition.hitbox.x, opposition.hitbox.y);
    float p12 = specradius(player.hitbox.x, player.hitbox.y, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y);
    float p13 = specradius(player.hitbox.x, player.hitbox.y, opposition.hitbox.x, opposition.hitbox.y + opposition.hitbox.h);
    float p14 = specradius(player.hitbox.x, player.hitbox.y, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y + opposition.hitbox.h);
    //this code gets the relevant sub area relative to a vertice in player
    float p1subarea = heronstheorem(p11, p12, opposition.hitbox.w)+ 
    heronstheorem(p11, p13, opposition.hitbox.h)+
    heronstheorem(p12, p14, opposition.hitbox.h)+
    heronstheorem(p13, p14, opposition.hitbox.w);
    
    //these are my lines drawn from the upper left of a rectangle to the vertices of another
    float p11 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y, opposition.hitbox.x, opposition.hitbox.y);
    float p12 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y);
    float p13 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y, opposition.hitbox.x, opposition.hitbox.y + opposition.hitbox.h);
    float p14 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y + opposition.hitbox.h);
    //this code gets the relevant sub area relative to a vertice in player
    float p2subarea = heronstheorem(p11, p12, opposition.hitbox.w)+ 
    heronstheorem(p11, p13, opposition.hitbox.h)+
    heronstheorem(p12, p14, opposition.hitbox.h)+
    heronstheorem(p13, p14, opposition.hitbox.w);

    //these are my lines drawn from the upper left of a rectangle to the vertices of another
    float p11 = specradius(player.hitbox.x, player.hitbox.y + player.hitbox.h, opposition.hitbox.x, opposition.hitbox.y);
    float p12 = specradius(player.hitbox.x, player.hitbox.y + player.hitbox.h, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y);
    float p13 = specradius(player.hitbox.x, player.hitbox.y + player.hitbox.h, opposition.hitbox.x, opposition.hitbox.y + opposition.hitbox.h);
    float p14 = specradius(player.hitbox.x, player.hitbox.y + player.hitbox.h, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y + opposition.hitbox.h);
    //this code gets the relevant sub area relative to a vertice in player
    float p3subarea = heronstheorem(p11, p12, opposition.hitbox.w)+ 
    heronstheorem(p11, p13, opposition.hitbox.h)+
    heronstheorem(p12, p14, opposition.hitbox.h)+
    heronstheorem(p13, p14, opposition.hitbox.w);

    //these are my lines drawn from the upper left of a rectangle to the vertices of another
    float p11 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y + player.hitbox.h, opposition.hitbox.x, opposition.hitbox.y);
    float p12 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y + player.hitbox.h, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y);
    float p13 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y + player.hitbox.h, opposition.hitbox.x, opposition.hitbox.y + opposition.hitbox.h);
    float p14 = specradius(player.hitbox.x + player.hitbox.w, player.hitbox.y + player.hitbox.h, opposition.hitbox.x + opposition.hitbox.w, opposition.hitbox.y + opposition.hitbox.h);
    //this code gets the relevant sub area relative to a vertice in player
    float p4subarea = heronstheorem(p11, p12, opposition.hitbox.w)+ 
    heronstheorem(p11, p13, opposition.hitbox.h)+
    heronstheorem(p12, p14, opposition.hitbox.h)+
    heronstheorem(p13, p14, opposition.hitbox.w);
    if(p1subarea  <= opposition.hitbox.w * opposition.hitbox.h|| p2subarea <= opposition.hitbox.w * opposition.hitbox.h|| p3subarea <= opposition.hitbox.w * opposition.hitbox.h|| p4subarea <=opposition.hitbox.w * opposition.hitbox.h){
        //there is collision
        return true;
    }
    //there is no collision
    return false;
}
#endif