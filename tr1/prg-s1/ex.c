#include <stdio.h>
#include <stdlib.h>
typedef struct Article
{
    int refart;
    double pu;
    int qt;
} Article;

Article saisie_article(Article a)
{
    printf("Donner la reference de l'article : ");
    scanf("%d", &a.refart);
    do
    {
        printf("Donner le prix unitaire : ");
        scanf("%lf", &a.pu);
    } while (a.pu <= 0);

    do
    {
        printf("Donner la quantite : ");
        scanf("%d", &a.qt);
    } while (a.qt < 0);

    return a;
}
void saisie_articles(Article t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("---------------Donner les informations de l'article %d : \n", i + 1);
        t[i] = saisie_article(t[i]);
    }
}
double valeur_stock_article(int q, double p)
{
    return p * q;
}
void valeur_stock_articles(Article t[], int n, double v[])
{
    for (int i = 0; i < n; i++)
    {
        v[i] = valeur_stock_article(t[i].qt, t[i].pu);
    }
}
double Revenu(int n, double v[])
{
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }
    return total;
}
void afficher_articles(Article t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d | %.2lf PU | %d QT \n", t[i].refart, t[i].pu, t[i].qt);
    }
}
void Analyse_Rentabilite(Article t[], double v[], int n)
{
    /*********Bulle*******/
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                //>>> pr table des articles
                Article temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
                //>>> pr table de valeur_stock
                double aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

main()
{
    /*****Saisir le nombre des articles à partir du clavier****/
    int n;
    do
    {
        printf("Donner le nombre d'articles : ");
        scanf("%d", &n);
    } while (n < 0);
    /****************Declarer un tableau d’articles**********/
    Article tab_articles[n];

    /*Remplir le tableau à partir du clavier */
    saisie_articles(tab_articles, n);

    /*Calculer et afficher la valeur du revenu de l’entreprise*/
    double tab_valeur_stock[n];
    valeur_stock_articles(tab_articles, n, tab_valeur_stock);
    printf("***le revenu de l'entreprise est %lf\n", Revenu(n, tab_valeur_stock));
    /*Afficher les articles après une analyse de rentabilite faite par l’entreprise*/
    Analyse_Rentabilite(tab_articles, tab_valeur_stock, n);
    printf("-------------afficher_articles-------------------\n");
    afficher_articles(tab_articles, n);
}
