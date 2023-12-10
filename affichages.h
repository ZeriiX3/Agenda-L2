/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


#ifndef GESTION_AGENDA_AFFICHAGES_H
#define GESTION_AGENDA_AFFICHAGES_H

#include "models.h"
#include "fichier.h"


// Ici nous avons juste les fonctions qui permettent d'afficher les printf pour les inputs users dans le main

// Fonction pour afficher le menu de la première partie
void menu_part1();

// Fonction pour afficher le menu de la deuxième partie
void menu_part2();

// Fonction pour afficher le menu de la troisième partie
void menu_part3(t_entry_list* contact_list);

// Fonction pour afficher le menu d'ajout de contact
void menu_ajout_contact(t_entry_list* entry_list);

// Fonction pour afficher le menu de recherche de contact
void menu_find_contact(t_entry_list* entry_list);

// Fonction pour afficher le menu d'affichage des rendez-vous
void menu_display_rdv(t_entry_list* entry_list);

// Fonction pour obtenir le nombre de contacts dans la liste
int get_nb_contact(t_entry_list* entry_list);

// Fonction pour afficher le menu d'ajout de rendez-vous
void menu_add_rdv(t_entry_list* entry_list);

// Fonction pour afficher le menu d'affichage d'un contact
void menu_display_contact(t_contact* contact);

// Fonction pour afficher le menu d'affichage de tous les contacts dans la liste
void menu_display_all_contact(t_entry_list* entry_list);


#endif //GESTION_AGENDA_AFFICHAGES_H
