cmake_minimum_required(VERSION 3.9)
project(Corewar C)

set(CMAKE_C_STANDARD 90)

add_executable(Corewar Makefile libft vm_champs src/main.c inc/corewar.h src/read.c src/vizualize.c)