cmake_minimum_required(VERSION 3.25)
project(projet_agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_agenda main.c fonctions.c fonctions.h cellules.c cellules.h listes.c listes.h)
