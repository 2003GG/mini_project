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
            printf("********le livre numero (%d) *********\n",i+1);
            printf("Titre du livre     : %s\n", info[i].titre);

            printf("Auteur du livre    : %s\n",info[i].auteur);

            printf("Prix du livre      : %.2f\n", info[i].prix);

            printf("Quantité en stock  : %d\n", info[i].quan);
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
             printf("********le livre numero (%d) *********\n",i+1);
            printf("Titre du livre      :  %s\n",  info[i].titre);

            
        }
        printf("choise le titre de livre : ");
        scanf(" %[^\n]s", tit);
        for ( i = 0; i < count; i++)
        {
        if(strcasecmp(info[i].titre,tit)==0){
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
            printf("Titre du livre numero (%d): %s\n", i + 1, info[i].titre);
        }

        printf("Choisissez le titre du livre que vous souhaitez supprimer : ");
        scanf(" %[^\n]", tis);

        for (i = 0; i < count - 1; i++)
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

    printf("******Rechercher un livre*******\n");
    printf("entrez le titre de livre : ");
    scanf(" %[^\n]s", rech);
    for (i = 0; i < count; i++)
    {
        if (strcasecmp(info[i].titre, rech) == 0)
        {
            printf("Le livre de nom (%s) est disponible dans la libraire\n", rech);
            printf("*****les informations de livre*****\n");
            printf("-------------------------------------------------\n");
            printf("Titre du livre de livre de numero (%d) : %s\n", i + 1, rech);

            printf("Auteur du livre  : %s\n", info[i].auteur);

            printf("Prix du livre      : %.2f\n",  info[i].prix);

            printf("Quantité en stock : %d\n",  info[i].quan);
            printf("-------------------------------------------------\n");
        }
    }
}
int Nombre_total()
{
   
   int total=0;
   for(i=0;i<count;i++){
    total=total+info[i].quan;
   }

   
    return total;
}