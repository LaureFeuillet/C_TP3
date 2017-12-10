#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(void)
{
	int tailleGraphe;
	
	// Création du graphe
	printf("Veuillez rentrer la taille de votre graphe :");
	scanf("%d",&tailleGraphe);
	struct graphe * pgraphe = creer_graphe(tailleGraphe);
	
	Menu();
	return 0;
}