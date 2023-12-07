#include <stdio.h>
#include "fichier.h"

int main() {
    printf("Hello, World!\n");

    // Création d'une cellule avec 3 niveaux différents
    t_d_cell *cell5 = create_cell(50, 5);
    t_d_cell *cell4 = create_cell(40, 4);
    t_d_cell *cell3 = create_cell(30, 3);
    t_d_cell *cell2 = create_cell(20, 2);
    t_d_cell *cell1 = create_cell(10, 1);

    // Création d'une liste avec un maximum de 6 niveaux
    t_d_list *main_list = create_list(6);

    // Insertion des cellules (tous les cas)
    insert_cell(main_list, cell3);
    insert_cell(main_list, cell1);
    insert_cell(main_list, cell5);
    insert_cell(main_list, cell4);


    printf("3\n");
    // Affichage de tous les niveaux de la liste
    display_list(main_list);

    /*
    printf("4\n");
    // Affichage de tous les niveaux de la liste avec alignement
    display_list_aligned(main_list);*/


    // Libération de la mémoire
    free(cell1);
    free(cell2);
    free(cell3);
    free(cell4);
    free(cell5);
    free(main_list);

    int n;

    // Demander à l'utilisateur d'entrer la valeur de n
    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    // Création d'une liste avec un maximum de 2^n-1 niveaux
    t_d_list *list = create_list2(n);

    // Ajout des cellules à la liste
    for (int i = 1; i <= (1 << n) - 1; i++) {
        // Création d'une cellule avec i comme valeur et n comme niveau
        t_d_cell *cell = create_cell2(i, n);
        // Insertion de la cellule dans la liste
        insert_cell(list, cell);
    }

    // Affichage de tous les niveaux de la liste
    display_list2(list);

    // Libération de la mémoire (à adapter selon vos besoins)
    // ...

    return 0;
}

