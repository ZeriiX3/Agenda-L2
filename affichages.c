/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */

#include "affichages.h"
#include "models.h"

#include <stdio.h>


// FONCTION POUR AFFICHER LE MENU DE LA PARTIE 1 SUR LE MAIN
void menu_part1() {
    // PARTIE 1
    printf("PARTIE 1\n");

    int nb_cell, val, max_niv, niv;
    printf("Nombre de cellules que vous voulez : \n");
    scanf("%d", &nb_cell);
    printf("Niveau max de la liste : \n");
    scanf("%d", &max_niv);

    t_d_list *main_list = create_list(max_niv);

    for (int i = 0; i < nb_cell; i++) {
        printf("La valeur que vous voulez inserer dans la liste : \n");
        scanf("%d", &val);
        printf("Au combien-ieme niveau : \n");
        scanf("%d", &niv);
        while (niv > max_niv || niv == 0) {
            printf("Niveau demande incorrect !\n");
            printf("Ressaisissez un niveau pour la cellule de valeur %d :\n", val);
            scanf("%d", &niv);
        }
        t_d_cell *cell = create_cell(val, niv);
        insert_cell(main_list, cell);

    }

    // Affichage de tous les niveaux de la liste
    display_list(main_list);

    free(main_list);

}



// FONCTION POUR AFFICHER LE MENU DE LA PARTIE 3 SUR LE MAIN
void menu_part3(t_input_list * contact_list) {

    char run_part3 = '1';

    while (run_part3 == '1') {

        printf("============\n");
        printf("APPLICATION\n");
        printf("============\n");
        printf("\n");
        printf("Il y a %d contact(s) dans la liste\n", get_number_of_contacts(contact_list));
        printf("Veuillez selectionner une fonctionnalite\n");
        printf("1) Ajouter un contact\n");
        printf("2) Chercher un contact\n");
        printf("3) Afficher les contacts\n");
        printf("4) Ajouter un rendez-vous\n");
        printf("5) Affichez les rendez vous\n");
        printf("6) Quitter\n");

        char choix = 0;
        char input[15];  // Vous pouvez ajuster la taille en fonction de vos besoins
        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c", &choix);

        switch (choix) {

            case '1': {
                menu_add_contact(contact_list);
                break;
            }
            case '2': {
                menu_find_contact(contact_list);
                break;
            }
            case '3': {
                menu_display_all_contacts(contact_list);
                break;
            }
            case '4' : {
                menu_add_appointment(contact_list);
                break;
            }
            case '5': {
                menu_display_appointment(contact_list);
                break;
            }
            case '6': {
                run_part3 = '0';
                break;
            }
            default: {
                printf("Entrez un choix valide\n");
                break;
            }
        }
    }
}



// FONCTIONS


void menu_display_contact(t_contact* contact) {

    printf("Nom : %s\n", contact->nom_de_famille);
    printf("Prenom : %s\n", contact->prenom);

    return;
}

void menu_add_contact(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    printf("Entrer le prenom du contact : ");
    char* first_name = scan_string();

    t_contact* contact = create_contact(first_name, last_name);

    insert_input(contact, input_list);

    return;
}


void menu_find_contact(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
    } else {
        menu_display_contact(input->contact);
    }

    return;
}

void menu_display_all_contacts(t_input_list* input_list) {

    // Display contact on level 0
    t_input* tmp = input_list->tetes[0];

    if(tmp == NULL) {
        printf("Aucun contact dans la liste.\n");
        return;
    }

    while(tmp != NULL) {
        menu_display_contact(tmp->contact);
        tmp = tmp->suivant;
    }

    return;
}

void menu_add_appointment(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas, voulez vous le creer (0 = NON ; 1 = OUI)\n");
        int choice;
        scanf("%d", &choice);

        if((int) choice  == 1) {
            menu_add_contact(input_list);
        } else {
            return;
        }
    }


    input = find_contact(last_name, input_list);

    printf("Entrer l'objet du rendez-vous : ");
    char* object = scan_string();

    printf("Entrer l'heure du rendez-vous : ");
    int hour;
    scanf("%d", &hour);

    while(hour < 0 || hour > 23)
    {
        printf("L'heure doit etre comprise entre 0 et 23.\n");
        scanf("%d",&hour);
    }

    printf("Entrer les minutes du rendez-vous : ");
    int minute;
    scanf("%d", &minute);

    while(minute < 0 || minute > 59)
    {
        printf("Les doivent etre comprise entre 0 et 59.\n");
        scanf("%d",&minute);
    }

    printf("Entrer le jour du rendez-vous : ");
    int day;
    scanf("%d", &day);

    if(day < 1 || day > 31) {
        printf("Le jour doit être compris entre 1 et 31.\n");
        return;
    }

    printf("Entrer le mois du rendez-vous : ");
    int month;
    scanf("%d", &month);

    if(month < 1 || month > 12) {
        printf("Le mois doit être compris entre 1 et 12.\n");
        return;
    }

    printf("Entrer l'annee du rendez-vous : ");
    int year;
    scanf("%d", &year);

    if(year < 0) {
        printf("L'année doit être supérieure à 0.\n");
        return;
    }

    t_appointment* appointment = create_appointment(object, hour, minute, day, month, year);
    insert_appointment(appointment, input);

    return;
}

void menu_display_appointment(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();
    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
        return;
    }

    t_appointment* tmp = input->rendez_vous;

    while(tmp != NULL) {
        printf("Objet : %s\n", tmp->objet);
        printf("Heure : %d:%d\n", tmp->heure, tmp->minute);
        printf("Date : %d/%d/%d\n", tmp->jour, tmp->mois, tmp->annee);
        tmp = tmp->suivant;
    }
    return;
}

int get_number_of_contacts(t_input_list* input_list) {

    int number_of_contacts = 0;

    for(int i = 0; i < input_list->niveau_max; i++) {

        t_input* tmp = input_list->tetes[i];

        while(tmp != NULL) {
            number_of_contacts++;
            tmp = tmp->suivant;
        }
    }
    return number_of_contacts;
}

