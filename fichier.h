/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


#ifndef GESTION_AGENDA_FICHIER_H
#define GESTION_AGENDA_FICHIER_H

// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <stdlib.h>
// ******************************************************************************** //


// ***********************************STRUCT CELL**************************************** //

typedef struct s_d_cell {
    int value;
    int level;
    struct s_d_cell **next;
}t_d_cell;

// Création d'une cellule
t_d_cell* create_cell(int val, int lvl);


// ***********************************LISTE**************************************** //

// Structure
typedef struct s_d_list {
    int max_level;
    t_d_cell **heads;
}t_d_list;


// Fonctions

// Création d'une liste
t_d_list* create_list(int max_lvl);

// Insérer une cellule à la tête de la liste
void cell_atHead(t_d_list* list, t_d_cell* cell);

// Permet l'affichage d'une cellule selon le niveau
void display_cells(t_d_list * list, int level);

// Permet d'afficher la liste
void display_list(t_d_list * list);

// Permet d'insérer une cellule de manière à garder la liste croissante
void insert_cell(t_d_list* list, t_d_cell* cell);


// *********************************** LEVELS **************************************** //

// Créer la liste demandée dans la partie 2
t_d_list* create_levels_list(int niv);

// Affichage de la liste demandée
void display_levels_list(t_d_list* list);

// *********************************** SEARCH **************************************** //

// Fonctions de recherche
int search_cell_classique(t_d_list* list, int value);

int search_cell_optimal(t_d_list* list, int value);


#endif //GESTION_AGENDA_FICHIER_H
