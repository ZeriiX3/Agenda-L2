#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "models.h"

// Fonction pour saisir une chaîne de caractères depuis la console
char* scan_str() {
    int taille_max = 100;
    char* str = (char*) malloc(sizeof(char) * taille_max);
    scanf("%s", str);
    return str;
}

// Fonction pour obtenir le nom formaté d'un contact (nom_de_famille_prenom)
char* convert_maj_min(t_contact* contact) {
    // Allouer de la mémoire pour la nouvelle chaîne
    char* nom = (char*) malloc(sizeof(char) * (strlen(contact->nom) + strlen(contact->prenom) + 2)); // +2 pour le tiret bas et le caractère nul

    // Copier le nom de famille dans la nouvelle chaîne et le convertir en minuscules
    for (int i = 0; i < strlen(contact->nom); i++) {
        nom[i] = tolower(contact->nom[i]);
    }
    nom[strlen(contact->nom)] = '\0'; // Assurer la null-termination

    // Ajouter le tiret bas
    strncat(nom, "_", 1);

    // Ajouter le prénom et le convertir en minuscules
    for(int i = 0; i < strlen(contact->prenom); i++) {
        nom[strlen(contact->nom) + 1 + i] = tolower(contact->prenom[i]);
    }

    // Assurer la null-termination de la chaîne
    nom[strlen(contact->nom) + strlen(contact->prenom) + 1] = '\0';

    return nom;
}

// Fonction pour vérifier si str_1 vient avant str_2 dans l'ordre alphabétique
int si_nom_avant(char* str_1, char* str_2) {
    int i = 0;
    int j = 0;

    while(str_1[i] != '\0' && str_2[j] != '\0') {
        if(str_1[i] < str_2[j]) {
            return 1;
        } else if(str_1[i] > str_2[j]) {
            return 0;
        }
        i++;
        j++;
    }
    // Si str_1 est plus court que str_2, str_1 passe devant
    if(str_1[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour trouver un contact dans la liste
t_entry * find_contact(char* nom, t_entry_list* liste) {
    for (int i = 0; i < liste->max_niv; i++) {
        t_entry* temp = liste->heads[i];
        while(temp != NULL) {
            if(strcmp(temp->contact->nom, nom) == 0) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

// Fonction pour créer un contact
t_contact* create_contact(char* prenom, char* nom) {
    t_contact* contact = (t_contact*) malloc(sizeof(t_contact));
    contact->nom = nom;
    contact->prenom = prenom;
    return contact;
}

// Fonction pour créer un rendez-vous
t_appointment* create_rdv(char* objet, int heure, int minute, int jour, int mois, int annee) {
    t_appointment* rdv = (t_appointment*) malloc(sizeof(t_appointment));
    rdv->jours = jour;
    rdv->mois = mois;
    rdv->annees = annee;
    rdv->objet = objet;
    rdv->heures = heure;
    rdv->minutes = minute;
    rdv->next = NULL; // Next
    return rdv;
}

// Fonction pour créer une entrée dans la liste avec un contact
t_entry* create_input(t_contact* contact, int niv) {
    t_entry* entry = (t_entry*) malloc(sizeof(t_entry));
    entry->contact = contact;
    entry->rdv = NULL;
    entry->next = NULL;
    entry->niveau = niv;
    return entry;
}

// Fonction pour créer une liste d'entrées
t_entry_list* create_listInput(int niv) {
    t_entry_list* liste = (t_entry_list*) malloc(sizeof(t_entry_list));
    liste->heads = (t_entry **) malloc(sizeof(t_entry*) * niv);
    liste->max_niv = niv;
    for(int i = 0; i < niv; i++) {
        liste->heads[i] = NULL;
    }
    return liste;
}

// Fonction pour insérer un rendez-vous dans une entrée
void insert_rdv(t_appointment* rdv, t_entry* input) {
    rdv->next = input->rdv;
    input->rdv = rdv;
}

// Fonction pour insérer un contact dans la liste
void insert_entry(t_contact * contact, t_entry_list* liste) {
    // Vérifier si le contact est déjà dans la liste
    char* nom = convert_maj_min(contact);

    for(int i = 0; i < liste->max_niv; i++) {
        t_entry* temp = liste->heads[i];

        while(temp != NULL) {
            if(strcmp(convert_maj_min(temp->contact), nom) == 0) {
                printf("Contact déjà présent dans la liste.\n");
                return;
            }
            temp = temp->next;
        }
    }

    // Insérer le contact dans la liste par ordre alphabétique uniquement sur le niveau 0
    t_entry* entry = create_input(contact, 0);

    if(liste->heads[0] == NULL) {
        liste->heads[0] = entry;
        return;
    }

    if(si_nom_avant(nom, convert_maj_min(liste->heads[0]->contact))) {
        entry->next = liste->heads[0];
        liste->heads[0] = entry;
        return;
    }

    t_entry* temp = liste->heads[0];

    while(temp->next != NULL && si_nom_avant(convert_maj_min(temp->next->contact), nom)) {
        temp = temp->next;
    }

    entry->next = temp->next;
    temp->next = entry;
}

// Fonction pour afficher la liste d'entrées
void display_input_list(t_entry_list* liste) {
    for (int i = 0; i < liste->max_niv; i++) {
        printf("[tête de liste_%d @-]-->", i);
        t_entry *temp = liste->heads[i];

        while (temp != NULL) {
            printf("[ %s|@ ]-->", temp->contact->nom);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
