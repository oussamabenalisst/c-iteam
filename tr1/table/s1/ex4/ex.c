#include <stdio.h>
#include <stdlib.h>

main()
{
    int n;
    do
    {
        printf("Enter le nomber des etudient : ");
        scanf("%d", &n);
    } while (n <= 0 || n > 20);
    float t[n];
    //>>> remplir les moyennes des etudiants au tableau

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Enter la moyenne de etudient %d : ", i + 1);
            scanf("%f", &t[i]);
        } while (t[i] < 0 || t[i] > 20);
    }
    //>>> afficher les moyennes des etudiants
    for (int i = 0; i < n; i++)
    {
        printf("%f|", t[i]);
    }
    //>>>afficher la moyenne max et min
    float max = 0;
    float min = 100;
    for (int i = 0; i < n; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }
        if (t[i] < min)
        {
            min = t[i];
        }
    }
    printf("\nMoyenne max : %f", max);
    printf("\nMoyenne min : %f", min);
    //>>> trier les moyennes des etudiants dans l'ordre decroissant
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (t[j] > t[max])
                max = j;
        }
        if (max != i)
        {
            float aux = t[i];
            t[i] = t[max];
            t[max] = aux;
        }
    }
    //>>> afficher les moyennes des etudiants triees
    for (int i = 0; i < n; i++)
    {
        printf("\n%f|", t[i]);
    }
}