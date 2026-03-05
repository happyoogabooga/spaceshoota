//This will define the different states the game as a whole can be 
enum states{
    playing, paused
};
void stateofgame(states gamestate){
    switch(gamestate){
        case playing:
        break;
        case paused:
        break;
    }
}
void play();
void pause();
