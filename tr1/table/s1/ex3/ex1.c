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
    double t[n];
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Enter la moyenne de etudient %d : ", i + 1);
            scanf("%lf", &t[i]);
        } while (t[i] < 0 || t[i] > 20);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%lf|", t[i]);
    }
}