#pragma once
#include "defines.h"

struct game;

// application configuration
typedef struct application_config {
    // window starting x axis
    i16 start_pos_x;
    // window starting position y axis
    i16 start_pos_y;
    // window starting width
    i16 start_width;
    // window starting height 
    i16 start_height;
    // the application name used in windowing 
    char* name;
} application_config;

EPHAPI b8 application_create(struct game* game_inst);

EPHAPI b8 application_run();