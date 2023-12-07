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
        }else{
            printf("-----------");
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
// Modifier la création d'une liste
t_d_list *create_list2(int max_lvl) {
    // Allocation mémoire pour la structure de la liste
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));

    // Affecter le nombre exact de niveaux pour la liste (n niveaux)
    list->max_level = max_lvl;

    // Initialiser le pointeur de tête à NULL (liste vide au départ)
    list->heads = NULL;

    // Retourne le pointeur vers la liste nouvellement créée
    return list;

}
void cell_atHead2(t_d_list *list, t_d_cell *cell) {
    int temp;

    // Assurez-vous que nous ne dépassons pas le nombre maximal de niveaux
    if (cell->level > list->max_level) {
        temp = list->max_level;
    } else {
        temp = cell->level;
    }

    cell->level = temp;

    // Maintenant, ajustez la manière dont les niveaux sont gérés
    for (int i = 0; i < temp; ++i) {
        cell->next[i] = list->heads;
        list->heads = cell;
    }
}



// Modifier la création d'une cellule
t_d_cell *create_cell2(int val, int lvl) {
    // Allocation mémoire pour la structure
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));

    // Initialisation des champs de la structure
    cell->value = val;
    cell->level = lvl;

    // Allocation mémoire pour le tableau de pointeurs 'next'
    cell->next = (t_d_cell **)calloc(lvl, sizeof(t_d_cell *));

    // Initialisation des éléments du tableau 'next' à NULL
    for (int i = 0; i < lvl; i++) {
        // Ajouter la contrainte de pointage sur deux cellules du niveau précédent
        if (i % 2 == 0 && i > 0) {
            cell->next[i] = cell->next[i - 1];
        } else {
            cell->next[i] = NULL;
        }
    }

    // Retourne le pointeur vers la cellule nouvellement créée
    return cell;
}
void display_cells2(t_d_list *list, int level) {
    printf("[list head_%d @-]", level);

    // Traverse the list and display cells at the specified level
    t_d_cell *current = list->heads;
    int count = 1;  // Commencez le compteur à 1
    int displayCount = 1;

    while (current != NULL) {
        if (level < current->level) {
            printf("-->[ %d|@-]", current->value);
            if (count < displayCount) {
                printf("---------------");
            }
            count = (count + 1) % (displayCount + 1);  // Ajustez le modulo en conséquence
        } else {
            printf("------------------------------------------------------------------------------->NULL");
            count = 1;  // Réinitialisez le compteur pour le prochain niveau
        }

        current = current->next[0];  // Move to the next level

        // Met à jour le compteur d'affichage en fonction de la puissance de 2
        if (count == 1) {
            displayCount *= 2;
        }
    }

    printf("\n");
}





void display_list2(t_d_list *list) {
    for (int i = 0; i < list->max_level; i++) {
        if (i < list->max_level - 1) {  // Utiliser le niveau maximum de la liste
            display_cells(list, i);
        } else {
            printf("[list head_%d @-]------------------------------------------------------------------------------->NULL\n", i);
        }
    }
}
