#include <stdio.h>
#include <stdlib.h>
typedef struct etudient
{
    char nom[20];
    char pre[20];
    int cin;
    double moyenne;
} etudient;
void saisie_etudient(etudient *e)
{
    printf("donne nom de etudient : ");
    scanf("%s", e->nom);
    printf("donne prenom de etudient : ");
    scanf("%s", e->pre);
    printf("donne cin de etudient : ");
    scanf("%d", &e->cin);
    printf("donne la moyenne de etudient : ");
    scanf("%lf", &e->moyenne);
}
void remplir_etudient(etudient t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        saisie_etudient(&t[i]);
    }
}
void affichage(etudient e)
{
    printf("etudiant : %s %s\ncin : %d\nmoyenne : %.2lf\n", e.nom, e.pre, e.cin, e.moyenne);
}
void aff_tab(etudient t[], int n)
{
    printf("Nom|Prenom|CIN|Moyenne\n");
    for (int i = 0; i < n; i++)
    {
        affichage(t[i]);
    }
    printf("\n");
}
void tri(etudient t[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (t[j].moyenne < t[j + 1].moyenne)
            {
                etudient temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    aff_tab(t, n);
}
etudient selections_majeur(etudient t[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (t[i].moyenne > t[max].moyenne)
            max = i;
    }
    return t[max];
}
main()
{
    int n;
    do
    {
        printf("donne n : ");
        scanf("%d", &n);
    } while (n < 0);
    etudient t[n];
    remplir_etudient(t, n);
    aff_tab(t, n);
    tri(t, n);
    printf("etudiant ayant la meilleure moyenne :\n");
    affichage(selections_majeur(t, n));
}
