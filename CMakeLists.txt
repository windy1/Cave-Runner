cmake_minimum_required(VERSION 3.7)
project(CS_120_Final_Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/graphics/graphics.cpp src/graphics/graphics.h src/game.h src/math.h src/entity/Entity.cpp src/entity/Entity.h src/entity/Player.cpp src/entity/Player.h src/entity/GrapplingHook.cpp src/entity/GrapplingHook.h src/entity/Collectible.cpp src/entity/Collectible.h src/entity/Coin.cpp src/entity/Coin.h src/entity/PowerUp.cpp src/entity/PowerUp.h)

add_executable(CS_120_Final_Project ${SOURCE_FILES})
