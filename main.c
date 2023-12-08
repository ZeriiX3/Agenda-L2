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
    /*printf("PARTIE 2\n\n");

    int niv;
    printf("Entrez le niveau pour la liste :  ");
    printf("\n");
    scanf("%d", &niv);

    // Création des listes avec les levels demandés
    t_d_list* list_part2 = create_levels_list(niv);
    display_levels_list(list_part2);


    /**********************RECHERCHE *****************************/
    /*
    int val;
    printf("\nEntrez la valeur a chercher dans la liste :  ");
    scanf("%d", &val);


    // RECHERCHE CLASSIQUE

    startTimer();

    int resultat_classique = search_cell_classique(list_part2,val);
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

    int resultat_opti = search_cell_optimal(list_part2,val);
    printf("\n[RECHERCHE OPTIMALE]---> ");

    if (resultat_opti == 1) {
        printf("La valeur %d a ete trouve\n", val);
    } else {
        printf("La valeur %d n'est pas dans la liste\n", val);
    }

    stopTimer();
    displayTime();
    printf("\n");


    int resultat_classique = search_cell_classique(list_part2,val);
    // Boucle pour toutes les valuers
    printf("BOUCLE CLASSIQUE\n");
    startTimer();
    for (int i = 1; i < val; i++) {
        resultat_classique = search_cell_classique(list_part2,val);
    }
    stopTimer();
    displayTime();
    printf("\n");

    printf("BOUCLE OPTI\n");
    startTimer();
    for (int i = 1; i < val; i++) {
        resultat_classique = search_cell_optimal(list_part2,val);
    }
    stopTimer();
    displayTime();
    printf("\n");
    */



    // Mémoire
    //free(list_part2);


    /* PARTIE 3*************************/

    t_input_list* contact_list = create_input_list(4);

    int app_state = 1;

    while (app_state == 1) {

        printf("BONJOUR\n");
        printf("Il y a %d contact(s) dans la liste\n", get_number_of_contacts(contact_list));
        printf("Veuillez selectionner une fonctionnalite\n");
        printf("1. Ajouter un contact\n");
        printf("2. Chercher un contact\n");
        printf("3. Afficher les contacts\n");
        printf("4. Ajouter un rendez-vous\n");
        printf("5. Affichez les rendez vous\n");
        printf("6. Quitter\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                menu_add_contact(contact_list);
                break;
            }

            case 2: {
                menu_find_contact(contact_list);
                break;
            }

            case 3: {
                menu_display_all_contacts(contact_list);
                break;
            }

            case 4 : {
                menu_add_appointment(contact_list);
                break;
            }

            case 5: {
                menu_display_appointment(contact_list);
                break;
            }

            case 6: {
                app_state = 0;
                break;
            }

            default: {

                printf("Choix invalide\n");
                break;
            }
        }
    }

    return 0;
}

// TIMER


