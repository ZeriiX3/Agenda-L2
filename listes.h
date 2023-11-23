/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


#ifndef PROJET_AGENDA_LISTES_H
#define PROJET_AGENDA_LISTES_H

// ************************************ IMPORT ************************************ //
#include "cellules.h"
// ******************************************************************************** //


// Structure
typedef struct s_d_list {
    int max_level;
    struct s_d_list **heads;
}t_d_list;


// Fonctions
t_d_list* create_list(int max_lvl);

void cell_atHead(t_d_list* list, t_d_cell* cell);

void display_cells(t_d_list * list, int level);

void display_all_levels(t_d_list * list);


#endif //PROJET_AGENDA_LISTES_H
