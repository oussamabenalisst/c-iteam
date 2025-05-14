#include <stdio.h>
#include <stdlib.h>

main()
{
    int t[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the number t[%d]: ", i + 1);
        scanf("%d", &t[i]);
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d | ", t[j]);
    }
}