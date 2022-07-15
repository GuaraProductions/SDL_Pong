#include"paddle.hpp"
#include<iostream>

Paddle::Paddle() : Entity(0,0,150,50) {
    this->speed = 5;

    this->sprite_color = {
        255,
        255,
        255,
        255
    };
}

Paddle::Paddle(int x, int y,int width, int height, SDL_Color sprite_color ) : Entity(x,y,width,height) {
    this->sprite = {
        x,
        y,
        width,
        height,
    };

    this->speed        = 5;
    this->sprite_color = sprite_color;
}

void Paddle::update() {

    sprite.x = this->x;
    sprite.y = this->y;
}

void Paddle::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer,
                           sprite_color.r,
                           sprite_color.g,
                           sprite_color.b,
                           sprite_color.a);
                           
    SDL_RenderFillRect(renderer,&sprite);
}

void Paddle::move_x(int x) {
    this->x += x * speed;
}

void Paddle::move_y(int y) {
    this->y += y * speed;
}