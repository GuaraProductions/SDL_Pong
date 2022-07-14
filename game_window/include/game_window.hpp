#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include<SDL2/SDL.h>
#include<iostream>
#include"../../input/include/input.hpp"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

#define WINDOW_NAME "Game"

class GameWindow {

    SDL_Window*   window   = NULL;
    SDL_Renderer* renderer = NULL;

    bool game_is_running = false;

    Input keyboard_input;

    int last_frame_time = 0;

    public:

        GameWindow();
        ~GameWindow();
        bool initialize_window(void);
        void process_window_events(void);
        void start_loop(void);

        void render(void);
        void update(void);
};

#endif