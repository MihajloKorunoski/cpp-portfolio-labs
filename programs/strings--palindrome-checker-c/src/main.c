#include<stdio.h>

#define MAX_ELEMENTI 1


typedef struct {
    int info;
} tipElement;
typedef struct {
    tipElement red[MAX_ELEMENTI];
    int poc;
    int kraj;
} tipRed;
typedef struct Gragjanin {
    char ime[100];
    char prezime[100];
    int lkarta;
    int pasos;
    int vozachka;
};

tipRed red1;
tipElement nov, nov1;

void inicijalizacija(tipRed *red) {
    (*red).poc = 0;   //prazen red e definiran so pocetok = kraj =0
    (*red).kraj = 0;
}

int prazen(tipRed red) {
    return (red.poc == red.kraj); //vraka vistina ako redot e prazen
}

int poln(tipRed red) {
    return (red.kraj == MAX_ELEMENTI); //vraka vistina ako redot e poln
}

void dodadi(tipRed *red, tipElement element) {
    if (poln(*red)) printf("Redot e poln\n");  //redot e poln sinaliziraj greska
    else {
        (*red).red[(*red).kraj].info = element.info;  // smestuvanje na element
        (*red).kraj++;                                // kraj pokazuva na sledna slobodna pozicija
    }
}

void brisi(tipRed *red, tipElement *element) {
    if (prazen(*red)) printf("Redot e prazen\n");    //ako redot e prazen signaliziraj greska
    else {
        (*element).info = (*red).red[(*red).poc].info;  //smesti element
        int i;
        for (i = (*red).poc; i < (*red).kraj; i++)           //pomestuvajne na elementite vo nizata
            (*red).red[i] = (*red).red[i + 1];
        (*red).poc = 0;                                 //resetiraj gi indeksite
        (*red).kraj--;
    }
}

void print() {

}

int main() {
    int a;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", pom.info.ime);
        scanf("%s", pom.info.prezime);
        scanf("%d", &pom.info.lkarta);
        scanf("%d", &pom.info.pasos);
        scanf("%d", &pom.info.vozachka);
    }


    return 0;
}