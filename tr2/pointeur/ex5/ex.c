#include <stdio.h>
#include <stdlib.h>

void saisi_taille(int *p)
{
    do
    {
        printf("Saisir une taille : ");
        scanf("%d", p);
    } while (*p < 0);
}
void remplier(int a[], int n)
{
    int *p;
    for (p = a; p < a + n; p++)
    {
        printf("Saisir un entier : ");
        scanf("%d", p);
    }
    printf("\n");
}

void ranger(int a[], int b[], int n, int m)
{
    int *p;
    int *q;
    for (p = a + n, q = b; q < b + m; q++, p++)
    {
        *p = *q;
    }
}

void afficher(int a[], int n, int m)
{
    int *p;
    for (p = a; p < a + n + m; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
}

void inverse(int a[], int n)
{
    int *p = a;
    int *q = a + n - 1;
    while (p < q)
    {
        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}

main()
{
    int n, m;
    saisi_taille(&n);
    saisi_taille(&m);
    int a[n + m], b[m];
    printf("Tableau A : \n");
    remplier(a, n);
    printf("Tableau B : \n");
    remplier(b, m);
    ranger(a, b, n, m);
    printf("Tableau fusionne : ");
    afficher(a, n, m);
    printf("Tableau inverse : ");
    inverse(a, m + n);
    afficher(a, n, m);
}