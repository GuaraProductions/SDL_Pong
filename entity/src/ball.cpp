#include"ball.hpp"

Ball::Ball() : Entity(0,0,150,50) {
    this->speed = 5;

    this->sprite_color = {
        255,
        255,
        255,
        255
    };

    this->dx = -1.0f;
    this->dy =  0.0f;
}

Ball::Ball(int x, int y,int width, int height, SDL_Color sprite_color) : Entity(x,y,width,height) {

    this->speed        = 5;
    this->sprite_color = sprite_color;

    this->dx = -1.0f;
    this->dy =  0.0f;
}

void Ball::update() {
    this->x += this->dx * this->speed;
    this->y += this->dy * this->speed;
}

void Ball::render(SDL_Renderer *renderer) {
    
    SDL_SetRenderDrawColor(renderer,
                        sprite_color.r,
                        sprite_color.g,
                        sprite_color.b,
                        sprite_color.a);

    render_fill_circle(renderer,this->x,this->y,this->width);
}


int Ball::render_fill_circle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

