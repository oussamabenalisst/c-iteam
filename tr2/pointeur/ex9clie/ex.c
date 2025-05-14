#include <stdio.h>
#include <stdlib.h>
typedef struct patient
{
    char nom[20];
    char prenom[20];
    int rdv;
} patient;
typedef struct noeud
{
    patient var;
    struct noeud *susivant;
} noeud;
typedef struct noeud *liste_patient;
liste_patient AjoutePatient(liste_patient tete, patient e)
{
    liste_patient temp = (liste_patient)malloc(sizeof(struct noeud));
    temp->var = e;
    temp->susivant = NULL;
    if (tete == NULL)
    {
        tete = temp;
    }
    else
    {
        liste_patient p = tete;
        while (p->susivant != NULL)
        {
            p = p->susivant;
        }
        p->susivant = temp;
    }
    return tete;
}
void rendivous(liste_patient tete, int *yes, int *no)
{
    if (tete != NULL)
    {
        if (tete->var.rdv == 1)
        {
            *yes++;
        }
        else
        {
            *no++;
        }
        rendivous(tete->susivant, yes, no);
    }
}
liste_patient SurprimeTete(liste_patient tete)
{
    liste_patient temp = tete;
    tete = tete->susivant;
    free(temp);
    return tete;
}
liste_patient SurprimePatient(liste_patient tete)
{
    int rd = 0, srd = 0;
    if (tete != NULL)
    {
        rendivous(tete, &rd, &srd);
        if (rd == 0)
        {
            tete = SurprimeTete(tete);
        }
        else
        {
            liste_patient ptemp = tete, temp = tete;
            while (ptemp->var.rdv != 1)
            {
                temp = ptemp;
                ptemp = ptemp->susivant;
            }
            temp->susivant = ptemp->susivant;
            free(ptemp);
            return temp;
        }
    }
    return tete;
}
void Affiche(liste_patient tete, int rdv)
{
    liste_patient temp = tete;
    while ((temp != NULL))
    {
        if (temp->var.rdv == rdv)
        {
            printf("Nom: %s\n", temp->var.nom);
            printf("Prenom: %s\n", temp->var.prenom);
            printf("Rendez-vous: %d\n", temp->var.rdv);
        }
        temp = temp->susivant;
    }
}
void AffichePatient(liste_patient tete)
{
    printf("---------Rendez-vous 1 -----------\n");
    Affiche(tete, 1);
    printf("---------Rendez-vous 0 -----------\n");
    Affiche(tete, 0);
}
int main()
{
    liste_patient tete = NULL;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        patient p;
        printf("Nom: ");
        scanf("%s", p.nom);
        printf("Prenom: ");
        scanf("%s", p.prenom);
        do
        {
            printf("Rendez-vous: ");
            scanf("%d", &p.rdv);
        } while (p.rdv != 0 && p.rdv != 1);
        tete = AjoutePatient(tete, p);
    }
    AffichePatient(tete);
    printf("-------partie 2--------\n");
    int rd = 0, srd = 0;
    rendivous(tete, &rd, &srd);
    printf("Rendez-vous: %d | Sans rendez-vous: %d\n", rd, srd);
    for (int i = 0; i < n; i++)
    {
        tete = SurprimePatient(tete);
    }
    printf("Supprimer les patients sans rendez-vous\n");
    AffichePatient(tete);
}
