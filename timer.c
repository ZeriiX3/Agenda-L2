//
// Created by flasque on 11/10/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "timer.h"

// Lance le chronomètre
void startTimer()
{
    _timer._start = clock();
}

// Arrêtez le chronomètre et calculez la durée en millisecondes.
void stopTimer()
{
    _timer._end = clock();
    // Calculez la durée en millisecondes par rapport à CLOCKS_PER_SEC
    _timer._msecs = (1000.0 * (double) (_timer._end - _timer._start)) / CLOCKS_PER_SEC;
}

// Afficher l'heures
void displayTime()
{
    // Afficher l'heures en utilisant getTimeAsString()
    printf("%s\n", getTimeAsString());
    return;
}

// Retournez une chaîne de caractères avec le temps en secondes et en millisecondes
char *getTimeAsString()
{
    // Retournez une chaîne de caractères avec le temps en secondes et en millisecondes
    // format : integers, with 3 digits, fill with 0
    // exemple : 001,123

    // Utilisez sprintf pour écrire la chaîne dans un tampon alloué dynamiquement
    char *buffer = (char *)malloc(10*sizeof(char));
    // Utilisez sprintf pour écrire la chaîne dans un tampon alloué dynamiquement
    sprintf(buffer, "[%g] %03d,%03d", _timer._msecs, (int)(_timer._msecs)/1000, (int)(_timer._msecs)%1000);

    // Retournez le tampon
    return buffer;
}