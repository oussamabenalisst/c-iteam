#include <stdio.h>
#include <stdlib.h>

int poss(int n, int x)
{
    int p = 1;
    for (int i = 0; i < x; i++)
    {
        p = p * n;
    }
    return p;
}
int rposs(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return n * rposs(n, x - 1);
    }
}
main()
{
    int n, x;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n < 0);
    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &x);
    } while (x < 0);
    printf("%d ** %d= %d\n", n, x, poss(n, x));
    printf("r %d ** %d= %d\n", n, x, rposs(n, x));
}
