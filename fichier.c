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

    // Allocation mémoire
    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));

    list->max_level = max_lvl;
    // Initialisation d'un tableau de pointeur cellules
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_lvl);

    // Tout mettre à NULL pour éviter les potentiels bug
    for(int i = 0; i < max_lvl; i++) {
        list->heads[i] = NULL;
    }
    return list;
}

void cell_at_head(t_d_list* list, t_d_cell* cell) {
    int temp;

    // Dans le cas où level > max lvl possible de la liste
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

    // Traverse la liste et affiche la cellule
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
        cell_at_head(list, cell);

    } else {
        temp = list->heads[i];

        // Trouve l'emplacement correct pour insérer la cellule de manière croissante en parcourant la liste
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
    int *levels = (int*)malloc(cell_number * sizeof(int));


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
    t_d_list* level_list = create_list(niv);

    // Boucle pour créer et ajouter une cellule à la liste
    for (int k = 0; k < cell_number; k++) {
        t_d_cell *cell = create_cell(k + 1, levels[k]); // Cellule en fonction du tableau levels
        insert_cell(level_list, cell);  // Insertion de la cellule qui vient d'être créée
    }
    return level_list;

}

// On affiche juste la liste
void display_levels_list(t_d_list* list) {
    // Affichage de la liste
    display_list(list);
}

// Recherche classique dans le niveau 0
int search_cell_classique(t_d_list* list, int value) {
    // Début de la recherche à partir du premier élément du niveau 0
    t_d_cell* current = list->heads[0];

    // Parcours de la liste jusqu'à la fin ou jusqu'à ce que la valeur actuelle soit supérieure à la valeur recherchée
    while (current != NULL && current->value < value) {
        current = current->next[0];
    }

    // Vérification si la cellule avec la valeur recherchée a été trouvée
    if (current != NULL && current->value == value) {
        return 1;    // La cellule avec la valeur recherchée a été trouvée
    } else {
        return 0;    // La cellule n'a pas été trouvée
    }
}

// La recherche n'est pas celle demandée... mais nous avons tenté
// Recherche dichotomique au niveau le plus élevé
int search_cell_optimal(t_d_list* list, int value) {
    // Initialisation du niveau courant au niveau le plus élevé
    int currentLevel = list->max_level - 1;

    // Début de la recherche à partir du premier élément du niveau le plus élevé
    t_d_cell* current = list->heads[currentLevel];

    // Boucle principale pour parcourir les niveaux de la liste
    while (currentLevel >= 0) {
        // Parcours de la liste jusqu'à la fin ou jusqu'à ce que la valeur actuelle soit supérieure à la valeur recherchée
        while (current != NULL && current->value < value) {
            current = current->next[currentLevel];
        }

        // Vérification si la cellule avec la valeur recherchée a été trouvée
        if (current != NULL && current->value == value) {
            return 1;    // La cellule avec la valeur recherchée a été trouvée
        } else {
            currentLevel--; // Passage au niveau inférieur
        }
    }

    return 0;    // La cellule n'a pas été trouvée
}
