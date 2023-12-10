//
// Created by Seb on 08/12/2023.
//

#ifndef GESTION_AGENDA_MODELS_H
#define GESTION_AGENDA_MODELS_H

// Structure représentant un contact
typedef struct s_contact
{
    char* prenom;
    char* nom;

} t_contact;

// Structure représentant un rendez-vous
typedef struct s_appointment
{
    char* objet;
    int heures;
    int minutes;
    int jours;
    int mois;
    int annees;
    struct s_appointment *next;

} t_appointment;

// Déclaration préalable de la structure t_rdv
typedef struct t_rdv t_rdv;

// Structure représentant une entrée (contact) dans la liste
typedef struct s_entry {
    t_contact* contact;
    t_appointment* rdv;
    struct s_entry *next;
    int niveau;
    t_rdv *list_rdv;
} t_entry;

// Structure représentant la liste d'entrées (contacts)
typedef struct s_entry_list {
    int max_niv;
    t_entry **heads;

} t_entry_list;

// Fonction pour saisir une chaîne de caractères
char* scan_str();

// Fonction pour obtenir le nom formaté d'un contact en majuscules et minuscules
char* convert_maj_min(t_contact *contact);

// Fonction pour créer un contact
t_contact* create_contact(char* prenom, char* nom);

// Fonction pour créer une entrée avec un contact
t_entry* create_input(t_contact* contact, int niv);

// Fonction pour créer une liste d'entrées
t_entry_list* create_listInput(int niv);

// Fonction pour insérer un contact dans la liste
void insert_entry(t_contact * contact, t_entry_list* liste);

// Fonction pour afficher la liste d'entrées
void display_input_list(t_entry_list* liste);

// Fonction pour créer un rendez-vous
t_appointment* create_rdv(char* objet, int heure, int minute, int jour, int mois, int annee);

// Fonction pour insérer un rendez-vous dans une entrée
void insert_rdv(t_appointment *rdv, t_entry *input);

// Fonction pour vérifier l'ordre alphabétique des noms
int si_nom_avant(char* str_1, char* str_2);

// Fonction pour trouver un contact dans la liste
t_entry* find_contact(char* nom, t_entry_list* liste);



#endif //GESTION_AGENDA_MODELS_H
