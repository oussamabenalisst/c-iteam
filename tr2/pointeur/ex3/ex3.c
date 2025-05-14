#include <stdio.h>
#include <stdlib.h>

void sasi_taille(int *n)
{
    do
    {
        printf("Enter the size of the array : ");
        scanf("%d", n);
    } while (*n < 0);
}

void remplier_table(int t[], int n)
{
    int *p;
    for (p = t; p < t + n; p++)
    {
        printf("Enter the value of element %d : ", p - t + 1);
        scanf("%d", p);
    }
}

void affiche_table(int t[], int n)
{
    int *p;
    for (p = t; p < t + n; p++)
    {

        printf("%d ", *p);
    }
    printf("\n");
}

void supprimer_x(int t[], int x, int *n)
{
    int *p;
    int *q = t;
    for (p = t; p < t + *n; p++)
    {
        *q = *p;
        if (*q != x)
        {
            q++;
        }
    }
    *n = q - t;
}

int main()
{
    int n;
    sasi_taille(&n);
    int t[n];
    remplier_table(t, n);
    affiche_table(t, n);
    int x;
    sasi_taille(&x);
    supprimer_x(t, x, &n);
    affiche_table(t, n);
}
