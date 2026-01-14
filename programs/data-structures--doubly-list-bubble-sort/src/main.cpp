#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MEMCHECK(x) if(x==NULL) { printf("Nema memorija!\n"); exit(-1); }
#define NEW(t) (t *)malloc(sizeof(t))

typedef int info_t;

typedef struct element {
    info_t info;
    struct element *llink;
    struct element *rlink;
} node;

typedef node *nodep;


void fillel(node *q) {
    scanf("%d", &q->info);
}

node *new_list(void) {
    nodep v = NEW(node);
    MEMCHECK(v);
    v->llink = v;
    v->rlink = v;
    return (v);
}

void dinsert(nodep node, nodep newnode) {
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}


void ins_before(nodep l, nodep newn) {
    l->llink->rlink = newn;
    newn->llink = l->llink;
    newn->rlink = l;
    l->llink = newn;
}

void ddelete(nodep v, nodep deleted) {
    if (v == deleted) return;
    deleted->llink->rlink = deleted->rlink;
    deleted->rlink->llink = deleted->llink;
    free(deleted);
}

nodep find_first(nodep l, info_t x) {
    nodep end;
    for (l = (end = l)->rlink; l != end && l->info != x; l = l->rlink);
    return (l != end ? l : NULL);
}

nodep find_last(nodep l, info_t x) {
    nodep end;
    for (l = (end = l)->llink; l != end && l->info != x; l = l->llink);
    return (l != end ? l : NULL);
}

void sosed_swap(nodep a) {
    nodep b = a->rlink;
    if (b == a) return;
    a->llink->rlink = b;
    b->llink = a->llink;
    a->rlink = b->rlink;
    b->rlink->llink = a;
    b->rlink = a;
    a->llink = b;
}

void swap(nodep a, nodep b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void swapStudent(nodep a, nodep b) {
    node *l;


    if (a->rlink == b) sosed_swap(a);
    else if (b->rlink == a) sosed_swap(b);


    else {

        (l) = a->llink;
        a->llink = b->llink;
        b->llink->rlink = a;
        b->llink = (l);
        (l)->rlink = b;
        (l) = a->rlink;
        a->rlink = b->rlink;
        b->rlink->llink = a;
        b->rlink = (l);
        (l)->llink = b;

    }
}

void free_link_list(nodep p) {
    nodep q, end = p;
    p = p->rlink;
    while (p != end) {
        p = (q = p)->rlink;
        free(q);
    }
    free(p);
}


void printlist(nodep p) {
    void printnode(nodep);
    nodep end = p;
    p = p->rlink;
    while (p != end) {

        printnode(p);
        p = p->rlink;
    }

    putchar('\n');
}

void printnode(nodep p) {
    printf("%d ", p->info);
}

void bubbleSort(nodep vodach) {
    int flag;
    nodep temp1 = NEW(node);
    MEMCHECK(temp1);
    nodep temp2 = NEW(node);
    MEMCHECK(temp2);
    temp2 = nullptr;
    if (vodach == nullptr)
        return;

    do {
        flag = 0;
        temp1 = vodach;
        while (temp1->rlink != nullptr) {
            if (temp1->info > temp1->rlink->info) {
                swap(temp1, temp1->rlink);
                flag = 1;
            }
            printlist(temp1);
            temp1 = temp1->rlink;
        }
        temp2 = temp1;
    } while (flag);
}

int main() {
    int i, n;
    nodep lista = new_list();
    nodep a;
    info_t info;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &info);
        a = NEW(node);
        MEMCHECK(a);
        a->info = info;
        ins_before(lista, a);
    }
    bubbleSort(lista);
    return 0;
}