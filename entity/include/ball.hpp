#ifndef BALL_HPP
#define BALL_HPP

#include"entity.hpp"

class Ball : public virtual Entity{

    private: 

        SDL_Color sprite_color;
        int speed;

        float dx;
        float dy;

    public:

        Ball();
        Ball(int x,int y,int width, int height, SDL_Color sprite_color);
        void update();
        void render(SDL_Renderer *renderer);
        int render_fill_circle(SDL_Renderer * renderer, int x, int y, int radius);

        void move_x(int x);
        void move_y(int y);
};

#endif