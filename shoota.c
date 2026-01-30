#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
SDL_Renderer *renderer;
//this is a simple project, make that one space atari game
//before doing this work on the traingle col function and perfect it
//main character class
typedef struct saucer{
    char *filelocation;
    SDL_Rect screen_location;
    SDL_Rect structurelookpos;
    
}saucer;
void keyhandler(SDL_Event ev){
    switch(ev.key.keysym.sym){
        case SDLK_SPACE:
        break;
        case SDLK_a:
        break;
        case SDLK_d:
        break;
    }
}
int main(int argc, char** argv)
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_Window* window = SDL_CreateWindow( "SHOOTA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xF1, 0xFF, 0xFF );
    return 0;
}