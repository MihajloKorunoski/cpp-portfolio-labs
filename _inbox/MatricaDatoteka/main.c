#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while ((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
} 

int main() {
    wtf(); 
    int A[200][200];
    int redici, koloni, shtosCount=0;
    FILE *f = fopen("matrica.txt", "r");
    fscanf(f, "%d %d", &redici, &koloni);
    for (int i = 0; i < redici; i++) {
        for (int j = 0; j < koloni; j++) {
            fscanf(f, "%d", &A[i][j]);
        }
    }

    for (int i = 0; i < redici; i++) {
        for (int j = 0; j < koloni; j++) {
            if (((i + j) % 2 == 0 && A[i][j] % 2 == 0)||((i + j) % 2 != 0 && A[i][j] % 2 != 0))
                shtosCount++;
        }
        printf("%d: %d\n",i,shtosCount);
        shtosCount=0;
    }
    return 0; 
}