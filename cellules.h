/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


#ifndef PROJET_AGENDA_CELLULES_H
#define PROJET_AGENDA_CELLULES_H

// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <stdlib.h>
// ******************************************************************************** //


typedef struct s_d_cell {
    int value;
    int level;
    struct s_d_cell **next;
}t_d_cell;

t_d_cell* create_cell(int val, int lvl);

#endif //PROJET_AGENDA_CELLULES_H
