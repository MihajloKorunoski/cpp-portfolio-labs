#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

#define MEMCHECK(x) if(x==NULL) { printf("Nema memorija!\n"); exit(-1); }

typedef int info_t;

typedef struct bNodeType {
    info_t info;
    struct bNodeType *left;
    struct bNodeType *right;
} bNode;

typedef struct bTreeType {
    bNode *root;
} BSTree;

void initialize(BSTree *t) {
    t->root = NULL;
}

bNode *createNewNode(info_t x, bNode *left, bNode *right) {
    bNode *tmp = (bNode *) malloc(sizeof(bNode));
    tmp->info = x;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

bNode *insert(info_t x, bNode *t) {
    if (t == NULL) {
        t = createNewNode(x, NULL, NULL);
    } else if (x < t->info) {
        t->left = insert(x, t->left);
    } else if (x > t->info) {
        t->right = insert(x, t->right);
    } else; // Duplicate; do nothing
    return t;
}

void insertT(BSTree *t, info_t x) {
    t->root = insert(x, t->root);
}

info_t elementAt(bNode *t) {
    if (t == NULL)
        return (info_t) NULL;    // depends on the type of the elements
    return t->info;
}

bNode *findMin(bNode *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    }
    return findMin(t->left);
}

info_t findMinT(BSTree *tree) {
    return elementAt(findMin(tree->root));
}

bNode *findMax(bNode *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    }
    return findMax(t->right);
}

info_t findMaxT(BSTree *tree) {
    return elementAt(findMax(tree->root));
}

bNode *find(info_t x, bNode *t) {
    if (t == NULL)
        return NULL;

    if (x < t->info) {
        return find(x, t->left);
    } else if (x > t->info) {
        return find(x, t->right);
    } else {
        return t;   // Match
    }
}

bNode *findT(BSTree *tree, info_t x) {
    return find(x, tree->root);
}

bNode *delete(info_t x, bNode *t) {
    if (t == NULL)
        return t;       // Item not found; do nothing

    if (x < t->info) {
        t->left = delete(x, t->left);
    } else if (x > t->info) {
        t->right = delete(x, t->right);
    } else if (t->left != NULL && t->right != NULL) { // Two children
        t->info = findMin(t->right)->info;
        t->right = delete(t->info, t->right);
    } else {
        if (t->left != NULL)
            return t->left;
        else
            return t->right;
    }
    return t;
}

void deleteT(BSTree *tree, info_t x) {
    tree->root = delete(x, tree->root);
}

bNode *makeEmpty(bNode *t) {
    if (t == NULL)
        return NULL;
    t->left = makeEmpty(t->left);
    t->right = makeEmpty(t->right);
    free(t);
    return NULL;
}

void makeEmptyT(BSTree *tree) {
    tree->root = makeEmpty(tree->root);
}

int isEmptyT(BSTree *tree) {
    if (tree->root == NULL)
        return 1;
    else
        return 0;
}

void printTree(bNode *t) {
    if (t != NULL) {
        printTree(t->left);
        printf("%d\n", t->info);
        printTree(t->right);
    }
}

void printTreeT(BSTree *tree) {
    if (isEmptyT(tree)) {
        printf("Empty tree\n");
    } else {
        printTree(tree->root);
    }
}

/* Would like a semi-open interval [min, max) */
int random_in_range(unsigned int min, unsigned int max) {
    int base_random = rand(); /* in [0, RAND_MAX] */
    if (RAND_MAX == base_random)
        return random_in_range(min, max);
    /* now guaranteed to be in [0, RAND_MAX) */
    int range = max - min,
            remainder = RAND_MAX % range,
            bucket = RAND_MAX / range;
    /* There are range buckets, plus one smaller interval
    within remainder of RAND_MAX */
    if (base_random < RAND_MAX - remainder) {
        return min + base_random / bucket;
    } else {
        return random_in_range(min, max);
    }
}

int Visina(bNode *node) {
    if (node == NULL)
        return 0;
    else {
        int levavisina = Visina(node->left);
        int desnavisina = Visina(node->right);

        if (levavisina > desnavisina)
            return (levavisina + 1);
        else return (desnavisina + 1);
    }
}

int Dlabochina(bNode *root, int bdlabochina, int momentalen) {

    if (root != NULL && bdlabochina == momentalen)
        return 1;
    if (root == NULL)
        return 0;
    return Dlabochina(root->left, bdlabochina, momentalen + 1) + Dlabochina(root->right, bdlabochina, momentalen + 1);
}

int main() {
    int i;

    BSTree *tree = (BSTree *) malloc(sizeof(BSTree));
    initialize(tree);
    int n;
    scanf("%d", &n);
    int vlez;
    for (i = 0; i < n; i++) {
        scanf("%d", &vlez);
        insertT(tree, vlez);
    }
    bNode *root = tree->root;
    scanf("%d", &vlez);
    bNode *pom = find(vlez, root);
    int a = Visina(pom);
    printf("%d\n", a);
    int b = Dlabochina(root, a, 0);
    printf("%d", b);

    return 0;
}

