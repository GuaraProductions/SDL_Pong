#ifndef INPUT_HPP
#define INPUT_HPP

#include<SDL2/SDL.h>
#include<unordered_map>

class Input {

    private:

        static std::unordered_map<SDL_Keycode,SDL_EventType> keyboard_key_status;

    public: 

        static bool is_key_pressed(SDL_Keycode key);
        static bool is_key_released(SDL_Keycode key);

        void handle_keyboard_event(SDL_Keycode key, SDL_EventType state);
};

#endif