#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <windows.h>
#include "dynamicarray/dynarr.h"
#include "headers/trianglecoli.h"
#include "headers/movestruct.h"
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
SDL_Renderer *renderer;
SDL_Texture *tex = NULL;
int main(int argc, char** argv)
{
    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init(IMG_INIT_PNG);            // initialize SDL_image for PNG support
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    
    // Get screen resolution using Windows API
    SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
    SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);
    
    SDL_Window* window = SDL_CreateWindow( "SHOOTA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xF1, 0xFF, 0xFF );
    
    saucer *player = createsaucer(makestructure((SDL_Rect){100, 100, 128, 128},(SDL_Rect){21, 0, 22, 43}, "sprites/spaceships.png", renderer), NULL, 4);
    linkedlist *saucerlist = malloc(sizeof(linkedlist));
    saucer *newsauc = createsaucer(makestructure((SDL_Rect){300, 300, 128, 128},(SDL_Rect){21, 0, 22, 43}, "sprites/spaceships.png", renderer), NULL, long_range);
    saucerlist->head = NULL;
    push_back(player, saucerlist); // first node is assigned, pointer->next will be cleared by push_back
    push_back(newsauc, saucerlist);
    //this is just for testing purposes, make sure to clean up the code and make it more efficient
    structures newn = makestructure((SDL_Rect){player->saucerstructure.hitbox.x, player->saucerstructure.hitbox.y, 32,32},
    (SDL_Rect){0,64,16,16},"sprites/spaceships.png", renderer);
    SDL_Event ev;
    int oldtime = SDL_GetTicks();
    projectiles_list plist;
    plist.head = NULL;
    addNode(&plist,createNode(newn, north));
    while(true){
        int newtime = SDL_GetTicks();
        float deltatime = (float)(newtime - oldtime) / 1000.0f;  // Convert to seconds for proper delta time usage
        collision_n(&plist,saucerlist);
        //all of this besides deltatime can go in one function, but for now this is fine
        while(SDL_PollEvent(&ev)){
            if (ev.type == SDL_QUIT) {
                return 0;
            } else if (ev.type == SDL_KEYDOWN) {
                if (ev.key.keysym.sym == SDLK_ESCAPE) {
                    return 0;
                }
            }
        }
        // Get keyboard state for smooth movement
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        bool up = state[SDL_SCANCODE_W];
        bool down = state[SDL_SCANCODE_S];
        bool left = state[SDL_SCANCODE_A];
        bool right = state[SDL_SCANCODE_D];
        bool shot = state[SDL_SCANCODE_SPACE];
        saucer copy = *player; // Create a copy of the player saucer for collision checking
        if(up || down || left || right || shot) {
            move(&copy.saucerstructure, 200.0f, deltatime, up, down, left, right);  // Increased speed for better feel
            if (!StructureCollision(copy.saucerstructure, newsauc->saucerstructure)) {
                // Only move the player if there is no collision with the newsauc
                move(&player->saucerstructure, 200.0f, deltatime, up, down, left, right);
            }
        }
        shoot(*player,shot,&plist,deltatime, renderer);
        SDL_RenderClear(renderer);
        if(plist.head == NULL){
        }
        displaynodes(&plist, renderer);
        //SDL_RenderCopy(renderer, IMG_LoadTexture(renderer, newn.flocation), &newn.structurelookpos, &newn.hitbox);
        displayitems(saucerlist, renderer);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderPresent(renderer);
        oldtime = newtime;
    }
    return 0;
}
