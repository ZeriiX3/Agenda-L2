//
// Created by Seb on 08/12/2023.
//

#ifndef GESTION_AGENDA_MODELS_H
#define GESTION_AGENDA_MODELS_H

// Structure représentant un contact
typedef struct s_contact
{
    char* prenom;
    char* nom_de_famille;

} t_contact;

// Structure représentant un rendez-vous
typedef struct s_appointment
{
    char* objet;
    int heure;
    int minute;
    int jour;
    int mois;
    int annee;
    struct s_appointment *suivant;

} t_appointment;

// Déclaration préalable de la structure t_rendez_vous
typedef struct t_rendez_vous t_rendez_vous;

// Structure représentant une entrée (contact) dans la liste
typedef struct s_input
{
    t_contact* contact;
    t_appointment* rendez_vous;

    struct s_input *suivant;
    int niveau;

    t_rendez_vous *liste_rendez_vous;
} t_input;

// Structure représentant la liste d'entrées (contacts)
typedef struct s_input_list
{
    int niveau_max;
    t_input **tetes;

} t_input_list;

// Déclaration de fonction pour créer un rendez-vous
t_appointment* create_appointment(char*, int, int, int, int, int);
// Déclaration de fonction pour insérer un rendez-vous dans une entrée
void insert_appointment(t_appointment*, t_input *);
// Déclaration de fonction pour vérifier l'ordre alphabétique des noms
int order_name(char*, char*);
// Déclaration de fonction pour trouver un contact dans la liste
t_input * find_contact(char*, t_input_list*);

// Déclaration de fonction pour créer un contact
t_contact* create_contact(char*, char*);
// Déclaration de fonction pour créer une entrée avec un contact
t_input* create_input(t_contact*, int);
// Déclaration de fonction pour créer une liste d'entrées
t_input_list* create_input_list(int);
// Déclaration de fonction pour insérer un contact dans la liste
void insert_input(t_contact *, t_input_list*);
// Déclaration de fonction pour afficher la liste d'entrées
void display_input_list(t_input_list*);

// Déclaration de fonction pour saisir une chaîne de caractères
char* scan_string();
// Déclaration de fonction pour obtenir le nom formaté d'un contact
char* formatted_name(t_contact*);

#endif //GESTION_AGENDA_MODELS_H
