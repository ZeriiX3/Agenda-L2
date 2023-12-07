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

void display_list(t_d_list * list) {
    for (int i = 0; i < list->max_level; i++) {
        display_cells(list, i);
    }
}

void display_list_aligned(t_d_list* list) {

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

void insert_cell(t_d_list* list, t_d_cell* cell) {
    t_d_cell* temp = NULL;
    int i = 0;

    // Vérifie si on peut insérer en tête
    if (list->heads == NULL || list->heads->value > cell->value) {
        cell_atHead(list, cell);
        printf("XU\n");

    } else {

        temp = list->heads;

        // Trouve l'emplacement correct pour insérer la cellule de manière croissante
        while (temp->next[i] != NULL && temp->next[i]->value < cell->value) {
            printf("XU3\n");
            temp = temp->next[i];
            printf("apagnan\n");
        }

        printf("XU4\n");
        // Insère la cellule à la bonne position
        cell->next[i] = temp->next[i];
        temp->next[i] = cell;

    }
}

