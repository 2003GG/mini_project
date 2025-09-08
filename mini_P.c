#include <stdio.h>
#include <string.h>
#include "libary.h"
int main()
{ 
    int x;
    int novq;

    while (1){
        printf("\n********Bonjour a la libraire******\n");
        printf("1.   Ajouter un livre au stock.\n");
        printf("2.   Afficher tous les livres disponibles.\n");
        printf("3.   Rechercher un livre par son titre.\n");
        printf("4.   Mettre à jour la quantité d'un livre.\n");
        printf("5.   Supprimer un livre du stock.\n");
        printf("6.   Afficher le nombre total de livres en stock.\n");
        printf("7.   sortie\n");
        printf("------------------------------------------\n");
        printf("   choise le number de service : ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            ajoute();
            break;
        case 2:
            affiche();
            break;
        case 3:
            Recherch();
            break;
        case 4:
            Mettre_a_Jour();
            break;
        case 5:
            Supprimer();
            break;
        case 6:
            AF_N();
           
            break;
        case 7:
            return 0;
            break;

        default:
            printf("le choix est invalide\n");
            break;
        }
    }

    return 0;
}