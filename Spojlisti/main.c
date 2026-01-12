#include <stdio.h>
#include <malloc.h>

struct node {
    int value;
    struct node *next;
};

struct node *mk_link_list(int n) {
    struct node *p = NULL, *q = NULL;
    while (n--) {
        p = (struct node *) malloc(sizeof(struct node));
        p->next = q;
        q = p;
    }
    while (q != NULL) {
        scanf("%d", &q->value);
        q = q->next;
    }
    return p;
};

struct node *joinLists(struct node *p1, struct node *p2) {
    struct node *r1, *r2;
    r1 = r2 = NULL;
    int br;
    while (p1 != NULL && p2 != NULL) {
        br = 0;
        while (p1 != NULL && br != 2) {
            if (r1 == NULL) {
                r1 = r2 = p1;
            } else {
                r1 = r1->next = p1;
            }
            p1 = p1->next;
            br++;
        }
        br = 0;
        while (p2 != NULL && br != 2) {
            if (r1 == NULL) {
                r1 = r2 = p2;
            } else {
                r1 = r1->next = p2;
            }
            p2 = p2->next;
            br++;
        }
    }
    if (p1 != NULL) {
        if (r1 == NULL) {
            r2 = p1;
        } else {
            r1->next = p1;
        }
    } else {
        if (r1 == NULL) {
            r2 = p2;
        } else {
            r1->next = p2;
        }
    }

    return r2;

}

int main() {
    struct node *p1, *p2, *r;
    int m, n;

    scanf("%d", &m);
    p1 = mk_link_list(m);

    scanf("%d", &n);
    p2 = mk_link_list(n);

    r = joinLists(p1, p2);

    while (r->next != NULL) {
        printf("%d ", r->value);
        r = r->next;
    }
    printf("%d\n", r->value);

    return (0);
}