#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include<SDL2/SDL.h>
#include<iostream>
#include"../../input/include/input.hpp"
#include"../../entity/include/paddle.hpp"
#include"../../entity/include/ball.hpp"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800

#define WINDOW_NAME "Game"

class GameWindow {

    SDL_Window*   window   = NULL;
    SDL_Renderer* renderer = NULL;

    Paddle player;
    Paddle enemy;
    Ball ball;

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