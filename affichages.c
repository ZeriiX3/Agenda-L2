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
void menu_part3(t_entry_list * contact_list) {

    char run_part3 = '1';

    while (run_part3 == '1') {

        printf("============\n");
        printf("APPLICATION\n");
        printf("============\n");
        printf("\n");
        printf("Il y a %d contact(s) dans la liste\n", get_nb_contact(contact_list));
        printf("Veuillez selectionner une fonctionnalite\n");
        printf("1) Ajouter un contact\n");
        printf("2) Chercher un contact\n");
        printf("3) Afficher les contacts\n");
        printf("4) Ajouter un rendez-vous\n");
        printf("5) Affichez les rendez vous\n");
        printf("6) Quitter\n");

        // Pour lire toute la ligne d'entrée de l'utilisateur et pas chaque caractère, ce qui créer une boucle pour chaque str
        char choix = 0;
        char input[15];
        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c", &choix);

        switch (choix) {

            case '1': {
                menu_ajout_contact(contact_list);
                break;
            }
            case '2': {
                menu_find_contact(contact_list);
                break;
            }
            case '3': {
                menu_display_all_contact(contact_list);
                break;
            }
            case '4' : {
                menu_add_rdv(contact_list);
                break;
            }
            case '5': {
                menu_display_rdv(contact_list);
                break;
            }
            case '6': {
                run_part3 = '0';
                break;
            }
            default: {
                printf("Choix valide\n");
                break;
            }
        }
    }
}


// FONCTIONS


void menu_ajout_contact(t_entry_list* entry_list) {

    printf("Entrer le nom de famille du contact : ");
    char* nom = scan_str();
    printf("Entrer le prenom du contact : ");
    char* prenom = scan_str();

    t_contact* contact = create_contact(prenom, nom);
    insert_entry(contact, entry_list);

}

void menu_display_contact(t_contact* contact) {
    printf("Nom : %s\n", contact->nom);
    printf("Prenom : %s\n", contact->prenom);
}

void menu_display_all_contact(t_entry_list* entry_list) {

    // Affiche les contacts au niveau 0
    t_entry* temp = entry_list->heads[0];
    if (temp == NULL) {
        printf("Aucun contact dans la liste.\n");
        return;
    }
    while(temp != NULL) {
        menu_display_contact(temp->contact);
        temp = temp->next;
    }
}

void menu_find_contact(t_entry_list* entry_list) {
    printf("Entrer le nom de famille du contact : ");
    char* nom = scan_str();

    t_entry* input = find_contact(nom, entry_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
    } else {
        menu_display_contact(input->contact);
    }
}


void menu_add_rdv(t_entry_list* entry_list) {

    printf("Entrer le nom de famille du contact : ");
    char* nom = scan_str();

    t_entry* input = find_contact(nom, entry_list);

    if (input == NULL) {
        printf("Le contact n'existe pas, voulez vous le creer (0 = NON ; 1 = OUI)\n");
        int choix;
        scanf("%d", &choix);

        if((int) choix == 1) {
            menu_ajout_contact(entry_list);
        } else {
            return;
        }
    }
    input = find_contact(nom, entry_list);

    printf("Objet du rendez-vous : ");
    char* objet = scan_str();

    printf("Heure du rendez-vous : ");
    int heure;
    scanf("%d", &heure);

    if (heure < 0 || heure > 23)
    {
        printf("L'heures doit etre comprise entre 0 et 23.\n");
        scanf("%d", &heure);
    }

    printf("Minutes du rendez-vous : ");
    int minute;
    scanf("%d", &minute);
    if (minute < 0 || minute > 59)
    {
        printf("Les minutes doivent etre comprise entre 0 et 59.\n");
        scanf("%d",&minute);
    }

    printf("Jour du rendez-vous : ");
    int jour;
    scanf("%d", &jour);
    if (jour < 1 || jour > 31) {
        printf("Le jours doit etre compris entre 1 et 31.\n");
        scanf("%d", &jour);
    }

    printf("Mois du rendez-vous : ");
    int mois;
    scanf("%d", &mois);
    if (mois < 1 || mois > 12) {
        printf("Le mois doit etre compris entre 1 et 12.\n");
        return;
    }

    printf("Annee du rendez-vous : ");
    int annee;
    scanf("%d", &annee);
    if (annee < 0) {
        printf("L'annees doit être superieure à 0.\n");
        return;
    }

    t_appointment* rdv = create_rdv(objet, heure, minute, jour, mois, annee);
    insert_rdv(rdv, input);

}

void menu_display_rdv(t_entry_list* entry_list) {

    printf("Entrer le nom de famille du contact : ");
    char* nom = scan_str();
    t_entry* input = find_contact(nom, entry_list);

    if (input == NULL) {
        printf("Le contact n'existe pas.\n");
        return;
    }

    t_appointment* temp = input->rdv;
    while(temp != NULL) {
        printf("Objet : %s\n", temp->objet);
        printf("Heure : %d:%d\n", temp->heures, temp->minutes);
        printf("Date : %d/%d/%d\n", temp->jours, temp->mois, temp->annees);
        temp = temp->next;
    }
    return;
}

int get_nb_contact(t_entry_list* entry_list) {

    int nb_contact = 0;
    for (int i = 0; i < entry_list->max_niv; i++) {
        t_entry* temp = entry_list->heads[i];
        while (temp != NULL) {
            nb_contact++;
            temp = temp->next;
        }
    }
    return nb_contact;
}
