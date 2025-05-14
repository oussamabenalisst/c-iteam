#include <stdio.h>
#include <stdlib.h>
main()
{
    int x, i, s;
    printf("donne x : ");
    scanf("%d", &x);
    while (x < 0)
    {
        printf("donne x : ");
        scanf("%d", &x);
    }
    if (x == 0)
    {
        s = 1;
    }
    else
    {
        s = 1;
        for (i = 1; i <= x; i++)
        {
            s = s * i;
        }
    }

    printf("le factu %d", s);
}