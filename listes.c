/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "listes.h"
// ******************************************************************************** //


t_d_list* create_list(int max_lvl) {
    // Allocation mémoire
    t_d_list* list = (t_d_list*) malloc(sizeof(t_d_list));

    list->max_level = max_lvl;

    // Liste à niveau vide
    for (int i = 0; i < list->max_level; i++) {
        list->heads[i] = NULL;
    }

    return list;
}

void cell_atHead(t_d_list* list, t_d_cell* cell) {

}


// Function to display all cells at a specific level in the list
void display_cells(t_d_list * list, int level) {
    printf("[list head_%d @-]", level);

    // Traverse the list and display cells at the specified level
    t_d_cell *current = list->head;
    while (current != NULL) {
        if (level < current->level) {
            printf("-->[ %d|@-]", current->value);
        }
        current = current->next[0];  // Move to the next level
    }
    printf("-->NULL");
    printf("\n");
}

void display_all_levels(t_d_list * list) {
    for (int i = 0; i < list->max_level; i++) {
        display_cells(list, i);
    }
}
