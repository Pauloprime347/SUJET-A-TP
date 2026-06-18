#include <stdio.h>
#include <string.h>
#include "livre.h"

Livre bibliotheque[MAX];
int nbLivres = 0;

void ajouterLivre()
{
    if(nbLivres >= MAX)
    {
        printf("Bibliotheque pleine.\n");
        return;
    }

    printf("Titre : ");
    getchar();
    fgets(bibliotheque[nbLivres].titre,100,stdin);
    bibliotheque[nbLivres].titre[strcspn(bibliotheque[nbLivres].titre,"\n")] = 0;

    printf("Auteur : ");
    fgets(bibliotheque[nbLivres].auteur,100,stdin);
    bibliotheque[nbLivres].auteur[strcspn(bibliotheque[nbLivres].auteur,"\n")] = 0;

    printf("Annee : ");
    scanf("%d",&bibliotheque[nbLivres].annee);

    bibliotheque[nbLivres].disponible = 1;

    nbLivres++;

    printf("Livre ajoute.\n");
}

void afficherLivres()
{
    if(nbLivres==0)
    {
        printf("Aucun livre.\n");
        return;
    }

    for(int i=0;i<nbLivres;i++)
    {
        printf("\n%d\n",i+1);
        printf("Titre : %s\n",bibliotheque[i].titre);
        printf("Auteur : %s\n",bibliotheque[i].auteur);
        printf("Annee : %d\n",bibliotheque[i].annee);

        if(bibliotheque[i].disponible)
            printf("Disponible\n");
        else
            printf("Emprunte\n");
    }
}

void rechercherLivre()
{
    char recherche[100];
    int trouve = 0;

    getchar();

    printf("Recherche : ");
    fgets(recherche,100,stdin);
    recherche[strcspn(recherche,"\n")] = 0;

    for(int i=0;i<nbLivres;i++)
    {
        if(strstr(bibliotheque[i].titre,recherche)!=NULL ||
           strstr(bibliotheque[i].auteur,recherche)!=NULL)
        {
            printf("%d - %s (%s)\n",i+1,bibliotheque[i].titre,bibliotheque[i].auteur);
            trouve = 1;
        }
    }

    if(!trouve)
        printf("Aucun resultat.\n");
}

void emprunterRendre()
{
    int num;

    afficherLivres();

    printf("Numero : ");
    scanf("%d",&num);

    if(num<1 || num>nbLivres)
    {
        printf("Numero invalide.\n");
        return;
    }

    bibliotheque[num-1].disponible = !bibliotheque[num-1].disponible;

    printf("Statut modifie.\n");
}

void supprimerLivre()
{
    int num;

    afficherLivres();

    printf("Numero : ");
    scanf("%d",&num);

    if(num<1 || num>nbLivres)
    {
        printf("Numero invalide.\n");
        return;
    }

    for(int i=num-1;i<nbLivres-1;i++)
        bibliotheque[i]=bibliotheque[i+1];

    nbLivres--;

    printf("Livre supprime.\n");
}