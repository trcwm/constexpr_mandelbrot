
cmake_minimum_required(VERSION 3.12)
project(constexpr_mandel)

set(CMAKE_CXX_STANDARD 17)

set(SRC 
    src/mandel1.cpp
    src/mandel2.cpp
    src/mandel3.cpp
    src/mandel4.cpp
    src/main.cpp)

add_compile_options(-fconstexpr-ops-limit=1000000000)
add_executable(constexpr_mandel ${SRC})

