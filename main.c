/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <string.h>
#include "fichier.h"
#include "timer.h"
#include "models.h"
#include "affichages.h"
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
    /*
    printf("PARTIE 2\n\n");

    int niv;
    printf("Entrez le niveau pour la liste :  ");
    printf("\n");
    scanf("%d", &niv);

    // Création des listes avec les levels demandés
    t_d_list *list_part2 = create_levels_list(niv);
    display_levels_list(list_part2);


    //---**********************RECHERCHE *****************************/
    /*
    int val;
    printf("\nEntrez la valeur a chercher dans la liste :  ");
    scanf("%d", &val);


    // RECHERCHE CLASSIQUE

    startTimer();

    int resultat_classique = search_cell_classique(list_part2, val);
    printf("\n[RECHERCHE CLASSIQUE]--> ");

    if (resultat_classique == 1) {
        printf("La valeur %d a ete trouve\n", val);
    } else {
        printf("La valeur %d n'est pas dans la liste\n", val);
    }
    stopTimer();
    displayTime();
    printf("\n");

    // RECHERCHE OPTIMALE

    startTimer();

    int resultat_opti = search_cell_optimal(list_part2, val);
    printf("\n[RECHERCHE OPTIMALE]---> ");

    if (resultat_opti == 1) {
        printf("La valeur %d a ete trouve\n", val);
    } else {
        printf("La valeur %d n'est pas dans la liste\n", val);
    }

    stopTimer();
    displayTime();
    printf("\n");

*/


    // ------------------------------------------- BOUUUUUCLEEEEE -------------------------------------------
    /*
    int resultat_classique = search_cell_classique(list_part2, val);
    // Boucle pour toutes les valuers
    printf("BOUCLE CLASSIQUE\n");
    startTimer();
    for (int i = 1; i < val; i++) {
        resultat_classique = search_cell_classique(list_part2, val);
    }
    stopTimer();
    displayTime();
    printf("\n");

    printf("BOUCLE OPTI\n");
    startTimer();
    for (int i = 1; i < val; i++) {
        resultat_classique = search_cell_optimal(list_part2, val);
    }
    stopTimer();
    displayTime();
    printf("\n");

    */

    // Mémoire
    //free(list_part2);




    // PARTIE 3*************************/

    int run_app = 1;

    while (run_app == 1) { // BOUCLE PRINCIPALE

        printf("======================");
        printf("CHOISSISSEZ LA PARTIE");
        printf("======================");
        printf("1. PARTIE 1 (Test)\n");
        printf("2. PARTIE 2 (Test de la liste levels)\n");
        printf("3. PARTIE 2 (Recherche avec timer)\n");
        printf("4. AGENDA (PARTIE 3\n");
        printf("5. Quitter\n");

        int choix_part;
        scanf("%d",&choix_part);

        switch (choix_part) {

            case 1: {   // PARTIE 1 (Test)
                break;
            }

            case 2: {
                break;  // PARTIE 2 (Test de la liste levels)
            }

            case 3: {
                break;  // PARTIE 2 (Recherche avec timer)
            }

            case 4: {   // AGENDA (PARTIE 3)
                t_input_list* contact_list = create_input_list(4);
                menu_part3(contact_list);
                break;
            }

            case 5: {
                run_app = 0;
                break;
            }

            default: {
                printf("Entrez un chiffre valide");
            }
        }

    }




    return 0;
}




