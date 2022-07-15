#ifndef INPUT_HPP
#define INPUT_HPP

#include<SDL2/SDL.h>
#include<unordered_map>

class Input {

    private:

        const static Uint8 *keyboard_key_status;

    public: 

        static bool is_key_pressed(SDL_Keycode key);

        void handle_keyboard_event();
};

#endif