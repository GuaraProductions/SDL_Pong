#include<iostream>
#include<SDL2/SDL.h>

#include"game_window.hpp"

int main(int argc, const char* argv[]) {   

    GameWindow game = GameWindow();

    game.start_loop();
    return 0;
}