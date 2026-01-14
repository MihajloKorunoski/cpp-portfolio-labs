#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define MEMCHECK(x) if(x==NULL){printf("Nema memorija!\n"); exit(-1);}
#define NEW(t) (t*)malloc(sizeof(t))

typedef int info_t;

typedef struct element{
    info_t info;
    struct element *llink;
    struct element *rlink;
}node;

typedef node *nodep;

int main() {

}
