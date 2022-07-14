#include "game_window.hpp"

int x = 0;

GameWindow::GameWindow() {
    game_is_running = initialize_window();
}

GameWindow::~GameWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool GameWindow::initialize_window()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL" << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(
        WINDOW_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS);

    if (window == NULL)
    {
        std::cerr << "Error creating a window" << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL)
    {
        std::cerr << "Error creating the game renderer" << std::endl;
        exit(1);
    }

    return true;
}

void GameWindow::process_window_events() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            game_is_running = false;
            break; 
        
        case SDL_KEYDOWN:
        {
            auto key_pressed = event.key.keysym.sym;

            if (key_pressed == SDLK_ESCAPE) 
                game_is_running = false;

            if (key_pressed == SDLK_RIGHT)
                x++;

            break;
        }
        default:
            break;
    }
}

void GameWindow::update() {
    
}

void GameWindow::render() {
    SDL_SetRenderDrawColor(renderer, 100,50,100,255);
    SDL_RenderClear(renderer);
    
    SDL_Rect ball = {
        x,
        150,
        50,
        50,
    };

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&ball);

    SDL_RenderPresent(renderer);

}

void GameWindow::start_loop() {

    auto last_time         = SDL_GetTicks();
    double amount_of_ticks = 60.0;
    double ns              = 1000000000 / amount_of_ticks;
    double delta           = 0.0;

    while(game_is_running) {
        
        auto now = SDL_GetTicks();
        delta    += now - last_time / ns;
        last_time = now;
        if (delta >= 1) {
            process_window_events();
            update();
            render();
            delta--;
        }
    }
}

