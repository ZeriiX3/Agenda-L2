/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "listes.h"
// ******************************************************************************** //


t_d_list* create_list(int max_lvl) {
    t_d_list list;
    list.max_level = max_lvl;
    for (int i=0; i<list.max_level;i++) {
        list.heads[i] = NULL;
    }
    list.heads = create_cell(2, 4);
    return list;
}