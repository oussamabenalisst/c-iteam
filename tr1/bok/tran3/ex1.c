#include <stdio.h>
#include <stdlib.h>

main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Enter the value of n: ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
