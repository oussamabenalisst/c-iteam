#include <stdio.h>
#include <stdlib.h>

main()
{
    int n1, n2;
    do
    {
        printf("donne le n1 : ");
        scanf("%d", &n1);
    } while (n1 < 0);
    do
    {
        printf("donne le n1 : ");
        scanf("%d", &n2);
    } while (n2 < 0);
    float t1[n1], t2[n2], t3[n1 + n2];
    for (int i = 0; i < n1; i++)
    {
        printf("donne la note %d de etudiant : ", i + 1);
        scanf("%f", &t1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        printf("donne la note %d de etudiant : ", i + 1);
        scanf("%f", &t2[i]);
    }

    int j = 0, k = 0, i = 0;
    while (j < n1 && k < n2)
    {
        if (t1[j] < t2[k])
        {
            t3[i] = t1[j];
            j++;
        }
        else
        {
            t3[i] = t2[k];
            k++;
        }
        i++;
    }
    if (k < n2)
    {
        for (int l = k; l < n2; l++)
        {
            t3[i] = t2[l];
            i++;
        }
    }
    else
    {
        if (j < n1)
        {
            for (int l = j; l < n1; l++)
            {
                t3[i] = t1[l];
                i++;
            }
        }
    }
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%.2f ", t3[i]);
    }
}