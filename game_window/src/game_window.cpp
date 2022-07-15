#include "game_window.hpp"

GameWindow::GameWindow() {
    game_is_running = initialize_window();
    this->keyboard_input = Input();

    SDL_Color player_color = {
        0,
        168,
        107,
        255
    };

    SDL_Color enemy_color = {
        205,
        92,
        92,
        255
    };

    this->player = Paddle(WINDOW_WIDTH/2,0,150,50,player_color);
    this->enemy  = Paddle(WINDOW_WIDTH/2,WINDOW_HEIGHT-50,150,50,enemy_color);
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

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
    SDL_PumpEvents();

    switch(event.type) {
        case SDL_QUIT:
            game_is_running = false;
            break; 
        
        case SDL_KEYDOWN:
        {
            auto key_pressed = event.key.keysym.sym;
            auto key_state   = SDL_KEYDOWN;
            this->keyboard_input.handle_keyboard_event();
            break;
        }
        case SDL_KEYUP:
        {
            auto key_pressed = event.key.keysym.sym;
            auto key_state   = SDL_KEYUP;
            this->keyboard_input.handle_keyboard_event();
            break;
        }
        default:
            break;
    }
}

void GameWindow::update() {
    if (Input::is_key_pressed(SDL_SCANCODE_RIGHT)) {
        player.move_x(1);
    } else if (Input::is_key_pressed(SDL_SCANCODE_LEFT)) {
        player.move_x(-1);
    }
    if (Input::is_key_pressed(SDL_SCANCODE_A)) {
        enemy.move_x(-1);
    } else if (Input::is_key_pressed(SDL_SCANCODE_D)) {
        enemy.move_x(1);
    }
    if (Input::is_key_pressed(SDL_SCANCODE_ESCAPE)) {
        game_is_running = false;
    }

    player.update();
    enemy.update();
    
}

void GameWindow::render() {

    // Background color
    SDL_SetRenderDrawColor(renderer, 35,35,35,255);
    SDL_RenderClear(renderer);

    player.render(renderer);
    enemy.render(renderer);

    SDL_RenderPresent(renderer);

}

void GameWindow::start_loop() {

    while(game_is_running) {
        process_window_events();
        update();
        render();
    }
}

