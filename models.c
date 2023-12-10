//
// Created by Seb on 08/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "models.h"

// Fonction pour saisir une chaîne de caractères depuis la console
char* scan_string() {
    int max_size = 100;
    char* string = (char*) malloc(sizeof(char) * max_size);
    scanf("%s", string);
    return string;
}

// Fonction pour obtenir le nom formaté d'un contact (nom_de_famille_prenom)
char* formatted_name(t_contact* contact) {
    // Allouer de la mémoire pour la nouvelle chaîne
    char* name = (char*) malloc(sizeof(char) * (strlen(contact->nom_de_famille) + strlen(contact->prenom) + 2)); // +2 pour le tiret bas et le caractère nul

    // Copier le nom de famille dans la nouvelle chaîne et le convertir en minuscules
    for(int i = 0; i < strlen(contact->nom_de_famille); i++) {
        name[i] = tolower(contact->nom_de_famille[i]);
    }
    name[strlen(contact->nom_de_famille)] = '\0'; // Assurer la null-termination

    // Ajouter le tiret bas
    strncat(name, "_", 1);

    // Ajouter le prénom et le convertir en minuscules
    for(int i = 0; i < strlen(contact->prenom); i++) {
        name[strlen(contact->nom_de_famille) + 1 + i] = tolower(contact->prenom[i]);
    }

    // Assurer la null-termination de la chaîne
    name[strlen(contact->nom_de_famille) + strlen(contact->prenom) + 1] = '\0';

    return name;
}

// Fonction pour vérifier si str1 vient avant str2 dans l'ordre alphabétique
int order_name(char* str1, char* str2) {
    int i = 0;
    int j = 0;

    while(str1[i] != '\0' && str2[j] != '\0') {
        if(str1[i] < str2[j]) {
            return 1;
        } else if(str1[i] > str2[j]) {
            return 0;
        }
        i++;
        j++;
    }

    // Si str1 est plus court que str2, str1 vient avant
    if(str1[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour trouver un contact dans la liste
t_input *find_contact(char *nom_de_famille, t_input_list *liste) {
    // Parcourir les niveaux dans la liste
    for (int i = 0; i < liste->niveau_max; i++) {
        // Pointeur temporaire pour parcourir la liste à un niveau donné
        t_input *tmp = liste->tetes[i];

        // Parcourir la liste à ce niveau
        while (tmp != NULL) {
            // Vérifier si le nom de famille correspond
            if (strcmp(tmp->contact->nom_de_famille, nom_de_famille) == 0) {
                // Retourner le pointeur du contact trouvé
                return tmp;
            }

            // Passer au contact suivant dans la liste
            tmp = tmp->suivant;
        }
    }

    // Aucun contact trouvé, retourner NULL
    return NULL;
}

// Fonction pour créer un contact
t_contact *create_contact(char *prenom, char *nom_de_famille) {
    // Allouer dynamiquement de la mémoire pour le nouveau contact
    t_contact *contact = (t_contact *)malloc(sizeof(t_contact));

    // Assigner le nom de famille et le prénom au contact
    contact->nom_de_famille = nom_de_famille;
    contact->prenom = prenom;

    // Retourner le pointeur vers le nouveau contact
    return contact;
}

// Fonction pour créer un rendez-vous
t_appointment *create_appointment(char *objet, int heure, int minute, int jour, int mois, int annee) {
    // Allouer dynamiquement de la mémoire pour le nouveau rendez-vous
    t_appointment *appointment = (t_appointment *)malloc(sizeof(t_appointment));

    // Assigner les valeurs spécifiées au rendez-vous
    appointment->objet = objet;
    appointment->heure = heure;
    appointment->minute = minute;
    appointment->jour = jour;
    appointment->mois = mois;
    appointment->annee = annee;

    // Initialiser le pointeur suivant à NULL, car c'est le dernier rendez-vous dans la liste
    appointment->suivant = NULL;

    // Retourner le pointeur vers le nouveau rendez-vous
    return appointment;
}

// Fonction pour créer un rendez-vous
t_appointment *create_appointment(char *objet, int heure, int minute, int jour, int mois, int annee) {
    // Allouer dynamiquement de la mémoire pour le nouveau rendez-vous
    t_appointment *appointment = (t_appointment *)malloc(sizeof(t_appointment));

    // Assigner les valeurs spécifiées au rendez-vous
    appointment->objet = objet;
    appointment->heure = heure;
    appointment->minute = minute;
    appointment->jour = jour;
    appointment->mois = mois;
    appointment->annee = annee;

    // Initialiser le pointeur suivant à NULL, car c'est le dernier rendez-vous dans la liste
    appointment->suivant = NULL;

    // Retourner le pointeur vers le nouveau rendez-vous
    return appointment;
}

// Fonction pour créer une liste d'entrées
t_input_list *create_input_list(int niveau) {
    // Allouer dynamiquement de la mémoire pour la nouvelle liste d'entrées
    t_input_list *liste = (t_input_list *)malloc(sizeof(t_input_list));

    // Allouer dynamiquement de la mémoire pour le tableau de pointeurs de niveau
    liste->tetes = (t_input **)malloc(sizeof(t_input *) * niveau);

    // Initialiser le niveau maximal de la liste
    liste->niveau_max = niveau;

    // Initialiser chaque tête de niveau à NULL
    for (int i = 0; i < niveau; i++) {
        liste->tetes[i] = NULL;
    }

    // Retourner le pointeur vers la nouvelle liste d'entrées
    return liste;
}

// Fonction pour insérer un rendez-vous dans une entrée
void insert_appointment(t_appointment *rendez_vous, t_input *input) {
    // Ajouter le rendez-vous à la tête de la liste des rendez-vous de l'entrée
    rendez_vous->suivant = input->rendez_vous;
    input->rendez_vous = rendez_vous;
}

// Fonction pour insérer un contact dans la liste
void insert_input(t_contact *contact, t_input_list *liste) {
    // Obtenir le nom formaté du contact à insérer
    char *nom = formatted_name(contact);

    // Vérifier si le contact est déjà dans la liste
    for (int i = 0; i < liste->niveau_max; i++) {
        // Pointeur temporaire pour parcourir la liste à un niveau donné
        t_input *tmp = liste->tetes[i];

        // Parcourir la liste à ce niveau
        while (tmp != NULL) {
            // Comparer le nom formaté du contact actuel avec le nom du contact à insérer
            if (strcmp(formatted_name(tmp->contact), nom) == 0) {
                // Afficher un message et sortir de la fonction si le contact est déjà présent
                printf("Contact déjà présent dans la liste.\n");
                return;
            }

            // Passer au contact suivant dans la liste
            tmp = tmp->suivant;
        }
    }
    // Le contact n'est pas dans la liste, continuer avec l'insertion

    // Insérer le contact dans la liste par ordre alphabétique uniquement sur le niveau 0
    t_input *entree = create_input(contact, 0);

    // Si il n'y a pas de contacts dans la liste
    if (liste->tetes[0] == NULL) {
        liste->tetes[0] = entree;
        return;
    }

    // Comparer les noms pour déterminer la position d'insertion
    if (order_name(nom, formatted_name(liste->tetes[0]->contact))) {
        entree->suivant = liste->tetes[0];
        liste->tetes[0] = entree;
        return;
    }

    t_input *tmp = liste->tetes[0];

    // Parcourir la liste pour trouver la position d'insertion
    while (tmp->suivant != NULL && order_name(formatted_name(tmp->suivant->contact), nom)) {
        tmp = tmp->suivant;
    }

    // Insérer le contact à la position trouvée
    entree->suivant = tmp->suivant;
    tmp->suivant = entree;
}

// Fonction pour afficher la liste d'entrées
void display_input_list(t_input_list *liste) {
    // Parcourir chaque niveau de la liste
    for (int i = 0; i < liste->niveau_max; i++) {
        // Afficher l'en-tête du niveau actuel
        printf("[tête de liste_%d @-]-->", i);

        // Pointeur temporaire pour parcourir la liste à un niveau donné
        t_input *tmp = liste->tetes[i];

        // Parcourir la liste à ce niveau
        while (tmp != NULL) {
            // Afficher le nom de famille du contact actuel
            printf("[ %s|@ ]-->", tmp->contact->nom_de_famille);

            // Passer au contact suivant dans la liste
            tmp = tmp->suivant;
        }

        // Afficher NULL pour indiquer la fin de la liste à ce niveau
        printf("NULL\n");
    }
}

