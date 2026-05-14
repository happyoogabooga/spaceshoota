#include "hud.h"
static SDL_Rect srec_heart  = (SDL_Rect){
  0,
  80,
  15,
  12
};
SDL_Rect heart_hitbox = (SDL_Rect){
  0,
  0,
  32,
  32
};
structures* makeheart(int x, int y, SDL_Renderer *renderer){
  structures*heart = (structures*)malloc(sizeof(structures));
  heart->hitbox.x = x;
  heart->hitbox.y = y;
  heart->hitbox.h = 32;
  heart->hitbox.w = 32;
  heart->structurelookpos = srec_heart;
  heart->flocation = IMG_LoadTexture(renderer, "sprites/spaceships.png");
  return heart;
};
SDL_Rect ammunition_display;
void displayhearts(int health, SDL_Renderer *renderer){
  SDL_Texture *heart_texture = IMG_LoadTexture(renderer, "sprites/spaceships.png");
  for(int i = 0; i < health; i++){
    heart_hitbox.x = i * 32;
    SDL_RenderCopy(renderer, heart_texture, &srec_heart, &heart_hitbox);
  }
  SDL_DestroyTexture(heart_texture);
}
void displayammo(int ammocount, SDL_Renderer *renderer){
  ammunition_display.x = 0;
  ammunition_display.y = 64;
  ammunition_display.h = ammocount;
  ammunition_display.w = 16;
  if(ammocount > 0){
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
  }
  else{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(renderer, &ammunition_display);
}
void displayhud(int health, int ammocount, SDL_Renderer *renderer){
  displayhearts(health, renderer);
  displayammo(ammocount, renderer);
}
