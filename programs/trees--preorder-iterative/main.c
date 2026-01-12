#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#define MEMCHECK(x) if(x==NULL) { printf("Nema memorija!\n"); exit(-1); }
#define LEFT 1
#define RIGHT 2

typedef char *info_t;

typedef struct bNodeType {
    info_t info;
    struct bNodeType *left;
    struct bNodeType *right;
} bNode;

typedef struct bTreeType {
    bNode *root;
} bTree;

void initialize(bTree *t) {
    t->root = NULL;
}

void makeRoot(info_t elem, bTree *t) {
    t->root = (bNode *) malloc(sizeof(bNode));
    t->root->info = elem;
    t->root->left = NULL;
    t->root->right = NULL;
}

bNode *addChild(bNode *n, int where, info_t elem) {
    bNode *tmp = (bNode *) malloc(sizeof(bNode));
    tmp->info = elem;
    tmp->left = NULL;
    tmp->right = NULL;

    if (where == LEFT) {
        if (n->left != NULL)    // veke postoi element
            return NULL;
        n->left = tmp;
    } else {
        if (n->right != NULL)   // veke postoi element
            return NULL;
        n->right = tmp;
    }

    return tmp;
}

bNode *addChildNode(bNode *n, int where, bNode *tmp) {
    //tmp->left = NULL;
    //tmp->right = NULL;

    if (where == LEFT) {
        if (n->left != NULL)    // veke postoi element
            return NULL;
        n->left = tmp;
    } else {
        if (n->right != NULL)   // veke postoi element
            return NULL;
        n->right = tmp;
    }

    return tmp;
}

///////////////////////////////////////////////////////////////////
typedef bNode *stackElementT;

typedef struct stackTag {
    stackElementT element;
    struct stackTag *next;
} stackNodeT;

typedef struct {
    stackNodeT *top;
} stackT;

void stackInit(stackT *stackPtr) {
    (*stackPtr).top = NULL;
}

void stackDestroy(stackT *stackPtr) {
    stackNodeT *t;

    while (stackPtr->top != NULL) {
        t = stackPtr->top;
        stackPtr->top = t->next;
        free(t);
    }
}

void stackPush(stackT *stackPtr, stackElementT element1) {
    stackNodeT *t;
    t = (stackNodeT *) malloc(sizeof(stackNodeT));
    MEMCHECK(t);
    t->element = element1;
    t->next = stackPtr->top;
    stackPtr->top = t;
}

bNode stackPop(stackT *stackPtr) {
    stackNodeT *t;
    t = stackPtr->top;
    stackPtr->top = stackPtr->top->next;
    free(t);
}

stackElementT stackTop(stackT *stackPtr) {
    return stackPtr->top->element;
}

int stackEmpty(stackT *stack) {
    return (stack->top == NULL);
}
///////////////////////////////////////////////////////////////////

void preorderNonRecursive(bTree *t) {
    stackT temp;
    stackInit(&temp);
    bNode *pom = t->root;
    int flag=1;
    while(flag){
        while(pom!=NULL){
            printf("%s ", pom->info);
            stackPush(&temp,pom);
            pom=pom->left;
        }
        if(stackEmpty(&temp)){
                break;
            }
        pom=stackTop(&temp);
        stackPop(&temp);
        pom=pom->right;
    }

}

int main() {
    int i, j, k = -1;

    char words[1000][100];
    int N;
    int index;
    int parent;
    bNode **n = (bNode **) calloc(1000, sizeof(bNode *));
    char pc;
    scanf("%d", &N);

    for (i = 0; i < 1000; i++) {
        n[i] = (bNode *) malloc(sizeof(bNode));
        n[i]->left = NULL;
        n[i]->right = NULL;
    }

    bTree *t = (bTree *) malloc(sizeof(bTree));
    initialize(t);

    for (i = 0; i < N; i++) {

        k++;
        scanf("%s", words[k]);
        index = atoi(words[k]);


        k++;
        scanf("%s", words[k]);
        n[index]->info = words[k];

        k++;
        scanf("%s", words[k]);

        if (strcmp(words[k], "LEFT") == 0) {

            k++;
            scanf("%s", words[k]);
            parent = atoi(words[k]);
            addChildNode(n[parent], LEFT, n[index]);

        } else if (strcmp(words[k], "RIGHT") == 0) {
            k++;
            scanf("%s", words[k]);
            parent = atoi(words[k]);
            addChildNode(n[parent], RIGHT, n[index]);

        } else {
            t->root = n[index];
        }

    }

    preorderNonRecursive(t);

    return 0;
}