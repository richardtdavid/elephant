#pragma once 
#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"


// external-defined function to create a game
extern b8 create_game(game* out_game);


/*
*  The main entry point for the application 
*/
int main(void) {
    // game instance from the application 
    game game_inst;
    if(!create_game(&game_inst)) {
        EPHFATAL("could not create game!");
        return -1;
    }

    // ensure the function pointers exist 
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        EPHFATAL("The game's function pointers must be assigned!");
        return -2;
    }

    // initialization
    if(!application_create(&game_inst)) {
        EPHINFO("Application failed to create!");
        return 1;
    }

    // begin the game loop
    if(!application_run()) {
        EPHINFO("Application did not shutdown gracefully!");
        return 2;
    }
    
    return 0;
}