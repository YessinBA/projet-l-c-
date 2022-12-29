#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct date_t{
  int jour;
  int mois;
  int annee;
} ;
struct voyage {
    long idvoyage;
    char destination[30];
    struct  date_t date_depart;
    struct date_t date_retour;
    int prix;
} ;
struct noeud {
    struct voyage  v ;
    struct noeud *    suiv ;
}     ;


void inserer(struct voyage v) {

    struct noeud* aux = (struct noeud*) malloc(sizeof(struct noeud));
    struct noeud* head = NULL;
    aux->v = v;
    aux->suiv = head;
    head = aux;
} ;
void ajouter_voyage(struct noeud *list_v){
    struct voyage v;
    printf("donner l id du voyage:\n");
    scanf("%ld",&v.idvoyage);
    printf("\ndonner la destination:\n");
    scanf("%s",&v.destination);
    printf("\ndonner la date de depart:\n annee:\n");
    scanf("%d",&v.date_depart.annee);
    printf("\n mois:\n");
    scanf("%d",&v.date_depart.mois);
    printf("\njour:\n");
    scanf("%d",&v.date_depart.jour);
    printf("\ndonner la date de retour:\n annee:\n");
    scanf("%d",&v.date_retour.annee);
    printf("\n mois:\n");
    scanf("%d",&v.date_retour.mois);
    printf("\n jour:\n");
    scanf("%d",&v.date_retour.jour);
    printf("donner le prix:\n");
    scanf("%d",&v.prix);
    inserer(v);
}


void afficher_voyage(struct noeud *list_v){
        struct noeud* head = NULL;
    struct noeud *aux = head;
    long c;
    printf("donner le id du voyage a afficher: \n");
    scanf("%ld",&c);
    while ((aux != NULL)&&(aux -> v.idvoyage != c)){
        aux = aux -> suiv;
    }
    if(aux==NULL){
        printf("ce voyage n'existe pas.\n");
    }
        else{
            printf("destination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d\n",aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
        }
}

void supprimer_voyage(struct noeud *list_v){
        struct noeud* head = NULL;
    struct noeud *aux = head;
    struct noeud *pred = NULL;
    long c;
    printf("donner le id du voyage a supprimer: \n");
    scanf("%ld",&c);
    if(aux->v.idvoyage==c){
        head=aux->suiv;
        free(aux);
    }
    else{

        while ((aux != NULL)&&(aux -> v.idvoyage != c)){
            pred = aux;
            aux = aux -> suiv;
        }
        if(aux==NULL){
            printf("ce voyage n'existe pas.\n");
        }
        else{
            pred->suiv=aux->suiv;;
            free(aux);
        }
    }
}


void modifier_voyage(struct noeud *list_v){
    char ch[30];
    int i=0,j,m,a,aa,mm,jj,p;
            struct noeud* head = NULL;
    struct noeud *aux = head;
    long c;
    printf("donner le donner l id du voyage a modifier: \n");
    scanf("%ld",&c);
    while ((aux != NULL)&&(aux -> v.idvoyage != c)){
        aux = aux -> suiv;
    }
    if(aux==NULL){
        printf("ce voyage n'existe pas.\n");
    }
    else{
        while(i!=5){
            printf("donner le numero de la modification à faire:\n");
            printf("1-Modifier destination\n2-Modifier la date de depart\n3-Modifier la date de retour\n4-Modifier le prix\n5-Exit.\n");
            scanf("%d",&i);
            switch(i){
                case 1:{
                    gets(ch);
                    printf("Donner la nouvelle destination:\n");
                    gets(ch);
                    strcpy(aux->v.destination,ch);
                    break;
                }
                case 2:{
                    printf("Donner la nouvelle date de depart:\n");
                    printf("Donner l'annee:\n");
                    scanf("%d",&a);
                    printf("Donner le mois:\n");
                    scanf("%d",&m);
                    printf("Donner le jour:\n");
                    scanf("%d",&j);
                    aux->v.date_depart.annee=a;
                    aux->v.date_depart.mois=m;
                    aux->v.date_depart.jour=j;
                    break;
                }
                case 3:{
                    printf("Donner la date e retour:\n");
                    printf("Donner l'annee:\n");
                    scanf("%d",&aa);
                    printf("Donner le mois:\n");
                    scanf("%d",&mm);
                    printf("Donner le jour:\n");
                    scanf("%d",&jj);
                    aux->v.date_retour.annee=aa;
                    aux->v.date_retour.mois=mm;
                    aux->v.date_retour.jour=jj;
                    break;
                }
                case 4:{
                    printf("Donner le nouveau prix:\n");
                    scanf("%d",&p);
                    aux->v.prix=p;
                    break;
                }
                case 5: break;
                default: printf("numero errone\n");
            }
        }
    }
    }
    void rechercher_voyage(struct noeud *list_v){
    int a1,m1,j1,a2,m2,j2,a,m,j;
    int b=0;
    struct noeud* head = NULL;
    struct noeud *aux = head;
    printf("Donner la 1ere date:\n");
    printf("annee: ");
    scanf("%d",&a1);
    printf("mois: ");
    scanf("%d",&m1);
    printf("jour: ");
    scanf("%d",&j1);
    printf("Donner la 2eme date:\n");
    printf("annee: ");
    scanf("%d",&a2);
    printf("mois: ");
    scanf("%d",&m2);
    printf("jour: ");
    scanf("%d",&j2);
    while(aux!=NULL){
        a=aux->v.date_depart.annee;
        m=aux->v.date_depart.mois;
        j=aux->v.date_depart.jour;
        if(a>a1 && a<a2){
            printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
            b=1;
        }
        else{
            if(a==a1 && a<a2){
                if(m>m1){
                    printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                    b=1;
                }
                else{
                    if(m=m1 && j>=j1){
                        printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                        b=1;
                    }
                }

            }
            else{
                if(a==a1 && a==a2){
                    if(m>m1 && m<m2){
                        printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                        b=1;
                    }
                    else{
                        if((m==m1 && j>=j1)||(m==m2 && j<=j2)){
                            printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                        b=1;
                        }

                    }
                }
                else{
                    if(a>a1 && a==a2){
                        if(m<m2){
                            printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                        b=1;
                        }
                        else{
                            if(m==m2 && j<=j2){
                                printf("id du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->v.idvoyage,aux->v.destination,aux->v.date_depart.jour,aux->v.date_depart.mois,aux->v.date_depart.annee,aux->v.date_retour.jour,aux->v.date_retour.mois,aux->v.date_retour.annee,aux->v.prix);
                                b=1;
                            }
                        }
                    }
                }
            }
        }
        aux=aux->suiv;
    }
    if(b==0){
        printf("Il n'existe aucun voyage.");
    }
 }


int main(){
    int i,z=1;
    int b=1;
    struct noeud* head = NULL;
    struct noeud *list_v = (struct noeud*) malloc(sizeof(struct noeud));
    list_v=head;
    while(z==1){

        while (b){
            printf("Donner le numero de la tache a faire: \n");
            printf(" 1:Ajouter un voyage. \n 2:Afficher la description d'un voyage. \n 3:Supprimer un voyage. \n 4:Modifier un voyage. \n 5:Rechercher les voyages disponibles selon les dates donnees.\n ");
            scanf("%d",&i);
            if(i<=5&&i>=1){
                b=0;
            }
        }
        switch (i){
            case 1: ajouter_voyage(list_v);
            break;
            case 2: afficher_voyage(list_v);
            break;
            case 3: supprimer_voyage(list_v);
            break;
            case 4: modifier_voyage(list_v);
            break;
            case 5: rechercher_voyage(list_v);
            break;
        }
        b=1;
        printf("Pour retourner vers le menu tappez: 1\nPour quitter tappez un autre nombre: \n");
        scanf("%d",&z);
    }

}
