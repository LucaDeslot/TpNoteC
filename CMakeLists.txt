cmake_minimum_required(VERSION 3.26)
project(TpNoteC C)

set(CMAKE_C_STANDARD 11)

add_executable(TpNoteC main.c
        Euristic.c
        exact-method.c
        main.h
        exact-method.h)
