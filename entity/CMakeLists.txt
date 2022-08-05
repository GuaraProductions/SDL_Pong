add_library(game_entities
src/entity.cpp
src/paddle.cpp
src/ball.cpp)

target_include_directories(game_entities PUBLIC include)
target_link_libraries(game_entities PRIVATE window)