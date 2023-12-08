/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
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


    //****************************** RECHERCHE *****************************/
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

    /*
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

    /*
     * /*
    // read the text file in ../libs/data/noms2008nat_txt.txt in wich each line is a lastName, take 1000 lastName randomly and add them to the list
    FILE *file = fopen("../libs/data/noms2008nat_txt.txt", "r");
    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        if (i < 1000) {
            char *lastName = malloc(sizeof(char) * 256);
            strcpy(lastName, line);
            lastName[strlen(lastName) - 1] = '\0';
            t_contact *contact = create_contact("John", lastName);
            insert_input(contact, MAIN_LIST);
            i++;
        }
    }

    fclose(file);
     */

    t_input_list* MAIN_LIST = create_input_list(4);
    int app_state = 1;

    while (app_state == 1) {

        scanf("");

        printf("MENU\n");
        printf("%d contacts dans la liste\n", get_number_of_contacts(MAIN_LIST));
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
                menu_add_contact(MAIN_LIST);
                break;
            }

            case 2: {
                menu_find_contact(MAIN_LIST);
                break;
            }

            case 3: {
                menu_display_all_contacts(MAIN_LIST);
                break;
            }

            case 4 : {
                menu_add_appointment(MAIN_LIST);
                break;
            }

            case 5: {
                menu_display_appointment(MAIN_LIST);
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


