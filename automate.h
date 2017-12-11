#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "graphe.h"

struct automate * creer_automate (int *, char *, int, int *);
void liberer_automate (struct automate *);
void ajouter_transition (int, int, char);

struct automate
{
	struct graphe * graphe_trans; // Graphe de transition de l'AFD
	char * alphabet; // Alphabet de l'AFD, correspond aux étiquettes possibles
	int etat_init; // Etat initial
	int * etats_finaux; // Etats finaux
};

#endif