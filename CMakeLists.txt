cmake_minimum_required(VERSION 3.0.0)
project(SDL_Pong VERSION 1.0.0)

find_package(SDL2 REQUIRED)

add_subdirectory(game_window)

add_executable(SDL_Pong
main.cpp)

target_include_directories(SDL_Pong PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL_Pong PRIVATE window ${SDL2_LIBRARIES})