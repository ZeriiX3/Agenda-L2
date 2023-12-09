/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <string.h>
#include "fichier.h"
#include "models.h"
#include "affichages.h"
#include "timer.h"
// ******************************************************************************** //


// BOUCLE PRINCIPALE

int main() {

    // TEST SOUTENANCE



    char run_app = '1';

    while (run_app == '1') { // BOUCLE PRINCIPALE

        printf("\n");
        printf("======================\n");
        printf("CHOISSISSEZ LA PARTIE\n");
        printf("======================\n");
        printf("1) PARTIE 1 (Test)\n");
        printf("2) PARTIE 2 (Test de la liste levels et timer)\n");
        printf("3) AGENDA (PARTIE 3)\n");
        printf("4) Quitter\n");

        char choix_part = '0';
        char input[15];  // Pour lire toute la ligne d'entrée de l'utilisateur et pas chaque caractère, ce qui créer une boucle
        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c", &choix_part);


        switch (choix_part) {

            case '1': {   // PARTIE 1 (Test)
                menu_part1();
                break;
            }
            case '2': {
                int niv;
                printf("Entrez le niveau pour la liste :  ");
                printf("\n");
                scanf("%d", &niv);

                // Création des listes avec les levels demandés
                t_d_list *list_part2 = create_levels_list(niv);
                display_levels_list(list_part2);

                //---**********************RECHERCHE *****************************
                int val;
                printf("\nEntrez la valeur a chercher dans la liste :  ");
                scanf("%d", &val);

                printf("BOUCLE CLASSIQUE\n");
                int resultat_classique = search_cell_classique(list_part2, val);

                startTimer();


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
                break;
            }
                case '3': {   // AGENDA (PARTIE 3)
                    t_input_list *contact_list = create_input_list(4);
                    menu_part3(contact_list);
                    break;
                }
                case '4': {
                    run_app = '0';
                    break;
                }
                default: {
                    printf("Entrez un chiffre valide");
                }

            }

        }

        return 0;
    }


