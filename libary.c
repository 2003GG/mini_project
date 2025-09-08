#include <stdio.h>
#include <string.h>
int i, n, j, count = 0, d, novq, K = 0;
char rech[20];

typedef struct
{
    char titre[100];
    char auteur[100];
    float prix;
    int quan;

} book;

book info[100];
void ajoute()
{

    printf("*******Ajouter un Livre*********\n");
    printf("commbient des livres : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("------------------------------------\n");

        printf("Titre du livre de numero: ");
        scanf(" %[^\n]s", info[i].titre);
        printf("Auteur du livre : ");
        scanf(" %[^\n]s", info[i].auteur);
        printf("Prix du livre : ");
        scanf("%f", &info[i].prix);
        printf("Quantité en stock : ");
        scanf("%d", &info[i].quan);
    }

    count = count + n;
}
void affiche()
{
    if (count <= 0)
    {
        printf("******la libraire est vide*******\n");
    }
    if (count > 0)
    {
        printf("*******Afficher Tous les Livres Disponibles*********\n");
        for (i = 0; i < count; i++)
        {
            printf("-------------------------------------------------\n");
            printf("Titre du livre de livre numero (%d): %s\n", i + 1, info[i].titre);

            printf("Auteur du livre de numero      (%d) : %s\n", i + 1, info[i].auteur);

            printf("Prix du livre de numero        (%d): %.2f\n", i + 1, info[i].prix);

            printf("Quantité en stock de numero    (%d) : %d\n", i + 1, info[i].quan);
        }
    }
}

void Mettre_a_Jour()
{

    char tit[20];
    if (count <= 0)
    {
        printf("la libraire est vide \n");
    }

    if (count > 0)
    {
        for (i = 0; i < count; i++)
        {
            printf("-------------------------------------------------\n");
            printf("Titre du livre de livre de numero (%d) : %s\n", i + 1, info[i].titre);

            printf("Auteur du livre de numero         (%d) : %s\n", i + 1, info[i].auteur);

            printf("Prix du livre de numero           (%d) : %.2f\n", i + 1, info[i].prix);

            printf("Quantité en stock de numero       (%d) : %d\n", i + 1, info[i].quan);
        }
        printf("choise le numero de livre : ");
        scanf("%d", &d);
        printf("entrez la novelle quantite : ");
        scanf("%d", &novq);

        for (i = 0; i < count; i++)
        {
            info[d - 1].quan = novq;
        }

        printf("le quantite est mise a joure \n");
    }
}

void Supprimer()
{
    char tis[100];
    if (count < 0)
    {
        printf("la libraire est vide \n");
    }
    if (count > 0)
    {

        printf("******Supprimer un Livre********\n");

        for (i = 0; i < count; i++)
        {
            printf("-------------------------------------------------\n");
            printf("Titre du livre numero (%d): %s\n", i + 1, info[i].titre);
        }

        printf("Choisissez le titre du livre que vous souhaitez supprimer : ");
        scanf(" %[^\n]", tis);

        for (i = 0; i < count - 1; i++)
        {
            if (strcmp(info[i].titre, tis) == 0)
            {
                printf("Le livre de nom (%s) est disponible dans la libraire\n", tis);
                for (j = i + 1; j < count; j++)
                {
                    info[i] = info[j];
                    K = K - info[j].quan;
                }

                count--;
                printf("Le livre intitulé (%s) a été supprimé du stock.\n", tis);
                break;
            }

            if (strcmp(info[i].titre, tis) == 1)
            {
                printf("Le livre de nom (%s) n'est pas disponible dans la librairie !!!!\n", tis);
            }
        }
    }
}

void Recherch()
{

    printf("******Rechercher un livre*******\n");
    printf("entrez le titre de livre : ");
    scanf(" %[^\n]s", rech);
    for (i = 0; i < count; i++)
    {
        if (strcascmp(info[i].titre, rech) == 0)
        {
            printf("Le livre de nom (%s) est disponible dans la libraire\n", rech);
            printf("*****les informations de livre*****\n");
            printf("-------------------------------------------------\n");
            printf("Titre du livre de livre de numero (%d) : %s\n", i + 1, rech);

            printf("Auteur du livre de numero         (%d) : %s\n", i + 1, info[i].auteur);

            printf("Prix du livre de numero           (%d) : %.2f\n", i + 1, info[i].prix);

            printf("Quantité en stock de numero       (%d) : %d\n", i + 1, info[i].quan);
            printf("-------------------------------------------------\n");
        }
    }
}
int AF_N()
{
    for (i = 0; i < count; i++)
    {
        K = K + info[i].quan;
    }

    printf("\ntotal des livres est : %d", K);
    return K;
}