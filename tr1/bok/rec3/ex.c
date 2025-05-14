#include <stdio.h>
#include <stdlib.h>

main()
{
    int n;
    do
    {
        printf("Enter the value of n: ");
        scanf("%d", &n);
    } while (n <= 0 || n % 2 == 0);
    int n_espaces = 0;
    while (n >= 1)
    {
        for (int j = 0; j < n_espaces / 2; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < n; k++)
        {
            printf("*");
        }
        //!!!!!!!!!!!!!facultatif!!!!!!!!!!!!!!//
        /*for (int l = 0; l < n_espaces / 2; l++)
        {
            printf(" ");
        }*/
        //!!!!!!!!!!!!facultatif!!!!!!!!!!!!!!//

        n_espaces += 2;
        n -= 2;
        printf("\n");
    }
}
