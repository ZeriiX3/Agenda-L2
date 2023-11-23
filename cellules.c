/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "cellules.h"
// ******************************************************************************** //


// Création d'une cellule
t_d_cell* create_cell(int val, int lvl) {
    // Allocation mémoire pour la structure
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));

    cell->value = val;
    cell->level = lvl;

    // Allocation mémoire
    cell->next = (t_d_cell**) calloc(lvl, sizeof(t_d_cell*));

    return cell;
}
