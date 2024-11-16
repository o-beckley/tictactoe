cmake_minimum_required(VERSION 3.29)
project(tictactoe C)

set(CMAKE_C_STANDARD 11)

add_executable(
        tictactoe
        main.c
        game.c
        tictactoe.h
)
