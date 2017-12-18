#include "graphe.h"
#include "automate.h"
#include "langage.h"
#include "fichier.h"

int main(void)
{
    // Prend un nom de fichier en param�tres
    int taille = 15;
    char * nomfichier = calloc(taille,sizeof(char));
    FILE * pfichier = NULL;
    printf("Nom du fichier : ");
    lecture(nomfichier,taille);

    pfichier = fopen(nomfichier, "r+"); // Ouverture du fichier en mode lecture

    if(pfichier !=NULL)
    {
        struct automate * pautomate = lire_automate(pfichier);

        int c = 1; // Continuation ou non du menu
        int x=0; // Choix du menu
        while (c != 0)
        {
            while(x>3 || x<1)
            {
                printf("\n1. Modifier l'automate\n2. Reconnaitre un mot\n3. Quitter\nChoix :");
                scanf("%d",&x);
            }
            int s1;
            int s2;
            char symbole;
            char mot[100];
            int y; // Choix de la modification de l'automate
            while(x!=-1)
            {
                switch(x)
                {
                    // Modifier l'automate
                    case 1 :
                        y=0;
                        while((y>5 || y<1))
                        {
                            printf("\n1. Ajouter un arc\n2. Retirer un arc\n3. Affiche graphe\n4. Retour\nChoix :");
                            scanf("%d",&y);
                        }
                        switch(y)
                        {
                            // Ajouter arc
                            case 1 :
                                printf("Sommet de d�part : ");
                                scanf("%d", &s1);
                                printf("Sommet d'arriv�e : ");
                                scanf("%d", &s2);
                                printf("Etiquette : ");
                                while (getchar() != '\n');
                                scanf("%c", &symbole);

                                ajouter_arc(pautomate->graphe_trans, s1, s2, symbole);
                                break;

                            // Retirer arc
                            case 2 :
                                printf("Sommet de d�part : ");
                                scanf("%d", &s1);
                                printf("Sommet d'arriv�e : ");
                                scanf("%d", &s2);
                                printf("Etiquette : ");
                                while (getchar() != '\n');
                                scanf("%c", &symbole);

                                retirer_arc(pautomate->graphe_trans, s1, s2, symbole);
                                break;
                            case 3:
                                afficher(pautomate->graphe_trans);
                                break;
                            case 4:
                                x=-1;
                                break;
                        }
                        break;

                    // Reconnaitre un mot
                    case 2 :
                        printf("\n");
                        char mot[100];
                        printf("OK 1\n");
                        printf("Mot : ");
                        while (getchar() != '\n');
                        scanf("%s", mot);
                        printf("OK 2\n");

                        // Renvoie 1 si le mot est reconnu par l'automate
                        // Renvoie 0 si le mot n'est pas reconnu par l'automate
                        int a = accepte(pautomate->graphe_trans, mot);
                        if (a == 0)
                        {
                            printf("Le mot %s n'est pas reconnu par l'automate.\n", mot);
                        }
                        if (a==1)
                        {
                            printf("Le mot %s est reconu par l'automate.\n", mot);
                        }
                        break;

                    // Quitter
                    case 3 :
                        liberer_graphe(pautomate->graphe_trans);
                        c = 0;
                        break;
                }
            }
        }

        fclose(pfichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }

    return 0;
}
