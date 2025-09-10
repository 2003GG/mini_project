#include <stdio.h>
#include <string.h>
int i, n, j, count = 0, d, novq;

char rech[20];

typedef struct
{
    char titre[100];
    char auteur[100];
    float prix;
    int quan;
    char isbn[100];
} book;

book info[100];
book tmp;
void ajoute()
{

    printf("*******Ajouter un Livre*********\n");
    printf("commbient des livres : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("------------------------------------\n");

        printf("Titre du livre : ");
        scanf(" %[^\n]s", info[i].titre);
        printf("Auteur du livre : ");
        scanf(" %[^\n]s", info[i].auteur);
        printf("Prix du livre : ");
        scanf("%f", &info[i].prix);
        printf("Quantité en stock : ");
        scanf("%d", &info[i].quan);
        printf("Entrez l'ISBN : ");
        scanf(" %[^\n]s",info[i].isbn);
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
            printf("********le livre numero (%d) *********\n", i + 1);
            printf("Titre du livre     : %s\n", info[i].titre);

            printf("Auteur du livre    : %s\n", info[i].auteur);

            printf("Prix du livre      : %.2f\n", info[i].prix);

            printf("Quantité en stock  : %d\n", info[i].quan);

            printf("le ISBN : %s\n", info[i].isbn);
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
            printf("********le livre numero (%d) *********\n", i + 1);
            printf("Titre du livre      :  %s\n", info[i].titre);
        }
        printf("choise le titre de livre : ");
        scanf(" %[^\n]s", tit);
        for (i = 0; i < count; i++)
        {
            if (strcasecmp(info[i].titre, tit) == 0)
            {
                printf("entrez la novelle quantite : ");
                scanf("%d", &info[i].quan);
            }
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
            printf("Titre du livre numero : %s\n", info[i].titre);
        }

        printf("Choisissez le titre du livre que vous souhaitez supprimer : ");
        scanf(" %[^\n]s", tis);

        for (i = 0; i < count ; i++)
        {
            if (strcasecmp(info[i].titre, tis) == 0)
            {
                printf("Le livre de nom (%s) est disponible dans la libraire\n", tis);
                for (j = i + 1; j < count; j++)
                {
                    info[i] = info[j];

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
    char NISBN[30];

    int pos = 0;
    int inf = 0;
    int sup = count - 1;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (info[j].isbn < info[i].isbn)
            {
                tmp = info[j];
                info[j] = info[i];
                info[i] = tmp;
            }
        }
    }

    printf("le ISBN que recherche :  ");
    scanf("%s", NISBN);

    while (inf <= sup)
    {

        int mid = (inf + sup) / 2;

        if (strcasecmp(info[mid].isbn, NISBN) == 0)
        {

            printf("le ISBN (%s)est  existe a la position %d\n", info[mid].isbn, mid+1);
            printf("-------------------------------------------------------\n");
            printf("le titre de livre : %s\n", info[i].titre);
            printf("l'auteur : %s\n", info[mid].auteur);
            printf("le prix : %.2f\n",info[mid].prix);
            printf("Quantite : %d\n", info[mid].quan);
            printf("ISBN : %s\n", info[mid].isbn);
            pos = 1;
            break;
        }

        if (info[mid].isbn < NISBN)
        {

            inf = mid + 1;
        }

        if (info[mid].isbn > NISBN)
        {
            sup = mid - 1;
        }
    }

    if (pos != 1)
    {
        printf("ISBN : (%s) n'est pas existe \n", NISBN);
    }
}

int Nombre_total()
{

    int total = 0;
    for (i = 0; i < count; i++)
    {
        total = total + info[i].quan;
    }

    return total;
}

void tri(int o)
{
    
    printf("1. tri coissant\n");
    printf("2. tri decroissant\n");
    printf("le numero de choix : ");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
        // croissant
        for (i = 0; i < count - 1; i++)
        {
            for (j = i + 1; j < count; j++)
            {
                if (info[j].quan < info[i].quan)
                {
                    tmp = info[j];
                    info[j] = info[i];
                    info[i] = tmp;
                }
            }
        }
        affiche();

        break;
    case 2:
        // decroissatn

        for (i = 0; i < count - 1; i++)
        {
            for (j = i + 1; j < count; j++)
            {
                if (info[j].quan > info[i].quan)
                {
                    tmp = info[j];
                    info[j] = info[i];
                    info[i] = tmp;
                }
            }
        }
        affiche();

        break;

    default:
        printf("ERROR");
        break;
    }
}
