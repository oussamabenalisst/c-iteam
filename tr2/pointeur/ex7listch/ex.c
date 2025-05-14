#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant
{
    char nom[30];
    char prenom[30];
    double moy;
} etudiant;

typedef struct noeud
{
    etudiant etud;
    struct noeud *suivant;
} noeud;
typedef noeud *liste;

liste inite()
{
    return NULL;
}

void ajoute_etudiant(etudiant *etud)
{
    printf("Saisir nom et prenom de l'etudiant : ");
    scanf("%s %s", etud->nom, etud->prenom);
    do
    {
        printf("Saisir la moyenne de l'etudiant : ");
        scanf("%lf", &etud->moy);
    } while (etud->moy < 0 || etud->moy > 20);
}

liste ajoute_tete_element(liste tete, etudiant etud)
{
    liste temp = tete;
    temp = (liste)malloc(sizeof(struct noeud));
    temp->etud = etud;
    temp->suivant = NULL;
    temp->suivant = tete;
    return temp;
}
void affiche_etud(etudiant e)
{
    printf("Nom : %s\nPrenom : %s\nMoyenne : %.2lf\n", e.nom, e.prenom, e.moy);
}

void affich_liste(liste tete)
{
    liste temp = tete;
    while (temp != NULL)
    {
        printf("---------");
        affiche_etud(temp->etud);
        temp = temp->suivant;
    }
    printf("\n");
}

liste supprimer_etudiant(liste tete)
{
    if (tete == NULL)
        return NULL;
    else
    {
        liste ptmp = tete, arenvoyer;
        liste temp = tete;
        while (temp != NULL)
        {
            if (temp->etud.moy < 10)
            {
                if (temp == tete)
                {
                    arenvoyer = tete;
                    tete = tete->suivant;
                    free(arenvoyer);
                    temp = tete;
                }
                else
                {
                    ptmp->suivant = temp->suivant;
                    free(temp);
                    temp = ptmp->suivant;
                }
            }
            ptmp = temp;
            temp = temp->suivant;
        }
    }
    return tete;
}

liste majeur(liste tete)
{
    etudiant e;
    liste maj = tete;
    liste temp = tete;
    while (temp != NULL)
    {
        if (temp->etud.moy < maj->etud.moy)
        {
            e = maj->etud;
            maj->etud = temp->etud;
            temp->etud = e;
        }
        temp = temp->suivant;
    }
    return maj;
}

liste trie(liste tete)
{
    liste maj;
    etudiant e;
    if (tete != NULL)
    {
        maj = majeur(tete);
        if (maj != tete)
        {
            e = tete->etud;
            tete->etud = maj->etud;
            maj->etud = e;
        }
        tete->suivant = trie(tete->suivant);
        return tete;
    }
    else
        return NULL;
}
int main()
{
    liste tete = inite();
    etudiant e;
    for (int i = 0; i < 3; i++)
    {
        ajoute_etudiant(&e);
        tete = ajoute_tete_element(tete, e);
    }
    affich_liste(tete);
    tete = supprimer_etudiant(tete);
    printf("Liste des etudiants avec moyenne superieure ou egale a 10 :\n");
    affich_liste(tete);
    tete = trie(tete);
    return 0;
}
