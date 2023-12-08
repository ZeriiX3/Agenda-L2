/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include "fichier.h"
#include <math.h>
// ******************************************************************************** //



// *********************************** CELL **************************************** //

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




// *********************************** LISTE **************************************** //

t_d_list *create_list(int max_lvl) {

    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));

    list->max_level = max_lvl;
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_lvl);

    for(int i = 0; i < max_lvl; i++) {

        list->heads[i] = NULL;

    }

    return list;
}

void cell_atHead(t_d_list* list, t_d_cell* cell) {
    int temp;

    // dans le cas où level > max lvl possible de la liste
    if (cell->level > list->max_level) {
        temp = list->max_level;
    } else {
        temp = cell->level;
    }
    cell->level = temp;

    for (int i = 0; i < temp; ++i) {
        cell->next[i] = list->heads[0];
    }
    list->heads[0] = cell;
}

// Affichage d'une cellule part rapport à son niveau
void display_cells(t_d_list * list, int level) {
    printf("[list head_%d @-]", level);

    // Traverse the list and display cells at the specified level
    t_d_cell *current = list->heads[0];

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

// Boucle pour display_cell
void display_list(t_d_list * list) {

    for (int i = 0; i < list->max_level; i++) {
        display_cells(list, i);
    }
}

// Insert une cellule, en faisant en sorte que la liste reste croissante
void insert_cell(t_d_list* list, t_d_cell* cell) {

    t_d_cell* temp = NULL;
    int i = 0;

    // Vérifie si on peut insérer en tête
    if (list->heads[i] == NULL || list->heads[i]->value > cell->value) {
        cell_atHead(list, cell);

    } else {

        temp = list->heads[i];

        // Trouve l'emplacement correct pour insérer la cellule de manière croissante
        while (temp->next[i] != NULL && temp->next[i]->value < cell->value) {
            temp = temp->next[i];
        }

        // Insère la cellule à la bonne position
        cell->next[i] = temp->next[i];
        temp->next[i] = cell;

    }
}



// *********************************** LEVELS **************************************** //


// Fonctions pour créer la liste avec 2^n - 1 cellules, avec les valuers de 1 à 2^n -1
t_d_list* create_levels_list(int niv) {

    // PARTIE TABLEAU
    int cell_number = pow(2, niv) - 1;  // Initialise le nombre de cellules
    int levels[cell_number];

    // Initialise un tableau de 1 (pas 0 car le 1 = premier et pas niveau 1)
    for (int i = 0; i < cell_number; i++) {
        levels[i] = 1;
    }

    // + 1 avec des sauts qui double
    int pas = 2;
    while (pas <= cell_number){
        for (int j = pas - 1; j < cell_number; j += pas) {
            levels[j] += 1;
        }
        pas *= 2;
    }

    // PARTIE INSERTION
    int temp = niv;
    t_d_list* level_list = create_list(niv);


    // Boucle pour créer et ajouter une cellule à la liste

    for (int k = 0; k < cell_number; k++) {
        t_d_cell *cell = create_cell(k + 1, levels[k]);
        insert_cell(level_list, cell);
    }
    return level_list;

}

void display_levels_list(t_d_list* list) {
    // Affichage de la liste
    display_list(list);
}



// Recherche




int search_cell_classique(t_d_list* list, int value) {

    t_d_cell *temp = list->heads[0];

    while(temp != NULL && temp->value < value) {
        temp = temp->next[0];
    }

    if(temp != NULL && temp->value == value) {
        return 1;
    } else {
        return 0;
    }
}

/*
int search_cell_optimal(t_d_list* list, int value) {
    t_d_cell* temp = list->heads;

    // Commence à partir du niveau maximal
    for (int i = list->max_level - 1; i >= 0; i--) {
        // Traverse le niveau actuel jusqu'à ce que la valeur soit trouvée ou dépassée
        while (temp != NULL && temp->value < value) {
            printf("Level %d: Moving to next cell with value %d\n", i, temp->value);
            temp = temp->next[i];

        }

        // Si la valeur est trouvée, retourne 1
        if (temp != NULL && temp->value == value) {
            printf("Value %d found at level %d\n", value, i);
            return 1;
        }

        // Réinitialise temp pour le niveau suivant
        temp = list->heads;
    }

    // La valeur n'a pas été trouvée dans la liste, retourne 0
    printf("Value %d not found in the list\n", value);
    return 0;
}*/

int search_cell_optimal(t_d_list* list, int value) {

    for (int i = list->max_level - 1; i >= 0; i--) {

        t_d_cell *temp = list->heads[i];

        while (temp != NULL) {
            if (temp->value == value) {
                return 1;
            } else if (temp->value < value) {
                temp = temp->next[i];
            } else {
                break;  // Sortir si la valeur dépasse celle recherchée
            }
        }
    }

    return 0;
}




/*
t_d_cell* search_cell_optimal(int value, t_d_list* list) {

    t_d_cell *tmp = list->heads[list->max_level - 1];

    for(int i = list->max_level - 1; i >= 0; i--) {
        while(tmp != NULL && tmp->value < value) {

            tmp = tmp->next[i];
        }

        if(tmp != NULL && tmp->value == value) {
            return tmp;

        }

        tmp = list->heads[i];

    }

    return NULL;
}*/
