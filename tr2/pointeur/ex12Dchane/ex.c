/*Enoncé:
1-Définir les types necessaires pour representer une liste doublement chainée d'etudiants
2-déclarer un sous programme qui permet d'initialiser la liste à vide
3-Déclarer un sous programme qui permet d'ajouter un élément à la tete d'une liste
4-Déclarer un sous programme qui permet de remplir une liste par n éléments
5-Écrire deux procédures l’une pour un affichage usuel et l’autre pour un affichage inverse
des éléments de la liste.
6-Ecrire un sous programme qui permet de renvoyer les étudiants qui sont réfusés
7-Ecrire un sous programme qui permet de classer les étudiants dans la liste selon leurs moyennes
7-Ecrire un programme principal qui fait appel aux sous programmes
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct etudiant
{
    char nom[20];
    char prenom[20];
    double moy;
} etudiant;
typedef struct noeud
{
    etudiant val;
    struct noeud *prec;
    struct noeud *suiv;
} noeud;
typedef struct liste
{
    struct noeud *first;
    struct noeud *last;
} liste;
liste init(liste l)
{
    l.first = NULL;
    l.last = NULL;
    return l;
}
etudiant saisie_etud(etudiant e)
{
    printf("entrer le nom de l'etudiant:\n");
    scanf("%s", e.nom);
    printf("entrer le prenom de l'etudiant:\n");
    scanf("%s", e.prenom);
    do
    {
        printf("entrer la moyenne de l'etudiant:\n");
        scanf("%lf", &e.moy);
    } while ((e.moy < 0) || (e.moy > 20));
    return (e);
}
void insertion_tete(liste *l, etudiant e)
{
    noeud *p;
    p = (noeud *)malloc(sizeof(noeud));
    p->val = e;
    p->prec = NULL;
    p->suiv = l->first;
    if (l->first != NULL)
        (l->first)->prec = p;
    else
        l->last = p;
    l->first = p;
}
void insertion_queue(liste *l, etudiant e)
{
    noeud *p;
    p = (noeud *)malloc(sizeof(noeud));
    p->val = e;
    p->prec = l->last;
    p->suiv = NULL;
    if (l->last != NULL)
        (l->last)->suiv = p;
    else
        l->first = p;
    l->last = p;
}
void supprime_tete(liste *l)
{
    noeud *p;
    if (l->first != NULL)
    {
        p = l->first;
        if (l->first == l->last)
        {
            l->first = NULL;
            l->last = NULL;
        }
        else
        {
            l->first = (l->first)->suiv;
            (l->first)->prec = NULL;
        }
        free(p);
    }
}
void supprime_queue(liste *l)
{
    noeud *p;
    if (l->last != NULL)
    {
        p = l->last;
        if (l->first == l->last)
        {
            l->first = NULL;
            l->last = NULL;
        }
        else
        {
            l->last = (l->last)->prec;
            (l->last)->suiv = NULL;
        }
        free(p);
    }
}
void renvoyer_refuse(liste *l)
{
    if (l->first != NULL)
    {
        noeud *tmp, *ptmp, *arenvoyer;
        tmp = l->first;
        ptmp = l->first;
        while (tmp != NULL)
        {
            if (tmp->val.moy < 10)
            {
                if (tmp == l->first)
                {
                    supprime_tete(l);
                    tmp = l->first;
                    ptmp = l->first;
                }
                else
                {
                    if (tmp == l->last)
                    {
                        supprime_queue(l);
                        tmp = NULL;
                    }
                    else
                    {
                        ptmp->suiv = tmp->suiv;
                        ptmp->suiv->prec = ptmp;
                        free(tmp);
                        tmp = ptmp->suiv;
                    }
                }
            }
            else
            {
                ptmp = tmp;
                tmp = tmp->suiv;
            }
        }
    }
}

liste remplir_classe(liste l, int n)
{
    int i;
    etudiant e;
    for (i = 0; i < n; i++)
    {
        printf("saisir letud %d a inserer\n", i + 1);
        e = saisie_etud(e);
        insertion_queue(&l, e);
    }
    return l;
}
void affiche_etud(etudiant e)
{
    printf("Nom=%s	Prenom=%s	Moyenne=%lf\n", e.nom, e.prenom, e.moy);
}
void affiche_classe_normal(liste l)
{
    noeud *tmp;
    int i = 1;
    tmp = l.first;
    while (tmp != NULL)
    {
        printf("Etud num %d est:\n", i);
        affiche_etud(tmp->val);
        i++;
        tmp = tmp->suiv;
    }
}
void affiche_classe_inverse(liste l)
{
    noeud *tmp;
    int i = 1;
    tmp = l.last;
    while (tmp != NULL)
    {
        printf("Etud num %d est:\n", i);
        affiche_etud(tmp->val);
        i++;
        tmp = tmp->prec;
    }
}
noeud *majeur(noeud *tete)
{
    noeud *maj = tete;
    noeud *tmp = tete;
    while (tmp != NULL)
    {
        if (tmp->val.moy > maj->val.moy)
            maj = tmp;
        tmp = tmp->suiv;
    }
    return maj;
}
noeud *classement(noeud *tete)
{
    noeud *maj;
    etudiant e;
    if (tete != NULL)
    {
        maj = majeur(tete);
        if (tete != maj)
        {
            e = tete->val;
            tete->val = maj->val;
            maj->val = e;
        }
        tete->suiv = classement(tete->suiv);
        return tete;
    }
    else
        return NULL;
}
main()
{
    int n;
    printf("Entrer le nbr des etud en classe");
    scanf("%d", &n);
    liste l;
    l = init(l);
    l = remplir_classe(l, n);
    affiche_classe_normal(l);
    renvoyer_refuse(&l);
    printf("******\n");
    affiche_classe_normal(l);
    l.first = classement(l.first);
    printf("******\n");
    affiche_classe_normal(l);
}
