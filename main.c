/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include "fichier.h"
#include "timer.h"
// ******************************************************************************** //


// BOUCLE PRINCIPALE

int main() {

    // TEST SOUTENANCE





    // PARTIE 1 ********************************************************//

    /*printf("PARTIE 1\n\n");
    // Création d'une cellule avec 3 niveaux différents
    t_d_cell *cell5 = create_cell(5, 5);
    t_d_cell *cell4 = create_cell(4, 4);
    t_d_cell *cell3 = create_cell(3, 3);
    t_d_cell *cell2 = create_cell(2, 2);
    t_d_cell *cell1 = create_cell(1, 1);

    // Création d'une liste avec un maximum de 6 niveaux
    t_d_list *main_list = create_list(6);

    // Insertion des cellules (tous les cas)
    insert_cell(main_list, cell3);
    insert_cell(main_list, cell1);
    insert_cell(main_list, cell5);
    insert_cell(main_list, cell4);
    insert_cell(main_list, cell2);

    // Affichage de tous les niveaux de la liste
    display_list(main_list);

    // Libération de la mémoire
    free(cell1);
    free(cell2);
    free(cell3);
    free(cell4);
    free(cell5);
    free(main_list);
*/


    // PARTIE 2 ********************************************************//
    printf("PARTIE 2\n\n");

    int niv;
    printf("Entrez le niveau pour la liste :  ");
    printf("\n");
    scanf("%d", &niv);

    // Création des listes avec les levels demandés
    t_d_list* list_part2 = create_levels_list(niv);
    display_levels_list(list_part2);


    //****************************** RECHERCHE *************************//

    int val;
    printf("\nEntrez la valeur a chercher dans la liste :  ");
    scanf("%d", &val);

    // RECHERCHE CLASSIQUE

    int resultat_classique = search_cell_classique(list_part2,val);
    printf("\n[RECHERCHE CLASSIQUE]--> ");

    if (resultat_classique == 1) {
        printf("La valeur %d a ete trouve", val);
    } else {
        printf("La valeur %d n'est pas dans la liste", val);
    }

    // RECHERCHE OPTIMALE

    int resultat_opti = search_cell_optimal(list_part2,val);
    printf("\n[RECHERCHE OPTIMALE]---> ");

    if (resultat_opti == 1) {
        printf("La valeur %d a ete trouve", val);
    } else {
        printf("La valeur %d n'est pas dans la liste", val);
    }


    // Mémoire
    free(list_part2);


    return 0;
}
