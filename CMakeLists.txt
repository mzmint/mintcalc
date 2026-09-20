cmake_minimum_required(VERSION 3.20)

project(MintCalc)

set(CMAKE_CXX_STANDARD 20)

set(Qt6_DIR "D:/Qt/6.11.2/mingw_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MintCalc
        main.cpp
)

target_link_libraries(MintCalc
        Qt6::Widgets
)