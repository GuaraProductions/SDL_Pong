cmake_minimum_required(VERSION 3.0.0)
project(SDL_Pong VERSION 1.1.0) 

#set(CMAKE_BUILD_TYPE Debug)    # Allow the compiled to be debug with gdb and valgrind

find_package(SDL2 REQUIRED)   

add_subdirectory(game_window)
add_subdirectory(entity) 
add_subdirectory(input)

add_executable(SDL_Pong main.cpp) 

target_include_directories(SDL_Pong PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL_Pong PRIVATE window game_input game_entities ${SDL2_LIBRARIES})
