#include"input.hpp"
#include <stdexcept>
#include<iostream>

const Uint8* Input::keyboard_key_status;

void Input::handle_keyboard_event() {
    Input::keyboard_key_status = SDL_GetKeyboardState(NULL);
}

bool Input::is_key_pressed(SDL_Keycode key) {
    if (Input::keyboard_key_status != NULL)
        return Input::keyboard_key_status[key];
    else 
        return false;
}