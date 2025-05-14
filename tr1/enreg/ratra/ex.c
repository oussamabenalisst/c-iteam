#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    int j, m, a;
} date;
typedef struct voiture
{
    int mat;
    date df;
    int cin;
} voiture;
typedef struct prop
{
    int cin;
    int nbr;
    int tab[5];
} prop;
voiture saisie_voiture(voiture v)
{
    printf("donne matricule : ");
    scanf("%d", &v.mat);
    printf("donne le j :");
    scanf("%d", &v.df.j);
    printf("donne le m :");
    scanf("%d", &v.df.m);
    printf("donne l'a :");
    scanf("%d", &v.df.a);
    return v;
}
void saisie_tablevoiture(voiture t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("donne les informations de la voitur %d  \n", i);
        t[i] = saisie_voiture(t[i]);
    }
}

void affich_voitures(voiture t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nVoiture %d :\n", i + 1);
        affich_voiture(t[i]);
    }
}
void affich_voiture(voiture v)
{
    printf("\nMatricule : %d\nDate de fin de concession : %d/%d/%d\nCIN : %d\n", v.mat, v.df.j, v.df.m, v.df.a, v.cin);
}

prop saisie_cliente(prop v)
{
    printf("donne cin : ");
    scanf("%d", &v.cin);
    printf("donne le nombre de voitures : ");
    scanf("%d", &v.nbr);
    printf("donne les matricules des voitures : ");
    for (int i = 0; i < v.nbr; i++)
    {
        printf("\nmatricule %d : ", i + 1);
        scanf("%d", &v.tab[i]);
    }
    return v;
}
void saisie_clientes(prop t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("donne les informations du client %d  \n", i);
        t[i] = saisie_cliente(t[i]);
    }
}
void affich_props(prop v)
{
    printf("\nCIN : %d\nNombre de voitures : %d\n", v.cin, v.nbr);
    for (int i = 0; i < v.nbr; i++)
    {
        printf("Matricule %d : %d\n", i + 1, v.tab[i]);
    }
    printf("\n");
}
void affich_prop(prop tc[], int nc)
{
    for (int i = 0; i < nc; i++)
    {
        printf("\nClient %d :\n", i + 1);
        affich_props(tc[i]);
    }
}
main()
{
    int n;
    do
    {
        printf("donne n : ");
        scanf("%d", &n);
    } while (n < 0);
    voiture t[n];
    saisie_tablevoiture(t, n);
    affich_voitures(t, n);
    //**************clientes************** */
    //**************clientes************** */
    //**************clientes************** */
    int nc;
    do
    {
        printf("donne n : ");
        scanf("%d", &nc);
    } while (nc < 0);
    prop tc[n];
    saisie_clientes(tc, nc);
    affich_prop(tc, nc);
}
