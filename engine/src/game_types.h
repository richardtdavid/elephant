#pragma once
#include "core/application.h"

/**
 *  Represents the basic game state in a game 
 *  Called for creation by the application 
*/

typedef struct game {
    // application configuration 
    application_config app_config;

    // function fpointer to game's initialize function 
    b8 (*initialize)(struct game* game_inst);

    // function pointer to game's update function 
    b8 (*update)(struct game* game_inst, f32 delta_time);

    // function pointer to game's render function 
    b8 (*render)(struct game* game_inst, f32 delta_time);

    // function pointer handle resize, if applicable  
    void (*on_resize)(struct game* game_inst, u32 width, u32 height);

    // game specific game state. created and manged by the game 
    void* state;

} game;