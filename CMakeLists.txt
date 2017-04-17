cmake_minimum_required(VERSION 3.7)
project(CS_120_Final_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wno-deprecated-declarations)

set(SOURCE_FILES
        src/main.cpp
        src/tests.cpp src/tests.h
        src/textbased_test.cpp
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
        src/entity/Score.h src/entity/Score.cpp)

add_executable(CS_120_Final_Project ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries(CS_120_Final_Project ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
