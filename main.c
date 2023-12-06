#include <stdio.h>
#include "fichier.h"

int main() {
    printf("Hello, World!\n");

    // Création d'une cellule avec 3 niveaux
    t_d_cell * cell1 = create_cell(10, 1);
    t_d_cell * cell2 = create_cell(20, 2);
    t_d_cell * cell3 = create_cell(30, 3);

    // Création d'une liste avec un maximum de 4 niveaux
    t_d_list * main_list = create_list(4);


    // Insertion de cellules dans la liste
    cell_atHead(main_list, cell1);
    cell_atHead(main_list, cell2);
    cell_atHead(main_list, cell3);

    printf("2\n");
    // Affichage des cellules à un niveau donné
    display_cells(main_list, 1);

    printf("3\n");
    // Affichage de tous les niveaux de la liste
    display_all_levels(main_list);

    printf("4\n");
    // Affichage de tous les niveaux de la liste avec alignement
    display_all_levels_aligned(main_list);

    // Insertion d'une cellule triée
    t_d_cell * cell4 = create_cell(15, 2);
    insert_cell(main_list, cell4);

    printf("5\n");
    // Affichage de tous les niveaux de la liste après l'insertion triée
    display_all_levels_aligned(main_list);

    /*
    // Libération de la mémoire
    free(cell1);
    free(cell2);
    free(cell3);
    free(cell4);
    free(main_list);*/

    return 0;
}

