#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MEMCHECK(x) if(x==NULL){printf("Nema memorija!\n"); exit(-1);}
typedef int info_t;
typedef struct element{
    info_t info;
    struct element *link;
}node;

typedef node *nodep;

node *mk_link_list(int n){
    node *p=NULL, *q=NULL;
    void fillel(node *);

    while(n--){
        p=(node *)malloc(sizeof(node));
        MEMCHECK(p);
        p->link=q;
        q=p;
    }
    while(q!=NULL){
        fillel(q);
        q=q->link;
    }
    return (p);
}

void fillel(node *q){
    scanf("%d",&q->info);
}

void printlist(node *p){
    void printnode(node *);
    while(p!=NULL){
        printnode(p);
        p=p->link;
    }
    putchar('\n');
}

void printnode(node *p){
    printf("->%d",p->info);
}

void free_link_list(node *p){
    node *q;

    while(p!=NULL){
        p=(q=p)->link;
        free(q);
    }
}

void mirror(nodep *l){
    nodep m,p,q;
    m=NULL;
    p=*l;
    while(p!=NULL){
        q=p->link;
        p->link=m;
        m=p;
        p=q;
    }
    (*l)=m;
}

int main() {
    int a;
    nodep p;
    int n;

    printf("Kolku nodea: ");
    scanf("%d",&n);
    p=mk_link_list(n);


    printlist(p);

    mirror(&p);
    printlist(p);
    printf("\n\n");
    free_link_list(p);
    scanf("%d",&a);
    return 0;
}
















