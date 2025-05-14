#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
main()
{
    int n;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n < 0);
    printf("Factorial of %d is: %d", n, fact(n));
}
