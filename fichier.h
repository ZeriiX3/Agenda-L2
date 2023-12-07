/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */

#ifndef GESTION_AGENDA_FICHIER_H
#define GESTION_AGENDA_FICHIER_H

// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <stdlib.h>
// ******************************************************************************** //


// ***********************************CELL**************************************** //

typedef struct s_d_cell {
    int value;
    int level;
    struct s_d_cell **next;
}t_d_cell;

t_d_cell* create_cell(int val, int lvl);


// ***********************************LISTE**************************************** //

// Structure
typedef struct s_d_list {
    int max_level;
    t_d_cell *heads;
}t_d_list;


// Fonctions
t_d_list* create_list(int max_lvl);

void cell_atHead(t_d_list* list, t_d_cell* cell);

void display_cells(t_d_list * list, int level);

void display_list(t_d_list * list);

void display_list_aligned(t_d_list* list);

void insert_cell(t_d_list* list, t_d_cell* cell);


// *********************************** LEVELS **************************************** //

void display_levels_list(int niv);

#endif //GESTION_AGENDA_FICHIER_H
