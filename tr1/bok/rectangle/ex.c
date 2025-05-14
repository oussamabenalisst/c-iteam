#include <stdio.h>
#include <stdlib.h>

main()
{
    int n, j;
    do
    {
        printf("Enter the value of n: ");
        scanf("%d", &n);
    } while (n <= 0);
    do
    {
        printf("Enter the value of j: ");
        scanf("%d", &j);
    } while (j <= 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < j; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
