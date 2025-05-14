#include <stdio.h>
#include <stdlib.h>
typedef struct etudiant
{
    char nom[30];
    char prenom[30];
    double moyenne;
} etudiant;

void saisie_etudiant(int *n)
{
    do
    {
        printf("Saisir le nombre d'etudiants : ");
        scanf("%d", n);
    } while (*n < 0);
}

void remplire_etudiant(etudiant t[], int n)
{
    etudiant *p;
    for (p = t; p < t + n; p++)
    {
        printf("Saisir le nom de l'etudiant %d : ", p - t + 1);
        scanf("%s", p->nom);
        printf("Saisir le prenom de l'etudiant %d : ", p - t + 1);
        scanf("%s", p->prenom);
        printf("Saisir la moyenne de l'etudiant %d : ", p - t + 1);
        scanf("%lf", &p->moyenne);
    }
}

void affiche_tab(etudiant t[], int n)
{
    etudiant *p;
    for (p = t; p < t + n; p++)
    {
        printf("%s %s %.2lf\n", p->nom, p->prenom, p->moyenne);
    }
}

void supp_tab(etudiant t[], int *n)
{
    etudiant *q = t;
    etudiant *p;
    for (p = t; p < t + *n; p++)
    {
        *q = *p;
        if (p->moyenne >= 10)
        {
            q++;
        }
    }
    *n = q - t;
}
main()
{

    int n;
    saisie_etudiant(&n);
    etudiant tab[n];
    remplire_etudiant(tab, n);
    affiche_tab(tab, n);
    printf("----------------------------");
    supp_tab(tab, &n);
    printf("----------------------------");
    affiche_tab(tab, n);
}
