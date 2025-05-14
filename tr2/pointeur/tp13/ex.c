#include <stdio.h>
#include <stdlib.h>

typedef struct article
{
    int id;
    char Designation[20];
    double QteStock;
    char Date[20];
    double DA;
    double PUA;
    double PUV;
    double VS;
} article;
typedef struct noeud
{
    article info;
    struct noeud *suivant;
    struct noeud *prec;
} noeud;
typedef struct liste
{
    struct noeud *first;
    struct noeud *last;
} liste;

void SaisieUnArticle(article *e)
{
    printf("Saisir l'id de l'article : ");
    scanf("%d", &e->id);
    printf("Saisir la designation de l'article : ");
    scanf("%s", e->Designation);
    printf("Saisir la quantite en stock de l'article : ");
    scanf("%lf", &e->QteStock);
    printf("Saisir la date d'ajout de l'article : ");
    scanf("%s", e->Date);
    printf("Saisir le prix d'achat de l'article : ");
    scanf("%lf", &e->DA);
    printf("Saisir le prix unitaire d'achat de l'article : ");
    scanf("%lf", &e->PUA);
}
int SaisieNbreArticles()
{
    int n;
    do
    {
        printf("Saisir le nombre d'articles : ");
        scanf("%d", &n);
    } while (n < 0);
    return n;
}
void Ajout_Un_Article_Fin(liste *l, article e)
{
    noeud *p = (noeud *)malloc(sizeof(noeud));
    p->info = e;
    p->suivant = NULL;
    p->prec = l->last;
    if (l->first == NULL)
    {
        l->first = p;
    }
    else
    {
        l->last->suivant = p;
    }
    l->last = p;
}
void Inite(liste *l)
{
    l->first = NULL;
    l->last = NULL;
}
void Prise_en_charge_DesArticle(liste *l, int n)
{
    article e;
    for (int i = 0; i < n; i++)
    {
        SaisieUnArticle(&e);
        printf("-----------------------------------\n");
        Ajout_Un_Article_Fin(l, e);
    }
}
noeud *Rechercher_Un_Article(liste l, int code)
{
    noeud *p = l.first;
    while (p != NULL && p->info.id != code)
    {
        p = p->suivant;
    }
    return p;
}
double Prix_Vente(article e)
{
    return (e.PUA * 1.05);
}
double Valeur_On_Stock(liste l, int code)
{

    noeud *p = Rechercher_Un_Article(l, code);
    if (p != NULL)
    {
        return p->info.QteStock * p->info.PUV;
    }
    return -1;
}
void Valeur_On_Stock_Articles(liste *l)
{
    noeud *p = l->first;
    while (p != NULL)
    {
        p->info.PUV = Prix_Vente(p->info);
        p->info.VS = p->info.PUV * p->info.QteStock;
        // p->info.VS = Valeur_On_Stock(*l, p->info.id);
        p = p->suivant;
    }
}
void affichage_Article(article e)
{
    printf("ID: %d\n", e.id);
    printf("Designation: %s\n", e.Designation);
    printf("Quantite en stock: %.2lf\n", e.QteStock);
    printf("Date d'ajout: %s\n", e.Date);
    printf("Prix d'achat: %.2lf\n", e.DA);
    printf("Prix unitaire d'achat: %.2lf\n", e.PUA);
    printf("Prix unitaire de vente: %.2lf\n", e.PUV);
    printf("Valeur sur stock: %.2lf\n", e.VS);
}
void affichage(noeud *p)
{
    if (p != NULL)
    {
        affichage_Article(p->info);
        affichage(p->suivant);
    }
}
void supprimer_queue(liste *l)
{
    if (l->last != NULL)
    {
        noeud *p;
        p = l->last;
        if (p == l->first)
        {
            l->first = NULL;
            l->last = NULL;
        }
        else
        {
            l->last = p->prec;
            l->last->suivant = NULL;
        }
        free(p);
    }
}
void supprimer_tete(liste *l)
{
    if (l->first != NULL)
    {
        noeud *p;
        p = l->first;
        if (p == l->last)
        {
            l->first = NULL;
            l->last = NULL;
        }
        else
        {
            l->first = p->suivant;
            l->first->prec = NULL;
        }
        free(p);
    }
}
void SupprimerUnArticle(liste *l, int code)
{
    noeud *p = Rechercher_Un_Article(*l, code);
    if (p != NULL)
    {
        if (p == l->first)
            supprimer_tete(l);
        else
        {
            if (p == l->last)
                supprimer_queue(l);
            else
            {
                p->suivant->prec = p->prec;
                p->prec->suivant = p->suivant;
                free(p);
            }
        }
    }
}
noeud *rentable(noeud *l)
{
    noeud *max = l;
    noeud *q = l;
    while (q != NULL)
    {
        if (q->info.VS > max->info.VS)
            max = q;

        q = q->suivant;
    }
    return max;
}
noeud *Classement_Rentabilite(noeud *l)
{
    if (l == NULL)
    {
        return NULL;
    }
    noeud *max = rentable(l);
    article e;
    if (max != l)
    {
        e = l->info;
        l->info = max->info;
        max->info = e;
    }
    l->suivant = Classement_Rentabilite(l->suivant);
    return l;
}
liste suppRentable(liste *l)
{
    if (l->first == NULL)
    {
        return *l;
    }
    noeud *p = l->first;
    while (p != NULL)
    {
        if (p->info.VS < 100)
        {
            SupprimerUnArticle(l, p->info.id);
        }
        p = p->suivant;
    }
}

int main()
{
    int n = SaisieNbreArticles();
    liste l;
    Inite(&l);
    Prise_en_charge_DesArticle(&l, n);
    Valeur_On_Stock_Articles(&l);
    printf("_________affichage_________\n");
    affichage(l.first);
    int code;
    do
    {
        printf("[SUPP]Donne Code : ");
        scanf("%d", &code);
    } while (code < 0);
    SupprimerUnArticle(&l, code);
    l.first = Classement_Rentabilite(l.first);
    printf("_________affichageTRI_________\n");
    affichage(l.first);
}
