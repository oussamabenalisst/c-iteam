#include <stdio.h>
#include <stdlib.h>
typedef struct noeud
{
    int num;
    struct noeud *susivant;
} noeud;
typedef struct noeud *liste;

liste Inite()
{
    return NULL;
}
liste ajout_element(liste tete, int x)
{
    liste nvl = (liste)malloc(sizeof(struct noeud));
    nvl->num = x;
    nvl->susivant = tete;
    return nvl;
}

void affichage_element(liste tete)
{
    liste p = tete;
    while (p != NULL)
    {
        printf("%d", p->num);
        p = p->susivant;
    }
    printf("\n");
}
liste ajout_element_fin(liste tete, int x)
{
    liste temp, nvl;
    nvl = (liste)malloc(sizeof(struct noeud));
    nvl->num = x;
    nvl->susivant = NULL;
    if (tete == NULL)
        return nvl;
    else
    {
        temp = tete;
        while (temp->susivant != NULL)
            temp = temp->susivant;
        temp->susivant = nvl;
        return tete;
    }
}
liste supprimer_element(liste tete)
{
    if (tete == NULL)
    {
        printf("La liste est vide.\n");
        return tete;
    }
    else
    {
        liste temp = tete;
        tete = tete->susivant;
        free(temp);
        return tete;
    }
}

liste supprimer_element_X(liste tete, int x)
{
    if (tete == NULL)
        return tete;
    if (tete->num == x)
    {
        liste temp = tete;
        tete = tete->susivant;
        free(temp);
        return tete;
    }
    liste temp = tete;
    while (temp->susivant != NULL && temp->susivant->num != x)
        temp = temp->susivant;
    liste temp2 = temp->susivant;
    temp->susivant = temp2->susivant;
    free(temp2);
    return tete;
}
liste supprimer_element_fin(liste tete)
{
    if (tete == NULL)
        return NULL;
    if (tete->susivant == NULL)
    {
        free(tete);
        return NULL;
    }
    liste temp = tete;
    while (temp->susivant->susivant != NULL)
    {
        temp = temp->susivant;
    }
    free(temp->susivant);
    temp->susivant = NULL;
    return tete;
}
int main()
{
    // create un liste vide NULL
    liste tete = Inite();
    // ajouter un element dans la liste
    int x;
    for (int i = 0; i < 4; i++)
    {
        printf("Ajouter l'element %d dans la liste : ", i + 1);
        scanf("%d", &x);
        tete = ajout_element(tete, x);
    }
    // ajoute a la fin
    tete = ajout_element_fin(tete, 99);
    // affichage d'un liste
    affichage_element(tete);
    // supprimer un element dans la liste
    tete = supprimer_element(tete);
    affichage_element(tete);
    tete = supprimer_element_X(tete, 3);
    // affichage_element(tete);
    tete = supprimer_element_fin(tete);
    // affichage de la liste

    affichage_element(tete);
}
