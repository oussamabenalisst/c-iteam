#include <stdio.h>
#include <stdlib.h>
typedef struct article
{
    int ref;
    float prix;
    int qte;
    float vstock;
} article;

typedef struct neoud
{
    article article;
    struct noeud *suivant;
} neoud;
typedef neoud *liste;

void saisi_int(int *n)
{
    do
    {
        printf("Saisir le nombre d'articles : ");
        scanf("%d", n);
    } while (*n < 0);
}

void saisi_article(article *e)
{
    printf("Reference : ");
    scanf("%d", &e->ref);
    do
    {
        printf("Prix : ");
        scanf("%f", &e->prix);
    } while (e->prix < 0);

    do
    {
        printf("Quantite : ");
        scanf("%d", &e->qte);
    } while (e->qte < 0);
    e->vstock = e->prix * e->qte;
}
liste ajouter_element(liste tete, article e)
{
    liste nvl = (liste)malloc(sizeof(struct neoud));
    nvl->article = e;
    nvl->suivant = tete;
    return nvl;
}
liste remplire_element(liste tete, int n)
{
    int i;
    article e;
    for (i = 0; i < n; i++)
    {
        printf("Article %d :\n", i + 1);
        saisi_article(&e);
        tete = ajouter_element(tete, e);
    }
    return tete;
}

void affiche_element(liste tete, int n)
{
    printf("Liste des articles :\n");
    int i;
    for (i = 0; i < n; i++)
    {
        neoud *courant = tete;
        int j;
        for (j = 0; j < i; j++)
            courant = courant->suivant;
        printf("Reference : %d\n", courant->article.ref);
        printf("Prix : %.2f\n", courant->article.prix);
        printf("Quantite : %d\n", courant->article.qte);
        printf("Valeur du stock : %.2f\n", courant->article.vstock);
        printf("\n");
    }
}

void revonu(liste tete)
{
    liste temp = tete;
    double revonu = 0;
    while (tete != NULL)
    {
        revonu += tete->article.vstock;
        tete = tete->suivant;
    }
    printf("Le revenu total des stocks est : %.2f\n", revonu);
}
liste majeur(liste tete)
{
    liste maj = tete;
    liste temp = tete;
    while (temp != NULL)
    {
        if (temp->article.vstock > maj->article.vstock)
            maj = temp;
        temp = temp->suivant;
    }
    return maj;
}

liste rentability(liste tete)
{
    liste maj;
    article e;
    maj = majeur(tete);
    if (maj != tete)
    {
        e = maj->article;
        maj->article = tete->article;
        tete->article = e;
        tete->suivant = rentability(tete->suivant);
    }
    return tete;
}
void affiche_reffice(liste tete)
{
    liste temp = tete;
    while (temp != NULL)
    {
        printf("%d | ", temp->article.ref);
        temp = temp->suivant;
    }
}
int main()
{
    liste tete = NULL;
    int n;
    saisi_int(&n);
    tete = remplire_element(tete, n);
    affiche_element(tete, n);
    revonu(tete);
    tete = rentability(tete);
    printf("\nListe des articles triee par rentabilite :\n");
    affiche_reffice(tete);
}