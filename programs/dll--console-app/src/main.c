#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<string.h>

#define MEMCHECK(x) if(x==NULL) {printf("Nema memorija!\n"); exit(-1);}
#define NEW(t) (t*)malloc(sizeof(t))

typedef int info_t;
typedef struct element {
    info_t info;
    struct element *llink;
    struct element *rlink;
} node;

typedef node *nodep;

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

void ins_before(nodep l, nodep newnode) {
    l->llink->rlink = newnode;
    newnode->llink = l->llink;
    newnode->rlink = l;
    l->llink = newnode;
}

void ddelete(nodep v, nodep deleted) {
    if (v == deleted)
        return;
    deleted->llink->rlink = deleted->rlink;
    deleted->rlink->llink - deleted->llink;
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
    if (b == a)
        return;
    a->llink->rlink = b;
    b->llink = a->llink;
    a->rlink = b->rlink;
    b->rlink->llink = a;
    b->rlink = a;
    a->llink = b;
}

void swap(node *p, node *q) {
    node *t;
    void sosed_swap(node *);
    if (p->rlink == q)
        sosed_swap(p);
    else if (p->llink == q)
        sosed_swap(q);
    else {
        p->rlink->llink = p->llink->rlink = q;
        q->rlink->llink = q->llink->rlink = p;
        t = p->rlink;
        p->rlink = q->rlink;
        q->rlink = t;
        t = p->llink;
        p->llink = q->llink;
        q->llink = t;
    }
}

void swapStudent(nodep a, nodep b) {
    node *l;
    if (a->rlink == b)
        sosed_swap(a);
    else if (b->rlink == a)
        sosed_swap(b);
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
    printf("->%d", p->info);
}

int main() {
    int x;
    nodep list = new_list();
    nodep q, a;
    a = NEW(node);
    MEMCHECK(a);
    ddelete(list, list->rlink);
    sosed_swap(list->rlink);
    a->info = 1;
    dinsert(list, a);
    a = NEW(node);
    MEMCHECK(a);
    a->info = 2;
    dinsert(list, a);
    a = NEW(node);
    MEMCHECK(a);
    a = NEW(node);
    MEMCHECK(a);
    a->info = 3;
    dinsert(list, a);
    a = NEW(node);
    MEMCHECK(a);
    a->info = 4;
    dinsert(list, a);
    a = NEW(node);
    MEMCHECK(a);
    a->info = 5;
    ins_before(list, a);
    printlist(list);
    sosed_swap(list->rlink);
    printlist(list);
    q = find_first(list, 4);
    if (q)
        printf("Pronajden!%\n", q->info);
    else
        printf("Nemat takov element!\n");
    printlist(list);

    q = find_first(list, 2);
    if (q)
        printf("Pronajden!%\n", q->info);
    else
        printf("Nemat takov element!\n");
    ddelete(list, q);
    printlist(list);

    q = find_first(list, 5);
    if (q)
        printf("Pronajden!%\n", q->info);
    else
        printf("Nemat takov element!\n");
    printlist(list);

    a = find_first(list, 3);
    if (a)
        printf("Pronajden!%\n", a->info);
    else
        printf("Nemat takov element!\n");
    printlist(list);
    swapStudent(a, q);

    printlist(list);
    free_link_list(list);
    scanf("%d", &x);
    return 0;
}

