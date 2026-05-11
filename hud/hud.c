#include "hud.h";
void displayhearts(structures *heart);
void displayammo(int ammocount){
  SDL_Rect ammunition_display;
  if(ammo < 400){
    ammunition_display.x = 5;
    ammunition_display.y = 5;
    ammunition_display.h = ammo;
    ammunition_display.w = 20;
  }
} //This is stutter
