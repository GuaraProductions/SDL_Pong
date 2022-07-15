#include "game_window.hpp"

int player1_x     = WINDOW_WIDTH/2;
int player1_y     = 10;
int player1_speed = 5;

int player2_x     = WINDOW_WIDTH/2;
int player2_y     = WINDOW_HEIGHT-35;
int player2_speed = 5;


GameWindow::GameWindow() {
    game_is_running = initialize_window();
    this->keyboard_input = Input();
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
    if (Input::is_key_pressed(SDL_SCANCODE_RIGHT)) 
        player1_x += player1_speed;
    else if (Input::is_key_pressed(SDL_SCANCODE_LEFT)) 
        player1_x -= player1_speed;
    
    if (Input::is_key_pressed(SDL_SCANCODE_A)) 
        player2_x -= player2_speed;
    else if (Input::is_key_pressed(SDL_SCANCODE_D))
        player2_x += player2_speed;

    if (Input::is_key_pressed(SDL_SCANCODE_ESCAPE)) 
        game_is_running = false;
    
}

void GameWindow::render() {
    SDL_SetRenderDrawColor(renderer, 100,50,100,255);
    SDL_RenderClear(renderer);
    
    SDL_Rect player1_pad = {
        player1_x,
        player1_y,
        150,
        25,
    };

    SDL_Rect player2_pad = {
        player2_x,
        player2_y,
        150,
        25,
    };

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&player1_pad);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderFillRect(renderer,&player2_pad);

    SDL_RenderPresent(renderer);

}

void GameWindow::start_loop() {

    while(game_is_running) {
        process_window_events();
        update();
        render();
    }
}

