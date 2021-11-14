cmake_minimum_required(VERSION 3.20)
project(Fill-Maze)

set(CMAKE_CXX_STANDARD 14)
set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include)
set(GLAD_H /usr/local/Cellar/glad/include)

include_directories(${GLEW_H} ${GLFW_H} ${GLM_H} ${GLAD_H})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

add_executable(main
        src/main.cpp
        include/main.h
        src/control.cpp
        include/control.h
        src/draw.cpp
        include/draw.h
        src/gameresult.cpp
        include/gameresult.h
        src/gameover.cpp
        include/gameover.h
        src/gamestart.cpp
        include/gamestart.h
        src/init.cpp
        include/init.h
        src/ball.cpp
        include/ball.h
        src/laberynth.cpp
        include/laberynth.h
        )

if (APPLE)
    target_link_libraries(main "-framework OpenGL")
    target_link_libraries(main "-framework GLUT")

endif()