#include <stdio.h>
#include <stdlib.h>

void saisi(int *x)
{
    do
    {
        printf("Enter the value of int : ");
        scanf("%d", x);
    } while (*x < 0);
}

void swapping(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
int main()
{
    int a, b;
    saisi(&a);
    saisi(&b);
    printf("Before swapping, a = %d and b = %d\n", a, b);
    swapping(&a, &b);
    printf("After swapping, a = %d and b = %d\n", a, b);
}
