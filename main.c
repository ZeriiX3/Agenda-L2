#include <stdio.h>
#include "fichier.h"

int main() {
    printf("Hello, World!\n");

    // Création d'une cellule avec 3 niveaux différents
    t_d_cell * cell5 = create_cell(50, 2);
    t_d_cell * cell4 = create_cell(40, 3);
    t_d_cell * cell3 = create_cell(30, 5);
    t_d_cell * cell2 = create_cell(20, 1);
    t_d_cell * cell1 = create_cell(10, 3);

    // Création d'une liste avec un maximum de 6 niveaux
    t_d_list * main_list = create_list(6);

    // Insertion des cellules (tous les cas)
    insert_cell(main_list,cell3);
    insert_cell(main_list,cell1);
    insert_cell(main_list,cell5);
    insert_cell(main_list,cell4);
    insert_cell(main_list,cell2);


    // Affichage de tous les niveaux de la liste
    display_list(main_list);


    // Libération de la mémoire
    free(cell1);
    free(cell2);
    free(cell3);
    free(cell4);
    free(cell5);
    free(main_list);

    return 0;
}
