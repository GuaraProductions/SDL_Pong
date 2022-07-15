add_library(window
src/game_window.cpp)

target_include_directories(window PUBLIC include)
target_link_libraries(window PRIVATE game_input)
target_link_libraries(window PRIVATE game_entities)