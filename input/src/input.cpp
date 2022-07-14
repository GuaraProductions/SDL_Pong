#include"input.hpp"
#include <stdexcept>
#include<iostream>

std::unordered_map<SDL_Keycode,SDL_EventType> Input::keyboard_key_status;

void Input::handle_keyboard_event(SDL_Keycode key, SDL_EventType state) {
    std::cout << "2key: " << key << " 2state: " << state << std::endl;
    Input::keyboard_key_status[key] = state;
}

bool Input::is_key_pressed(SDL_Keycode key) {
    bool response = false;
    try {
        response = Input::keyboard_key_status[key] == SDL_KEYDOWN;
    } catch (const std::out_of_range& oor) { }

    return response;
}

bool Input::is_key_released(SDL_Keycode key) {
    bool response = false;

    try {
        response = Input::keyboard_key_status.at(key) == SDL_KEYUP;
    } catch(const std::out_of_range& oor) {}

    return response;
}
