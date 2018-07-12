cmake_minimum_required(VERSION 3.9)
project(Corewar C)

set(CMAKE_C_STANDARD 90)

link_directories(${PROJECT_SOURCE_DIR}/libft/ft_printf/includes)
include_directories(${PROJECT_SOURCE_DIR}/libft/ft_printf/includes)
link_directories(${PROJECT_SOURCE_DIR}/libft)
include_directories(${PROJECT_SOURCE_DIR}/libft)

add_executable(Corewar Makefile libft vm_champs src/main.c inc/corewar.h src/read.c src/vizualize.c src/inits.c src/converts.c src/live_ld_st_add_sub.c src/read2.c src/and_or_xor_zjmp_ldi.c src/sti_fork_lld_lldi_lfork.c)
target_link_libraries(Corewar ${PROJECT_SOURCE_DIR}/libft/libft.a ${PROJECT_SOURCE_DIR}/libft/ft_printf/libftprintf.a)
set(CMAKE_C_FLAGS "-lncurses")

#add_executable(Corewar Makefile libft vm_champs src/main.c inc/corewar.h src/read.c src/vizualize.c)