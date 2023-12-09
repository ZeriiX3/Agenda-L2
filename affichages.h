/* Project C: Gestion d'un agenda
Professeurs: Mourad KMIMECH, Nicolas FLASQUE, Rado RAKOTONARIVO
Octobre - Décembre / 2023

Par Sébastien XU, Matthieu BACHELERIE et Angel BOURDIOL */


#ifndef GESTION_AGENDA_AFFICHAGES_H
#define GESTION_AGENDA_AFFICHAGES_H

#include "models.h"
#include "fichier.h"


void menu_part1();

void menu_part2();

void menu_part3(t_input_list * contact_list);

void menu_add_contact(t_input_list* input_list);

void menu_find_contact(t_input_list* input_list);

void menu_add_appointment(t_input_list* input_list);

void menu_display_contact(t_contact* contact);

void menu_display_appointment(t_input_list* input_list);

void menu_display_all_contacts(t_input_list* input_list);

int get_number_of_contacts(t_input_list* input_list);

#endif //GESTION_AGENDA_AFFICHAGES_H
