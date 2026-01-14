#include<stdio.h>
#include<malloc.h>

typedef struct element {
    int info;
    struct element *llink, *rlink;
} node;

node *novaDvojna() {
    node *v = (node *) malloc(sizeof(node));
    v->llink = v;
    v->rlink = v;
    return v;
}

void dodadi(node **pok_v, int broj) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->info = broj;
    temp->llink = (*pok_v)->llink;
    temp->rlink = *pok_v;
    (*pok_v)->llink->rlink = temp;
    (*pok_v)->llink = temp;
}

int isItPalindrome(node *left) {
    if (left == NULL) {
        return 1;
    }
    node *right;
    right = (node *) malloc(sizeof(node));
    right->llink=left->llink;
    while (right->rlink != NULL)
        right = right->rlink;
    while (left != right) {
        if (left->info != right->info)
            return -1;
        left = left->rlink;
        right = right->llink;
    }
    return 1;
}

int main() {
    node *lista = NULL, *l1 = NULL, *l2 = NULL;
    int i, n, info;

    lista = novaDvojna();

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &info);
        dodadi(&lista, info);
    }

    int rez = isItPalindrome(lista);
    printf("%d", rez);

    return 0;
}

