cmake_minimum_required(VERSION 3.12)
project(demo)

set(BUILD_SHARED_LIBS 0)
if(WIN32)
    add_definitions(/W3)
else()
    add_definitions(-w)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/3rdparty/glew/include
    ${PROJECT_SOURCE_DIR}/3rdparty/glfw/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/3rdparty/glew/lib/
    ${PROJECT_SOURCE_DIR}/3rdparty/glfw/lib/
)

if(WIN32)
    if(BUILD_WITH_SHARE_LIB)
        link_libraries(
            glew32.lib
            glfw3dll.lib
        )
    else()
        link_libraries(
            glew32s.lib
            glfw3.lib
            OpenGL32.lib
        )
    endif()
else()

endif()

file(GLOB SOURCE_FILE
    ${PROJECT_SOURCE_DIR}/src/demo.cpp
)

add_executable(demo ${SOURCE_FILE})