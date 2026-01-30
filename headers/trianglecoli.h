#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <cstring>
#include <cmath>
#include <vector>
#include "structure.h"
#ifndef trianglecoli_h
#define trianglecoli_h
//****** this should probably go in the class */
typedef struct triangles{
    SDL_Vertex base1;
    SDL_Vertex base2;
    SDL_Vertex height;
    bool iscolided;
}triangle;

float specradius(int px, int py,int obx,int oby)
{
    return std::sqrt(((obx-px)*(obx-px))+((oby-py)*(oby-py)));
}

//triangle collision
//now just make this work with the window thing
//make this class into a header file
class trianglecol
{
    //at this point, make a function for the triangles, and one for the squares.
    public:
        std::vector<triangle*> Tstor;
        bool getlines(std::vector<triangle*>& T, SDL_Rect &mainc);
        bool squargetl(std::vector<structures*> m, SDL_Rect mainc);
        bool squarget1(SDL_Rect m, SDL_Rect mainc, char dummy);
        void movstructs(std::vector<structures*> rec,std::vector<triangles*>& tri, char key, bool iscoolided, char mok);
        //bool mov;
        //get the vertexes
};
//make this function take an array of structs instead of one
//overload this to make it work with rectangles.
bool trianglecol::getlines(std::vector<triangle*>& T, SDL_Rect &mainc)
{
    //remember I dont have to draw line in order to check areas, just get the numbers for the length of the line
    //check for SDL_rect(normal, check all the points for sdl_rect soon
    //it should be 2posx - 1posy squared + 2posy -1posy squared;
    //this->mov = false;
    for(int i = 0; i < T.size(); i++)
    {
        float lone =specradius(T[i]->height.position.x, T[i]->height.position.y, mainc.x, mainc.y);
        float ltwo =specradius(T[i]->base1.position.x, T[i]->base1.position.y, mainc.x, mainc.y);
        float lthree =specradius(T[i]->base2.position.x, T[i]->base2.position.y, mainc.x, mainc.y);

        //do the reg point(pone)
        float p2lone = specradius(T[i]->height.position.x, T[i]->height.position.y, mainc.x + mainc.w, mainc.y);
        float p2ltwo = specradius(T[i]->base1.position.x, T[i]->base1.position.y, mainc.x + mainc.w, mainc.y);
        float p2lthree = specradius(T[i]->base2.position.x, T[i]->base2.position.y, mainc.x + mainc.w, mainc.y);

        float p3lone = specradius(T[i]->height.position.x, T[i]->height.position.y, mainc.x, mainc.y + mainc.h);
        float p3ltwo = specradius(T[i]->base1.position.x, T[i]->base1.position.y, mainc.x, mainc.y + mainc.h);
        float p3lthree = specradius(T[i]->base2.position.x, T[i]->base2.position.y, mainc.x, mainc.y + mainc.h);

        float p4lone = specradius(T[i]->height.position.x, T[i]->height.position.y, mainc.x + mainc.w, mainc.y + mainc.h);
        float p4ltwo = specradius(T[i]->base1.position.x, T[i]->base1.position.y, mainc.x + mainc.w, mainc.y + mainc.h);
        float p4lthree = specradius(T[i]->base2.position.x, T[i]->base2.position.y, mainc.x + mainc.w, mainc.y + mainc.h);

        //these can stay the same throut all of the checks
        float Bone =specradius(T[i]->height.position.x, T[i]->height.position.y, T[i]->base1.position.x, T[i]->base1.position.y);
        float Btwo =specradius(T[i]->base1.position.x, T[i]->base1.position.y, T[i]->base2.position.x, T[i]->base2.position.y);
        float Bthree =specradius(T[i]->base2.position.x, T[i]->base2.position.y, T[i]->height.position.x, T[i]->height.position.y);

        float subarea = (Bone+Btwo+Bthree)/2;
        float A = std::sqrt(subarea*(subarea-Bone)*(subarea-Btwo)*(subarea-Bthree));

        float suba1 =(lone+ltwo+Bone)/2;
        float A1= std::sqrt(suba1*(suba1-lone)*(suba1-ltwo)*(suba1-Bone));
        float suba2 = (ltwo+lthree+Btwo)/2;
        float A2= std::sqrt(suba2*(suba2-ltwo)*(suba2-lthree)*(suba2-Btwo));
        float suba3 = (lthree+lone+Bthree)/2;
        float A3= std::sqrt(suba3*(suba3-lthree)*(suba3-lone)*(suba3-Bthree));

        //point two subarea
        float p2suba1 = (p2lone+p2ltwo+Bone)/2;
        float ptA1 = std::sqrt(p2suba1*(p2suba1-p2lone)*(p2suba1-p2ltwo)*(p2suba1-Bone));
        float p2suba2 = (p2ltwo+p2lthree+Btwo)/2;
        float ptA2 = std::sqrt(p2suba2*(p2suba2-p2ltwo)*(p2suba2-p2lthree)*(p2suba2-Btwo));
        float p2suba3 = (p2lthree+p2lone+Bthree)/2;
        float ptA3 = std::sqrt(p2suba3 *(p2suba3-p2lthree) * (p2suba3-p2lone) * (p2suba3-Bthree));

        //poitn three subarea
        float p3suba1 = (p3lone+p3ltwo+Bone)/2;
        float p3A1 = std::sqrt(p3suba1*(p3suba1-p2lone)*(p3suba1-p2ltwo)*(p3suba1-Bone));
        float p3suba2 = (p3ltwo+p3lthree+Btwo)/2;
        float p3A2 = std::sqrt(p3suba2*(p3suba2-p3ltwo)*(p3suba2-p3lthree)*(p3suba2-Btwo));
        float p3suba3 = (p3lthree+p3lone+Bthree)/2;
        float p3A3 = std::sqrt(p3suba3 *(p3suba3-p3lthree) * (p3suba3-p3lone) * (p3suba3-Bthree));

        //point four subarea
        float p4suba1 = (p4lone+p4ltwo+Bone)/2;
        float p4A1 = std::sqrt(p4suba1*(p4suba1-p4lone)*(p4suba1-p4ltwo)*(p4suba1-Bone));
        float p4suba2 = (p4ltwo+p4lthree+Btwo)/2;
        float p4A2 = std::sqrt(p4suba2*(p4suba2-p4ltwo)*(p4suba2-p4lthree)*(p4suba2-Btwo));
        float p4suba3 = (p4lthree+p4lone+Bthree)/2;
        float p4A3 = std::sqrt(p4suba3 *(p4suba3-p2lthree) * (p4suba3-p2lone) * (p4suba3-Bthree));

        //just add them now to get all of the areas
        //lthree ==
        //make 4 of these
        float subtr1, substr2, substr3, substr4;
        std::floor(subtr1 = A1 + A2 + A3);
        std::floor(substr2 = ptA1 + ptA2 + ptA3);
        std::floor(substr3 = p3A1 + p3A2 + p3A3);
        std::floor(substr4 = p4A1 + p4A2 + p4A3);


        if(subtr1 <= A || substr2 <= A  || substr3 <=A ||  substr4 <= A){return false;}
    }
    return true;                                                                        //return true if no collision
}
//finish this part later


//add to the total of tick, if tick is equal to size
//then there are no collisions
//if else then there is collisions
//fix this, I have no clue why its doing this
bool trianglecol::squargetl(std::vector<structures*> m, SDL_Rect mainc)
{
    std::vector<triangle*> squttr= {};
    //convert the points into two triangles
    for(int i = 0; i < m.size(); i++){
        triangle *T = new triangle();
        triangle *t2 = new triangle();
        T->height = {{(float)m[i]->hitbox.x, (float)m[i]->hitbox.y}, {0, 0, 255, 0xFF}, {0.f, 0.f}};
        T->base1 = {{(float)m[i]->hitbox.x, (float)m[i]->hitbox.y + m[i]->hitbox.h}, {}, {0.f,0.f}};
        T->base2 = {{(float)m[i]->hitbox.x + m[i]->hitbox.w, (float)m[i]->hitbox.y}, {}, {}};

        t2->height = {{(float)m[i]->hitbox.x + m[i]->hitbox.w, (float) m[i]->hitbox.y + m[i]->hitbox.h}, {}, {}};
        t2->base1 = {{(float)m[i]->hitbox.x + m[i]->hitbox.w, (float) m[i]->hitbox.y}, {}, {}};
        t2->base2 = {{(float) m[i]->hitbox.x, (float) m[i]->hitbox.y + m[i]->hitbox.h}};
        squttr.push_back(T);
        squttr.push_back(t2);
        //I have come to the conclusion that this function will not work as it is right now
        //just make seperate collisions for rectangles and triangles.
    }
    return getlines(squttr, mainc); //tells us if there is collision, if so return false, if not return true
}
bool trianglecol::squarget1(SDL_Rect m, SDL_Rect mainc, char dummy){
    std::vector<triangle*> squttr= {};
    //convert the points into two triangles
        triangle *T = new triangle();
        triangle *t2 = new triangle();
        T->height = {{(float)m.x, (float)m.y}, {0, 0, 255, 0xFF}, {0.f, 0.f}};
        T->base1 = {{(float)m.x, (float)m.y + m.h}, {}, {0.f,0.f}};
        T->base2 = {{(float)m.x + m.w, (float)m.y}, {}, {}};

        t2->height = {{(float)m.x + m.w, (float) m.y + m.h}, {}, {}};
        t2->base1 = {{(float)m.x + m.w, (float) m.y}, {}, {}};
        t2->base2 = {{(float) m.x, (float) m.y + m.h}};
        squttr.push_back(T);
        squttr.push_back(t2);

        bool ans = getlines(squttr,mainc);
        delete T;
        delete t2;

    return ans; //tells us if there is collision, if so return false, if not return true
}
//this function needs to be called for basically all movement
//use the last movstate as a buffer
//make this work with structures

//now I can do a check ahead
void trianglecol::movstructs(std::vector<structures*> rec,std::vector<triangle*>& tri, char key, bool iscoolided, char mok)
{
//change the position of the window with this function
//increment x's
    //this is regarded, i need to redo it
    if(iscoolided){
        if(key == 'd' && mok !='a'){
            for(int i = 0; i < tri.size(); i++){
                tri[i]->base1.position.x+=5;
                tri[i]->base2.position.x+=5;
                tri[i]->height.position.x+=5;
            }
            for(int i =0; i < rec.size(); i++){
                rec[i]->hitbox.x += 5;
            }
            //window->x +=5;
        }
    // decrement x's
        if(key == 'a' && mok != 'd'){
            for(int i= 0; i < tri.size(); i++){
                tri[i]->base1.position.x-=5;
                tri[i]->base2.position.x-=5;
                tri[i]->height.position.x-=5;
            }
            for(int i = 0; i < rec.size(); i++){
                rec[i]->hitbox.x -=5;
            }
            //window->x-=5;
        }
    //increment y's
        if(key == 's' && mok !='w'){
            for(int i = 0; i< tri.size(); i++){
                tri[i]->base1.position.y+=5;
                tri[i]->base2.position.y+=5;
                tri[i]->height.position.y+=5;
            }
            for(int i = 0; i < rec.size(); i++){
                rec[i]->hitbox.y+=5;
            }
            //window->y +=5;
        }
    //decrement y's
        if(key == 'w' && mok!='s'){
            for(int i = 0; i < tri.size(); i++){
                tri[i]->base1.position.y-=5;
                tri[i]->base2.position.y-=5;
                tri[i]->height.position.y-=5;
            }
            for(int i = 0; i < rec.size(); i++){
                rec[i]->hitbox.y -=5;
            }
            //window->y-=5;
        }
    }
else{
    if(key == 'd' ){
        for(int i = 0; i < tri.size(); i++){
            tri[i]->base1.position.x--;
            tri[i]->base2.position.x--;
            tri[i]->height.position.x--;
        }
        for(int i = 0; i < rec.size(); i++){
            rec[i]->hitbox.x--;
        }
        //window->x-=5;
    }
    // decrement x's
    if(key == 'a' ){
        for(int i= 0; i < tri.size(); i++){
            tri[i]->base1.position.x++;
            tri[i]->base2.position.x++;
            tri[i]->height.position.x++;
        }
        for(int i = 0; i < rec.size(); i++){
            rec[i]->hitbox.x++;
        }
        //window->x+=5;
    }
    //increment y's
    if(key == 's'){
        for(int i = 0; i< tri.size(); i++){
            tri[i]->base1.position.y--;
            tri[i]->base2.position.y--;
            tri[i]->height.position.y--;
        }
        for(int i = 0; i < rec.size(); i++){
            rec[i]->hitbox.y--;
        }
        //window->y-=5;
    }
    //decrement y's
    if(key == 'w'){
        std::cout << "hi";
        for(int i = 0; i < tri.size(); i++){
            tri[i]->base1.position.y++;
            tri[i]->base2.position.y++;
            tri[i]->height.position.y++;
        }
        for(int i = 0; i < rec.size(); i++){
            rec[i]->hitbox.y++;
        }
    //window->y+=5;
    }
}
iscoolided = false;
}

//the goal is to call key detect and be able to call the movstructs function too
#endif