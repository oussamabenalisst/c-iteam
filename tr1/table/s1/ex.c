#include <stdio.h>
#include <stdlib.h>
main()
{
    int tab[5];
    scanf("%d %d %d %d %d", &tab[0], &tab[1], &tab[2], &tab[3], &tab[4]);
    printf("%d | %d | %d | %d | %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
    printf("t[0]=%d\n", tab[0]);
    printf("t[1]=%d\n", tab[1]);
    printf("t[2]=%d\n", tab[2]);
    printf("t[3]=%d\n", tab[3]);
    printf("t[4]=%d\n", tab[4]);
}