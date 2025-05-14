#include <stdlib.h>
#include <stdio.h>
typedef struct etudiant
{
    char nom[30];
    char prenom[30];
    double moyenne;
} etudiant;
void saisie_int(int *p)
{
    do
    {
        printf("Saisir un entier positif : ");
        scanf("%d", p);
    } while (*p < 0);
}

void saisie_etudiant(etudiant *p)
{
    printf("Saisir le nom : ");
    scanf("%s", p->nom);
    printf("Saisir le prenom : ");
    scanf("%s", p->prenom);
    printf("Saisir la moyenne : ");
    scanf("%lf", &p->moyenne);
}
void remplire_table(etudiant t[], int n)
{
    etudiant *p;
    for (p = t; p < t + n; p++)
    {
        saisie_etudiant(p);
    }
}
void affiche_table(etudiant t[], int n)
{
    etudiant *p;
    for (p = t; p < t + n; p++)
    {
        printf("Nom : %s, Prenom : %s, Moyenne : %.2lf\n", p->nom, p->prenom, p->moyenne);
    }
}

void inverse_table(etudiant t[], int n)
{
    etudiant *p;
    etudiant *f;
    p = t;
    f = t + n - 1;
    while (f > p)
    {
        etudiant temp = *p;
        *p = *f;
        *f = temp;
        p++;
        f--;
    }
}
int main()
{
    int n;
    saisie_int(&n);
    etudiant t[n];
    remplire_table(t, n);
    printf("Contenu du tableau : \n");
    affiche_table(t, n);
    inverse_table(t, n);
    printf("\nTableau inverse : \n");
    affiche_table(t, n);
}
