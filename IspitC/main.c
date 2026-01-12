/*Во дадена еднострана поврзана листа избришете ги сите јазли чии вредности се јавуваат парен број пати.
 * Смеете да користите само ЕДНА листа.

Влез:

9

1->10->2->3->5->2->10->3->3

Излез:  1->3->5->3->3
*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define    MEMCHECK(x) if(x==NULL) { printf("Nema memorija!\n"); exit(-1); }

typedef int info_t;

typedef struct element {
    info_t info;
    struct element *link;
} node;                        // Definiranje na element vo linarna lista

typedef node *nodep;          // Definiranje na pokazuvac kon lista

int zbir(node *lista) {
    int zb = 0;
    while (lista != NULL) {
        zb += lista->info;
        lista = lista->link;
    }
    return zb;
}

/*int main ()
{
    int n;
    node *mk_link_list(int);
    scanf("%d",&n);
    struct node *p=mk_link_list(n);
    printf("%d",zbir(p));

    return 0;
}*/

/**************************************************************
 * node *mk_link_list(int n)     Vnesuvanje na linearna lista *
 *                                                            *
 * 	Se kreira linearna povrzana lista so n elementi so      *
 * dinamicka alokacija na memorija za sekoj jazel. Potoa od   *
 * tastatura se citaat vrednosti koi se smestuvaat vo info    *
 * polinjata na jazlite.                                      *
 *                                                            *
 * 	Vlezni parametri:                                       *
 *	int n	- broj na elementi vo listata sto treba da se kreira *
 * 	Izlezni parametri:                                      *
 * node * - funkcijata vraka pokazuvac kon pocetokot na       *
 *          kreiranata lista                                  *
 **************************************************************/
node *mk_link_list(int n) {
    node *p = NULL, *q = NULL;
    void fillel(node *);

    while (n--) {
        p = (node *) malloc(sizeof(node));
        MEMCHECK(p);
        p->link = q;
        q = p;
    }
    while (q != NULL) {
        fillel(q);
        q = q->link;
    }
    return (p);
}

void fillel(node *q) {
    char a,b;
    scanf("%d", &q->info);
    scanf("%c%c",&a,&b);
}

/**************************************************************
 * void printlist (node *p)       Pecatenje na linearna lista *
 *                                                            *
 * 	Se pecati linearna povrzana lista na ekran.             *
 *                                                            *
 * 	Vlezni parametri:                                       *
 *	node *p	-	pokazuvac kon pocetokot na listata             *
 * 	Izlezni parametri:    nema                              *
 **************************************************************/
void printlist(node *p) {
    void printnode(node *);
    printf("%d", p->info);
    p=p->link;
    while (p != NULL) {
        printnode(p);
        p = p->link;
    }
    putchar('\n');
}

void printnode(node *p) {
    printf("->%d", p->info);
}

/**************************************************************
 * void free_link_list(node *p)          Brise linearna lista *
 *                                                            *
 *      Ja brise linearnata lista od memorija. Se osloboduva    *
 * memorijata zafatena od listata kon cij pocetok pokazuva p. *
 *                                                            *
 *      Vlezni parametri:                                       *
 *      node *p -       pokazuvac kon pocetokot na listata             *
*      Izlezni parametri: nema                                 *
 **************************************************************/
void free_link_list(node *p) {
    node *q;

    while (p != NULL) {
        p = (q = p)->link;
        free(q);
    }
}

void insertInside(nodep p, info_t x)
//dodavanje na element na vednas zad jazelot na koj pokazuva p
{
    nodep t = (node *) malloc(sizeof(node));
    t->info = x;
    t->link = p->link;
    p->link = t;
}

int length(nodep l) { //kolku jazli ima dadena lista
    int n = 0;
    while (l != NULL) {
        l = l->link;
        n++;
    }
    return n;
}

int lengthR(nodep l) { //Rekurzivna - kolku jazli ima dadena lista
    if (l == NULL) return 0;
    else return (1 + lengthR(l->link));
}

nodep findFirst(nodep l,
                info_t x) { //Baranje na element od lista. Vraka pokazuvac kon jazelot vo koj e najdena vrednosta ili NULL ako ne e pronajdena
    while (l != NULL && l->info != x)
        l = l->link;
    return (l);
}

void deleteNodeAfter(nodep p)
//Brisenje na elementot koj se naoga vednas po onoj kon koj pokazuva  vo listata
{
    if (p->link == NULL) return;  //ako listata e veke prazna
    nodep t = p->link;
    p->link = t->link;
    free(t);
}

int deleteNode(nodep *l, nodep p) {
//od listata l se brise elementot na koj pokazuva p. Vraka 1 ako uspesno go izbrisal, 0 ako p ne e od listata l.
    if (*l == p)
        *l = p->link;
    else {  //iterira do krajot na listata se dodeka ne zastane na prethodnikot na p
        nodep q = *l;
        while (q->link != p && q != NULL) //za sekoj slucaj
            q = q->link;
        if (q == NULL) return 0;
        q->link = p->link;
    }
    free(p);
    return 1;
}

void insertInOrder(nodep *l, info_t x) {
    nodep t = (node *) malloc(sizeof(node));
    t->info = x;
    node vodac; //privremen vodac
    nodep p;

    (p = &vodac)->link = *l;

    while (p->link != NULL && p->link->info < x)
        p = p->link;
    t->link = p->link;
    p->link = t;
    *l = vodac.link; // azuriraj go pokazuvacot l na eventualniot nov pocetok na listata
}


int main() {
    int N = 0;
    scanf("%d", &N);

    node *mk_link_list(int);
    nodep t = (node *) malloc(sizeof(node));
    t = mk_link_list(N);
    int brojach;
    int i = 0;
    brojach=findFirst(t);
    printf("%d",brojach);
    for (i = 0; i < N; i++) {

    }
    //code here
    return 0;
}
