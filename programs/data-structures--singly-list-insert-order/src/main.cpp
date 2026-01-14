#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MEMCHECK(x) if(x==NULL){printf("Nema memorija!\n"); exit(-1);}

typedef int info_t;

typedef struct element{
    info_t info;
    struct element *link;
}node;

typedef node* nodep;

int main() {
    int a;
    node *p;
    node *mk_link_list(int);
    void printlist(node *);
    void free_link_list(node *);
    void insert_in_order(nodep *,info_t);

    int n;

    printf("Kolku jazli: ");
    scanf("%d", &n);
    p=mk_link_list(n);

    printlist(p);
    insert_in_order(&p,4);
    printlist(p);
    printf("\n\n");
    free_link_list(p);

    scanf("%d",&a);

}

node *mk_link_list(int n){
    node *p=NULL,*q=NULL;
    void fillel(node*);

    while(n--){
        p=(node*)malloc(sizeof(node));
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

void insertInside(nodep p, info_t x){
    nodep t=(node*)malloc(sizeof(node));
    t->info=x;
    t->link=p->link;
    p->link=t;
}
int lenght(nodep l){
    int n=0;
    while(l!=NULL){
        l=l->link;
        n++;
    }
    return n;
}
int lenghtR(nodep l){
    if(l==NULL){
        return 0;
    }
    else
        return (1+lenghtR(l->link));
}
nodep findFirst(nodep l, info_t x){
    while(l!=NULL&&l->info!=x){
        l=l->link;
    }
    return (l);
}
void deleteNodeAfter(nodep p){
    if(p->link==NULL)
        return;
    nodep t=p->link;
    p->link=t->link;
    free (t);
}
int deleteNode(nodep *l,nodep p){
    if (*l==p)
        *l=p->link;
    else{
        nodep q=*l;
        while(q->link != p && q!=NULL){
            q=q->link;
        }
        if(q==NULL)
            return 0;
        q->link=p->link;
    }
    free (p);
    return 1;
}
void insert_in_order(nodep *l, info_t x){
    nodep t=(node*)malloc(sizeof(node));
    t->info=x;
    node vodach;
    nodep p;

    (p=&vodach)->link=*l;

    while(p->link!=NULL && p->link->info<x){
        p=p->link;
    }
    t->link=p->link;
    p->link=t;
    *l=vodach.link;
}










