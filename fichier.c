/* Project C: Gestion d'un agenda
Professeurs: Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "fichier.h"
#include <math.h>
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
    int temp;

    if (cell->level > list->max_level) {
        temp = list->max_level;
    } else {
        temp = cell->level;
    }
    cell->level = temp;

    for (int i = 0; i < temp; ++i) {
        cell->next[i] = list->heads;
    }
    list->heads = cell;
}


void display_cells(t_d_list * list, int level) {
    printf("[list head_%d @-]", level);

    // Traverse the list and display cells at the specified level
    t_d_cell *current = list->heads;
    while (current != NULL) {
        if (level < current->level) {
            printf("-->[ %d|@-]", current->value);
        }/*else{
            printf("-----------");
        }*/
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


void insert_cell(t_d_list* list, t_d_cell* cell) {

    t_d_cell* temp = NULL;
    int i = 0;

    // Vérifie si on peut insérer en tête
    if (list->heads == NULL || list->heads->value > cell->value) {
        cell_atHead(list, cell);
    } else {

        temp = list->heads;

        // Trouve l'emplacement correct pour insérer la cellule de manière croissante
        while (temp->next[i] != NULL && temp->next[i]->value < cell->value) {
            temp = temp->next[i];
        }

        // Insère la cellule à la bonne position
        cell->next[i] = temp->next[i];
        temp->next[i] = cell;

    }
}


void display_levels_list(int niv) {
    int cell_number = pow(2, niv)-1;
    int levels[cell_number];

    for (int i = 0; i< cell_number; i++) {
        levels[i] = 1;
    }

    int pas = 2;
    while (pas <= cell_number){
        for (int j = 0; j < cell_number; j += pas) {
            levels[j] += 1;
        }
        pas *= 2;
    }

    int temp = niv;
    t_d_list *main_list = create_list(niv);
    printf("apagnan\n");

    for (int k = 0; k < cell_number; k++) {
        printf("xu");
        t_d_cell *cell = create_cell(k, levels[k]);
        printf("feur");
        insert_cell(main_list,cell);
    }

    printf("azeaze\n");
    display_list(main_list);

}
