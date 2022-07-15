#ifndef PADDLE_HPP
#define PADDLE_HPP

#include"entity.hpp"

class Paddle : public virtual Entity{

    private: 

        SDL_Rect  sprite;
        SDL_Color sprite_color;
        int speed;

    public:

        Paddle();
        Paddle(int x,int y,int width, int height, SDL_Color sprite_color);
        void update();
        void render(SDL_Renderer *renderer);

        void move_x(int x);
        void move_y(int y);
};

#endif