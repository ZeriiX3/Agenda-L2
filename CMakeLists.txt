cmake_minimum_required(VERSION 3.25)
project(gestion_agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(gestion_agenda main.c fichier.c fichier.h
        timer.c
        affichages.h
        affichages.h
        affichages.c
        models.c)
