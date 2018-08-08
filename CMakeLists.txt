cmake_minimum_required(VERSION 3.7)
project(CS_120_Final_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wno-deprecated-declarations)

set(SOURCE_FILES
        src/main.cpp
        src/tests.cpp src/tests.h
        src/graphics/graphics.cpp src/graphics/graphics.h
        src/game.h
        src/math.h
        src/entity/Entity.cpp src/entity/Entity.h
        src/entity/Player.cpp src/entity/Player.h
        src/entity/GrapplingHook.cpp src/entity/GrapplingHook.h
        src/entity/Collectible.cpp src/entity/Collectible.h
        src/entity/Coin.cpp src/entity/Coin.h
        src/entity/PowerUp.cpp src/entity/PowerUp.h
        src/entity/Obstacle.cpp src/entity/Obstacle.h
        src/entity/Collectible.cpp
        src/math.cpp
        src/entity/Barrier.cpp src/entity/Barrier.h
        src/entity/Score.h src/entity/Score.cpp
        src/graphics/Color.cpp src/graphics/Color.h
        src/entity/Torch.cpp src/entity/Torch.h
        src/ptr.h
        src/graphics/Menu.cpp src/graphics/Menu.h
        src/graphics/StartMenu.cpp src/graphics/StartMenu.h
        src/graphics/PauseMenu.cpp src/graphics/PauseMenu.h
        src/graphics/Scene.cpp src/graphics/Scene.h
        src/graphics/GameOverMenu.cpp src/graphics/GameOverMenu.h
        src/io/GameStateReader.cpp src/io/GameStateReader.h
        src/io/grs.h src/io/grs.cpp
        src/io/GameStateWriter.cpp src/io/GameStateWriter.h
        src/entity/Checkpoint.cpp src/entity/Checkpoint.h
        src/graphics/LevelButton.cpp src/graphics/LevelButton.h)

add_executable(CS_120_Final_Project ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries(CS_120_Final_Project ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
