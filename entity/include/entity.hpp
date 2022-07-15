#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<SDL2/SDL.h>

class Entity {

    protected:

        int x;
        int y;
        int width;
        int height;

    public:

        Entity(int x, int y, int width, int height);
        virtual void update() {}
        virtual void render(SDL_Renderer *renderer) {}

};

#endif