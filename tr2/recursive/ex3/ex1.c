#include <stdio.h>
#include <stdlib.h>
typedef struct employe
{
    int mat;
    char nom[20], prenom[20];
    int code;
    double salbrut;
    double cout;
} employe;
employe saisi_employe(employe e)
{
    printf("employ \n");
    printf("donne matricule : ");
    scanf("%d", &e.mat);
    printf("donne nom : ");
    scanf("%s", e.nom);
    printf("donne prenom : ");
    scanf("%s", e.prenom);
    printf("donne code : ");
    scanf("%d", &e.code);
    printf("donne salaire brut : ");
    scanf("%lf", &e.salbrut);
    return e;
}
void saisis_employes(employe t[], int n, int i)
{
    if (i < n)
    {
        t[i] = saisi_employe(t[i]);
        saisis_employes(t, n, i + 1);
    }
}
void aff(employe e)
{
    printf("%d %s %s %d %.2lf\n", e.mat, e.nom, e.prenom, e.code, e.salbrut);
}
void aff_table(employe t[], int n, int i)
{
    if (i < n)
    {
        aff(t[i]);
        aff_table(t, n, i + 1);
    }
}
void saisis_count(employe t[], int n, int i)
{
    if (i < n)
    {
        printf("donne cout de %s : ", t[i].nom);
        scanf("%lf", &t[i].cout);
        saisis_count(t, n, i + 1);
    }
}
main()
{
    int n;
    do
    {
        printf("donne le nombre de employe : ");
        scanf("%d", &n);
    } while (n < 0);

    employe t[n];
    int i = 0;
    saisis_employes(t, n, i);
    saisi_cout(t, n, i);
    aff_table(t, n, i);
}