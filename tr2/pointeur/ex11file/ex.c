#include <stdio.h>
#include <stdlib.h>

typedef struct client
{
    char nom[20];
    char prenom[20];
    char transaction[20];
    int temps_attente;
} client;

typedef struct noeud
{
    client var;
    struct noeud *suivant;
} noeud;
typedef struct file
{
    struct noeud *tete;
    struct noeud *queue;
} file;

file Inite(file f)
{
    f.tete = NULL;
    f.queue = NULL;
    return f;
}
//!!! ******** procedure Inite **************
//* void Inite(file *f){
//*     f->tete = NULL;
//*     f->queue = NULL;
//* }
//!!! ************ procedure Inite *******************
int file_vide(file f)
{
    if (f.tete == NULL)
    {
        return 1;
    }
    return 0;
}
file Enfiler(file f, client x)
{
    struct noeud *p = (struct noeud *)malloc(sizeof(struct noeud));
    p->var = x;
    p->suivant = NULL;
    if (file_vide(f) == 1)
    {
        f.tete = p;
        f.queue = p;
    }
    else
    {
        f.queue->suivant = p;
        f.queue = p;
    }
    return f;
}
//!!! ******** procedure Enfiler **************
//* void Enfiler(file *f, client x)
//* {
//*     struct noeud *p = (struct noeud *)malloc(sizeof(struct noeud));
//*     p->var = x;
//*     p->suivant = NULL;
//*     if (file_vide(*f) == 1)
//*     {
//*         f->tete = p;
//*         f->queue = p;
//*     }
//*     else
//*     {
//*         f->queue->suivant = p;
//*         f->queue = p;
//*     }
//* }
//!!! ************ procedure Enfiler *******************

file Defiler(file f, client *x)
{
    if (file_vide(f) == 1)
    {
        printf("la file est vide\n");
        return f;
    }
    if (f.tete->suivant == NULL)
    {
        *x = f.tete->var;
        free(f.tete);
        f.tete = NULL;
        f.queue = NULL;
        return f;
    }
    struct noeud *p = f.tete;
    f.tete = f.tete->suivant;
    *x = p->var;
    free(p);
    return f;
}
//!!! ******** procedure Defiler **************
//* void Defiler(file *f, client *x)
//* {
//*     if (file_vide(*f) == 1)
//*     {
//*         printf("la file est vide\n");
//*     }
//*     else
//*     {
//*         struct noeud *p = f->tete;
//*         f->tete = f->tete->suivant;
//*         *x = p->var;
//*         if (f->tete == NULL)
//*         {
//*             f->queue = NULL;
//*         }
//*         free(p);
//*     }
//* }
//!!! ******** procedure Defiler **************
void affichage_client(client x)
{
    printf("nom: %s |", x.nom);
    printf("prenom: %s |", x.prenom);
    printf("transaction: %s |", x.transaction);
    printf("temps d'attente: %d \n", x.temps_attente);
}
void affiche_file(file f)
{
    struct noeud *p = f.tete;
    int i = 0;
    while (p != NULL)
    {
        printf("=== client %d === ", i + 1);
        affichage_client(p->var);
        p = p->suivant;
        i++;
    }
}
void calcul_temps_attente(file f, client *cl)
{
    struct noeud *p = f.tete;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->suivant;
    }
    cl->temps_attente = i * 5;
}
void saisi_client(client *x)
{
    printf("entrer le nom du client\n");
    scanf("%s", x->nom);
    printf("entrer le prenom du client\n");
    scanf("%s", x->prenom);
    printf("entrer la transaction du client\n");
    scanf("%s", x->transaction);
}
int main()
{
    file f = Inite(f);
    int n, temps;
    do
    {
        printf("entrer le nombre de client\n");
        scanf("%d", &n);
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        client x;
        saisi_client(&x);
        calcul_temps_attente(f, &x);
        f = Enfiler(f, x);
    }
    affiche_file(f);
}
