#include <stdio.h>
#include <stdlib.h>
typedef struct etudient
{
    char nom[20];
    char pre[20];
    int cin;
    double moyenne;
} etudient;
main()
{
    int n;
    do
    {
        printf("donne le nombre de etudient : ");
        scanf("%d", &n);
    } while (n < 0);

    etudient t[n];
    for (int i = 0; i < n; i++)
    {
        printf("donne le nom de etudient %d: ", i + 1);
        scanf("%s", t[i].nom);
        printf("donne le prenom %d: ", i + 1);
        scanf("%s", t[i].pre);
        printf("donne le  cin de etudient %d: ", i + 1);
        scanf("%d", &t[i].cin);
        printf("donne le moyenne de etudient %d: ", i + 1);
        scanf("%lf", &t[i].moyenne);
    }
    // affichage de table
    printf("Nom|Prenom|CIN|Moyenne\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s|%s|%d|%lf\n", t[i].nom, t[i].pre, t[i].cin, t[i].moyenne);
    }
    // recherche de la bonne moyenne
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].moyenne > t[index].moyenne)
        {
            index = i;
        }
    }
    printf("\nEtudient ayant la meilleure moyenne: %s %s (%d) - Moyenne: %.2lf\n", t[index].nom, t[index].pre, t[index].cin, t[index].moyenne);
    // tri table par le moyenne
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
    printf("\nTable triee par moyenne:\n");
    printf("Nom|Prenom|CIN|Moyenne\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s|%s|%d|%lf\n", t[i].nom, t[i].pre, t[i].cin, t[i].moyenne);
    }
}