/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include "fichier.h"
#include "models.h"
#include "affichages.h"
#include "timer.h"
// ******************************************************************************** //


// BOUCLE PRINCIPALE

int main() {
    /*
    // On a, à la fin, l'algorithme pour mesurer le temps d'exécution pour l'enregistrer dans un fichier

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
                printf("Entrez le niveau pour la liste (Evitez au dessus du lvl 14, car on print la liste):  ");
                printf("\n");
                scanf("%d", &niv);

                // Création des listes avec les levels demandés
                t_d_list *list_part2 = create_levels_list(niv);
                display_levels_list(list_part2);

                //---**********************RECHERCHE *****************************
                int val;
                printf("\nEntrez la valeur a chercher dans la liste :  ");
                scanf("%d", &val);

                printf("On va faire 10000 recherches\n");
                startTimer();
                for (int j = 0; j <= 10000; ++j) {
                    search_cell_classique(list_part2,val);
                }
                stopTimer();

                char *time_classique = getTimeAsString();

                startTimer();
                for (int j = 0; j <= 10000; ++j) {
                    search_cell_optimal(list_part2,val);
                }
                stopTimer();
                char *time_opti = getTimeAsString();

                printf("Valeur = %d | Classique: %s  Optimal: %s \n", val, time_classique, time_opti);
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
    */

    // Algorithme de recherche ( Je le lance sans le code principal avec des /* ~~~ */ )
    // PS: l'algo prend un peu de temps...

    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level = 6;
    char *time_lvl0;
    char *time_all_levels;

    // Recheche d'une liste à niveau 6 à 14
    while (level != 14) {
        t_d_list *list_timer_test = create_levels_list(level);
        startTimer();
        for (int j = 0; j <= 10000; ++j) {
            search_cell_classique(list_timer_test,100000);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();

        startTimer();
        for (int j = 0; j <= 10000; ++j) {
            search_cell_optimal(list_timer_test,100000);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level += 1;
    }
    fclose(log_file);


    return 0;
}


