#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct graphe * creer_graphe (int);
void ajouter_arc (struct graphe *, int, int, char);
int arc_existe (struct graphe *, int, int, char);
void retirer_arc (struct graphe *, int, int, char);
void afficher(struct graphe *);
int transiter(struct graphe *, int, int);
void liberer_graphe(struct graphe *);

// void Menu(struct graphe *);
// int Verification (struct graphe *, int, int);

struct larc
{
	int voisin; // Num�ro du sommet vers lequel l'arc m�ne
	char etiquette; // Lettre associ�e � l'arc
	struct larc * arc_suiv; // Pointeur sur un autre arc issu du m�me sommet
};

struct graphe
{
	int nbsommets; // Nombre de sommets du graphe
	struct larc ** adjs; // Tableau contenant, pour chaque sommet, les fonctions de transition en �tant issues (tableau de larc)
};

#endif
