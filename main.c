#include <stdio.h>
#include "livre.h"
#include "fichier.h"

int main()
{
    int choix;

    charger();

    do
    {
        printf("\n=====================\n");
        printf(" BIBLIOTHEQUE\n");
        printf("=====================\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. Rechercher\n");
        printf("4. Emprunter/Rendre\n");
        printf("5. Supprimer\n");
        printf("6. Sauvegarder et quitter\n");

        printf("Choix : ");
        scanf("%d",&choix);

        switch(choix)
        {
            case 1:
                ajouterLivre();
                break;

            case 2:
                afficherLivres();
                break;

            case 3:
                rechercherLivre();
                break;

            case 4:
                emprunterRendre();
                break;

            case 5:
                supprimerLivre();
                break;

            case 6:
                sauvegarder();
                printf("Au revoir.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    }while(choix!=6);

    return 0;
}