/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "fichier.h"
// ******************************************************************************** //



// ***********************************CELL**************************************** //

// Création d'une cellule
t_d_cell* create_cell(int val, int lvl) {
    // Allocation mémoire pour la structure
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));

    // Initialisation des champs de la structure
    cell->value = val;
    cell->level = lvl;

    // Allocation mémoire pour le tableau de pointeurs 'next'
    cell->next = (t_d_cell**)calloc(lvl, sizeof(t_d_cell*));

    // Initialisation des éléments du tableau 'next' à NULL
    for(int i = 0; i < lvl; i++) {
        cell->next[i] = NULL;
    }

    // Retourne le pointeur vers la cellule nouvellement créée
    return cell;
}




// ***********************************LISTE**************************************** //

t_d_list * create_list(int max_lvl) {
    // Allocate memory for the list structure
    t_d_list * list = (t_d_list *)malloc(sizeof(t_d_list));

    // Set the maximum number of levels for the list
    list->max_level = max_lvl;

    // Set the head of the list to NULL (empty list)
    list->heads = NULL;

    // Return the pointer to the created list
    return list;
}

void cell_atHead(t_d_list* list, t_d_cell* cell) {
    int levelsToSet;

    if (cell->level > list->max_level) {
        levelsToSet = list->max_level;
    } else {
        levelsToSet = cell->level;
    }
    cell->level = levelsToSet;

    for (int i = 0; i < levelsToSet; ++i) {
        cell->next[i] = list->heads;
    }

    list->heads = cell;
}

// Function to display all cells at a specific level in the list
void display_cells(t_d_list * list, int level) {
    printf("[list head_%d @-]", level);

    // Traverse the list and display cells at the specified level
    t_d_cell *current = list->heads;
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

void display_all_levels_aligned(t_d_list* list) {

    for (int i = 0; i < list->max_level; i++) {
        printf("[list head_%d @-]", i);

        t_d_cell *current = list->heads;
        while (current != list->heads) {
            if (i < current->level) {
                printf("-->[ %-4d|@-]", current->value);
            } else {
                printf("-------------");
            }
            current = current->next[0];
        }
        printf("-->NULL");
        printf("\n");
    }
}

// Function to insert a cell at the correct position to keep the list sorted
void insert_cell(t_d_list * list, t_d_cell * cell) {

    int levelsToSet = (cell->level > list->max_level) ? list->max_level : cell->level;
    cell->level = levelsToSet;

    // Special case: If the list is empty or the new cell should be the new head
    if (list->heads == NULL || cell->value < list->heads->value) {
        for (int i = 0; i < levelsToSet; ++i) {
            cell->next[i] = list->heads;
        }
        list->heads = cell;
        return;
    }

    // Traverse the list to find the correct position to insert the cell
    t_d_cell * current = list->heads;
    t_d_cell * previous = NULL;

    while (current != NULL && current->value < cell->value) {
        previous = current;
        current = current->next[0];
    }

    // Insert the cell at the correct position
    for (int i = 0; i < levelsToSet; ++i) {
        cell->next[i] = current;
    }

    if (previous != NULL) {
        previous->next[0] = cell;
    }
}

