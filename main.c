#include "graphe.h"
#include "automate.h"
#include "langage.h"
#include "fichier.h"

int main(void)
{
    // Prend un nom de fichier en paramètres
    int taille = 15;
    char * nomfichier = calloc(taille,sizeof(char));
    FILE * pfichier = NULL;
    printf("Nom du fichier : ");
    lecture(nomfichier, taille);

    pfichier = fopen(nomfichier, "r+"); // Ouverture du fichier en mode lecture

    if(pfichier != NULL)
    {
        struct automate * pautomate = lire_automate(pfichier);

<<<<<<< HEAD
        int c = 0; // Continuation ou non du menu
        int x = 0; // Choix du menu
=======
        int c = 1; // Continuation ou non du menu
        int x=0; // Choix du menu
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
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
            switch(x)
            {
                // Modifier l'automate
<<<<<<< HEAD
                case 1 : 
                    printf("\n");
                    int y = 0; // Choix de la modification de l'automate
                    while(y>2 || y<1)
=======
                case 1 :
                    y=0;
                    while((y>3 || y<1))
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
                    {
                        printf("\n1. Ajouter un arc\n2. Retirer un arc\n3. Affiche graphe\n4. Retour\nChoix :");
                        scanf("%d",&y);
                    }
                    switch(y)
<<<<<<< HEAD
                    {  
                        int s1;
                        int s2;
                        char symbole;
                        // Ajouter arc
                        case 1 :
                            printf("\n");
                            printf("Sommet de depart : ");
=======
                    {
                        // Ajouter arc
                        case 1 :
                            printf("Sommet de départ : ");
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
                            scanf("%d", &s1);
                            printf("Sommet d'arrivee : ");
                            scanf("%d", &s2);
                            printf("Etiquette : ");
                            while (getchar() != '\n');
                            scanf("%c", &symbole);

                            ajouter_arc(pautomate->graphe_trans, s1, s2, symbole);
                            break;

                        // Retirer arc
                        case 2 :
<<<<<<< HEAD
                            printf("\n");
                            printf("Sommet de depart : ");
=======
                            printf("Sommet de départ : ");
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
                            scanf("%d", &s1);
                            printf("Sommet d'arrivee : ");
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
<<<<<<< HEAD
                case 2 : 
                    printf("\n");
                    char mot[100];
=======
                case 2 :

>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
                    printf("Mot : ");
                    while (getchar() != '\n');
                    scanf("%s", mot);

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
<<<<<<< HEAD
                case 3 : 
                    printf("\n");
                    c = -1;
=======
                case 3 :
                    liberer_graphe(pautomate->graphe_trans);
                    c = 0;
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
                    break;
            }
        }

        fclose(pfichier);
<<<<<<< HEAD
        sauvegarde_automate(pautomate, nomfichier);
=======
>>>>>>> 5bd739eb3780a72c29072ca312e220c52e474cf5
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }

    

    return 0;
}


// void Menu(struct graphe * pgraphe)
// {
//     int choixMenu=-1,sommet1,sommet2,tailleGraphe,i=0,etat_depart;
//     char symbole, alphabet[9]={'a','b','c','d','e','f','g','h'};
//     while(choixMenu != 6)
//     {
//         choixMenu=-1;
//         while(choixMenu>6 || choixMenu<1)
//         {
//             printf("\n\n1.Creer un arc\n2.Retirer un arc\n3.Affiche le graphe\n4.Transition\n5.Liberer la memoire et recreer un graphe\n6.Stop\nChoix : ");
//             scanf("%d",&choixMenu);
//         }

//         switch(choixMenu)
//         {
//             case 1 :

//                 do{
//                     printf("Sommet de depart :");
//                     scanf("%d",&sommet1);
//                     printf("Sommet d'arrivee :");
//                     scanf("%d",&sommet2);
//                     if(i<9){
//                         symbole=alphabet[i];
//                         i++;
//                     }
//                     else
//                         i=0;
//                 }while(Verification(pgraphe,sommet1,sommet2));
//                 ajouter_arc(pgraphe, sommet1, sommet2, symbole);
//                 break;

//             case 2 :
//                 do{
//                     printf("Sommet de depart :");
//                     scanf("%d",&sommet1);
//                     printf("Sommet d'arrivee :");
//                     scanf("%d",&sommet2);
//                 }while(Verification(pgraphe,sommet1,sommet2));
//                 retirer_arc(pgraphe, sommet1, sommet2);
//                 break;

//             case 3 : afficher(pgraphe);
//             break;

//             case 4:
//                 symbole = 'a'; // Il faut recuperer le symbole
//                 printf("Etat de depart : ");
//                 scanf("%d",&etat_depart);
//                 if(transiter(pgraphe,etat_depart,symbole) != -1)
//                     printf("En partant de l'etat %d, on arrive a l'etat %d en passant par la branche de symbole : %c",etat_depart,transiter(pgraphe,etat_depart,symbole),symbole);
//                 else
//                     printf("Transition impossible auncun arc du sommet %d n'a le symbole %c",etat_depart,symbole);
//                 break;
//             case 5 :
//                 liberer_graphe(pgraphe);
//                 printf("\nVeuillez rentrer la taille de votre graphe :");
//                 scanf("%d",&tailleGraphe);
//                 struct graphe * pgraphe = creer_graphe(tailleGraphe);
//             break;

//             case 6 : liberer_graphe(pgraphe);
//             break;
//         }
//     }
// }







    // int taille = 15;
    // char * nomfichier = calloc(taille,sizeof(char));
    // FILE * fichier = NULL;
    // printf("Fichier a lire : ");
    // lecture(nomfichier,taille);
    // printf("Lecture du fichier %s",nomfichier);
    // fichier = fopen(nomfichier, "r+"); // ouverture du fichier en mode lecture


    // if(fichier !=NULL)
    // {
    //     struct automate * pautomate = lire_automate(fichier);
    //     // Renvoie 1 si le mot est reconnu par l'automate
    //     // Renvoie 0 si le mot n'est pas reconnu par l'automate
    //     char * alpha = calloc(taille,sizeof(char));
    //     printf("Votre mot :");
    //     lecture(alpha,taille);
    //     if(accepte(pautomate,alpha))
    //         printf("Mot accepte");

    //     int rep;
    //     printf("\nVoulez-vous modifiez l'automate (1 = yes) :");
    //     scanf("%d",&rep);
    //     if(rep==1)
    //        pautomate=ecrire_automate(fichier,pautomate);
    //     if(rep==2)
    //     {
    //         char * nomfichier2 = calloc(taille,sizeof(char));
    //         printf("Sauvegarde de l'automate\nNom de fichier :");
    //         lecture(nomfichier2,taille); // Permet de lire la chaine de caractère rentrée par l'utilisateur et d'enlevere le \n à la fin
    //         sauvegarde_automate(pautomate,nomfichier2);
    //     }

    //     fclose(fichier);
    // }
    // else
    // {
    //     printf("Impossible d'ouvrir le fichier");
    // }

