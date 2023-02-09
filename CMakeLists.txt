cmake_minimum_required (VERSION 3.8)
project(LigidLight VERSION 1.0)

file(GLOB_RECURSE LIGIDLIGHT_SOURCES
   ${PROJECT_SOURCE_DIR}/*.cpp
   #${PROJECT_SOURCE_DIR}/Main/thirdparty/glad.c
)

#Disable warnings
#add_definitions(-w)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#if(UNIX)
#   find_package(glfw3 REQUIRED)
#   find_package(X11 REQUIRED)
#endif(UNIX)

add_definitions(-DCMAKE_HAS_X)

# set(GLFW_BUILD_EXAMPLES OFF)
# set(GLFW_BUILD_TESTS OFF)
# set(GLFW_BUILD_DOCS OFF)
# set(GLFW_INSTALL OFF)

# set(NMGFX_FIND_GLFW OFF)

add_executable(LigidLight
   ${LIGIDLIGHT_SOURCES})

# if (WIN32)
#    target_compile_definitions(LigidLight PRIVATE CRT)
# endif (WIN32)
   
target_include_directories(LigidLight PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_directories(LigidLight PRIVATE ${PROJECT_SOURCE_DIR}/src)
