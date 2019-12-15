cmake_minimum_required(VERSION 3.12)

project(Aurora)

 # Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(SOURCE_LIST "")
add_library(Aurora  ${CMAKE_SOURCE_DIR}/src/*.cpp)
# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)
