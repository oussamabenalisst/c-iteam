#include <stdio.h>
#include <stdlib.h>
typedef struct etudient
{
    char nom[20];
    char pre[20];
    int cin;
    double moyenne;
} etudient;

main()
{
    etudient e;
    printf("donne le nom de etudient : ");
    scanf("%s", e.nom);
    printf("donne le prenom de etudient : ");
    scanf("%s", e.pre);
    printf("donne le cin de etudient : ");
    scanf("%d", &e.cin);
    printf("donne la moyenne de etudient : ");
    scanf("%lf", &e.moyenne);
    printf("\n______________________________________\n");
    printf("etudiant : %s %s\ncin : %d\nmoyenne : %.2lf\n", e.nom, e.pre, e.cin, e.moyenne);
}
