#ifndef LIVRE_H
#define LIVRE_H

#define MAX 100

typedef struct
{
    char titre[100];
    char auteur[100];
    int annee;
    int disponible;
} Livre;

extern Livre bibliotheque[MAX];
extern int nbLivres;

void ajouterLivre();
void afficherLivres();
void rechercherLivre();
void emprunterRendre();
void supprimerLivre();

#endif