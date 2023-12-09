//
// Created by Seb on 08/12/2023.
//

#ifndef GESTION_AGENDA_AFFICHAGES_H
#define GESTION_AGENDA_AFFICHAGES_H

#include "models.h"
#include "fichier.h"

void menu_part3(t_input_list * contact_list);

void menu_add_contact(t_input_list* input_list);

void menu_find_contact(t_input_list* input_list);

void menu_add_appointment(t_input_list* input_list);

void menu_display_contact(t_contact* contact);

void menu_display_appointment(t_input_list* input_list);

void menu_display_all_contacts(t_input_list* input_list);

int get_number_of_contacts(t_input_list* input_list);

#endif //GESTION_AGENDA_AFFICHAGES_H
