#include <stdio.h>
#include <stdlib.h>
typedef struct livre
{
    int id;
    char titre[20];
    char auteur[20];
    int nbr;

} livre;
typedef struct noeud
{
    livre var;
    struct livre *suivant;
} noeud;
typedef struct noeud *pile;
//! la pile est une liste chainee de livres
//! la pile est une liste chainee de livres
//! la pile est une liste chainee de livres
pile Inite()
{
    return NULL;
}
int verif_Pile_vide(pile l)
{
    if (l == NULL)
    {
        return 0;
    }
    return 1;
}
pile Empiler(pile l, livre x)
{
    noeud *p = (pile)malloc(sizeof(struct noeud));
    p->var = x;
    p->suivant = l;
    return p;
}
pile Depiler(pile l, livre *x)
{
    if (verif_Pile_vide(l) == 0)
    {
        printf("la pile est vide\n");
        return NULL;
    }
    pile p = l;
    l = l->suivant;
    *x = p->var;
    free(p);
    return l;
}
pile remplire_pile(pile l, int n)
{
    livre x;
    for (int i = 0; i < n; i++)
    {
        x.id = i + 1;
        printf("entrer le titre du livre %d\n", i + 1);
        scanf("%s", x.titre);
        printf("entrer le nom de l'auteur du livre %d\n", i + 1);
        scanf("%s", x.auteur);
        printf("entrer le nombre d'exemplaire du livre %d\n", i + 1);
        scanf("%d", &x.nbr);
        l = Empiler(l, x);
    }
    return l;
}
void Affiche_pile(pile l)
{
    pile p = l;
    while (verif_Pile_vide(p) != 0)
    {
        printf("id: %d |", p->var.id);
        printf("titre: %s |", p->var.titre);
        printf("auteur: %s |", p->var.auteur);
        printf("nombre d'exemplaire: %d \n", p->var.nbr);
        p = p->suivant;
    }
}
pile copie_pile(pile *l)
{
    pile l2 = Inite();
    livre x;
    while (verif_Pile_vide(*l) != 0)
    {
        *l = Depiler(*l, &x);
        l2 = Empiler(l2, x);
    }
    return l2;
}
void copie_pile_recur(pile *l, pile *l2)
{
    if (verif_Pile_vide(*l) == 0)
    {
        return NULL;
    }
    livre x;
    *l = Depiler(*l, &x);
    *l2 = Empiler(l2, x);
    copie_pile_recur(l, l2);
}
int main()
{
    pile l;
    l = Inite();
    int n;
    do
    {
        printf("entrer le nombre de livres a ajouter dans la pile\n");
        scanf("%d", &n);
    } while (n < 0);
    l = remplire_pile(l, n);
    printf("______________________________\n");
    printf("les livres dans la pile 1 sont:\n");
    Affiche_pile(l);
    pile l2;
    l2 = Inite();
    copie_pile_recur(&l, &l2);
    printf("______________________________\n");
    printf("les livres dans la pile 2 sont:\n");
    Affiche_pile(l2);
}
