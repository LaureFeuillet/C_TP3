#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

// Initialise une structure graphe contenant un nombre de sommets passé en paramètre et aucun arc
// Renvoie l'adresse mémoire ddu graphe allouée
struct graphe * creer_graphe (int nbsommets)
{
	struct graphe * pgraphe;
	pgraphe = malloc(sizeof(struct graphe)); 
	pgraphe->nbsommets = nbsommets;
	pgraphe->adjs = calloc(sizeof(struct larc *),nbsommets); // Alloue la mémoire pour le tableau de listes d'adjacence

	int i = 0;
	for(i=0; i<nbsommets;i++)
		pgraphe->adjs[i]=NULL;

	return pgraphe; // Adresse mémoire du graphe créé
}

// Ajoute un arc entre deux sommets passés en paramètre
// Assigne un symbole aussi passé en paramètre
void ajouter_arc (struct graphe * pgraphe, int s1, int s2, char symbole)
{	
	printf("Tentative de l'ajout de l'arc :  \nReliant la branche %d, %d avec pour symbole %c \n",i, s1,s2,symbole);

	struct larc * parc;
	parc = malloc(sizeof(struct larc));
	parc->voisin = s2;
	parc->etiquette = symbole;

	if (arc_existe(pgraphe, s1, s2, symbole)) // On verifie si l'arc existe
	{
		printf("L'arc existe déjà");
	}
	else
	{
		if (pgraphe->adjs[s1] == NULL) // Si c'est le premier arc que l'on ajoute à partir de s1
	 	{
	 		pgraphe->adjs[s1] = parc;
	 		parc->arc_suiv = NULL; 
	 	}
	 	else
	 	{
	 		struct larc * pbuffer;
	 		pbuffer = pgraphe->adjs[s1]; //On garde en mémoire l'ancien arc pointer par le s1
	 		pgraphe->adjs[s1] = parc; //On fait pointer le s1 sur le nouvelle arc
	 		parc->arc_suiv = pbuffer; // On fait pointer cette arc sur l'ancien arc
	 		
	 	}
		printf("Arc reliant la branche %d, %d avec pour symbole %c crée \n",i, s1,s2,symbole);
	}
}


// Paramètres : 2 sommets et une étiquette associée
// Renvoie 1 si cet arc existe déjà
// Renvoie 0 si l'arc n'existe pas
int arc_existe (struct graphe * pgraphe, int s1, int s2, char symbole)
{
	int existence = 0;

	struct larc * piteration = pgraphe->adjs[s1]; // On recupère le pointeur du sommet s1 sur la liste chainée 
	while ((piteration != NULL) || ((piteration->voisin != s2) && (piteration->etiquette != symbole)) ) // Tant que 
	{
		piteration = piteration->arc_suiv;
	}	
	if ((piteration->voisin == s2) && (piteration->etiquette == symbole))
	{
		existence = 1;
		printf("L'arc reliant la branche %d, %d avec pour symbole %c existe\n",i, s1,s2,symbole);
	}
	return existence; // 0 ou 1 en fonction de l'existence de l'arc
}

// Paramètres : 2 sommets et une étiquette associée
// Supprime l'arc associé à ces paramètres si celui-ci existe
void retirer_arc (struct graphe * pgraphe, int s1, int s2, char symbole)
{
	if (arc_existe(pgraphe, s1, s2, symbole))
	{
		printf("Tentative de déstruction de l'arc reliant la branche %d, %d avec pour symbole %c n'existe pas \n",i, s1,s2,symbole);
		
		struct larc * pprecedent = NULL;  // Pointeur sur arc-1
		struct larc * pactuel = pgraphe->adjs[s1];;  // Pointeur sur arc
		while ((pactuel != NULL) || ((pactuel->voisin != s2) && (pactuel->etiquette != symbole)) ) // Tant que ça match pas
		{
			pprecedent = pactuel;
			pactuel = pactuel->arc_suiv; // On avance
		}	
		if ((pactuel->voisin == s2) && (pactuel->etiquette == symbole)) // Si ça match
		{
			printf("L'arc reliant la branche %d, %d avec pour symbole %c à détruire a été trouvé \n",i, s1,s2,symbole);
			pprecedent->arc_suiv = pactuel; // On change la valeur du pointeur de l'arc précedent avec la valeur de celui du pointeur de celui qui a match
			free(pactuel);//puis on le détruit
			printf("L'arc reliant la branche %d, %d avec pour symbole %c a été détruit \n",i, s1,s2,symbole);
		}
	}
	else
		printf("L'arc reliant la branche %d, %d avec pour symbole %c n'existe pas \n",i, s1,s2,symbole);
}


// Paramètres : état de départ et étiquette
// Renvoie l'état d'arrivée 
// Renvoie -1 si la transition n'existe pas
int transiter (struct graphe * pgraphe, int etat, int etiquette)
{
	int etat_atteint = -1;
	struct larc * piteration = pgraphe->adjs[s1];
	while ((piteration != NULL) || (piteration->etiquette != symbole)) // Tant que l'étiquette n'est pas la bonne
	{
		piteration = piteration->arc_suiv;
	}
	if(piteration->etiquette != symbole)
	{
		etat_atteint=piteration->voisin;
	}
	return etat_atteint; // Etat d'arrivée ou -1 si celui-ci n'existe pas
}


// Affiche le graphe en listant pour chaque sommet les sommets accessibles et les étiquettes associéees
void afficher(struct graphe * pgraphe)
{
	int i = 0;
	for (i=0; i < pgraphe->nbsommets; i++)
	{
		printf("Sommet %d : ", i);

		struct larc * piteration = pgraphe->adjs[i];
		while (piteration != NULL)
		{
			printf("(%d,%c) ", piteration->voisin, piteration->etiquette);
			piteration = piteration->arc_suiv;
		}	
		printf("\n");
	}
}


// Libère l'espace mémoire occupé par le graphe
void liberer_graphe(struct graphe * pgraphe)
{
	
	int i;
	struct larc * piteration = NULL;
	struct larc * pprecedent = NULL;  // Pointeur sur arc-1

	//Libere la mémoire des arcs 
	for (i = 0; i < pgraphe->nbsommets; ++i) // Pour le nombre de sommet
	{
		printf("Destruction des arcs du sommet %d\n", i);
		struct larc * piteration = pgraphe->adjs[i];
		do // Tant que l'étiquette n'est pas la bonne
		{
			pprecedent = piteration; // On garde en mémoire le pointeur actuel
			piteration = piteration->arc_suiv; // On passe au pointeur suivant
			free(pprecedent); // On free l'ancien arc
		} while (piteration != NULL); // Tant que le pointeur rencontrer n'est pas NULL
	}
	free(pgraphe);
	printf("Destruction du graphe\n");
}

void Menu(struct graphe * pgraphe)
{
	int choixMenu=-1,sommet1,sommet2;
	char symbole;
	while(choixMenu != 5)
	{
		while(choixMenu>4 && choixMenu<1)
		{
			printf("1.Créer un arc\n3.Retirer un arc\n2.Affiche le graphe\n4.Liberer la memoire et recréer un graphe\n5.Stop");
			scanf("%d",choixMenu)
		}
		
		switch(choixMenu)
		{
			case 1 : 	
				while(Verification(pgraphe,sommet1,sommet2))
				{
					printf("Sommet de départ :\n");
					scanf("%d",sommet1);
					printf("Sommet d'arrivée :\n");
					scanf("%d",sommet2);
					printf("Symbole :\n");
					scanf("%c",symbole);
				}
				ajouter_arc(pgraphe, sommet1, sommet2, symbole);
				break;
	
			case 2 : while(Verification(pgraphe,sommet1,sommet2))
				{
					printf("Sommet de départ :\n");
					scanf("%d",sommet1);
					printf("Sommet d'arrivée :\n");
					scanf("%d",sommet2);
					printf("Symbole :\n");
					scanf("%c",symbole);
				}
				retirer_arc(pgraphe, sommet1, sommet2, symbole);
				break;
			
			case 3 : afficher(pgraphe);
			break;
			
			case 4 : 
				liberer_graphe(pgraphe);
				printf("\nVeuillez rentrer la taille de votre graphe :");
				scanf("%d",&tailleGraphe);
				struct graphe * pgraphe = creer_graphe(tailleGraphe);
			break;
			
			case 5 : liberer_graphe(pgraphe);
			break;
		}
	}
}

int Verification (struct graphe * pgraphe, int s1, int s2)
{
	int ok =0;
	if( (s1 > (pgraphe->nbsommets) ) || (s2 > (pgraphe->nbsommets)) )
	{
		printf("Erreur : la valeur du sommet est trop grande\n");
		ok = 1;
	}
	return ok;
}