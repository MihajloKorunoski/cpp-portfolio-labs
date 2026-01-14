#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

int najdolgaOpagackaSekvenca(int n, int a[]) {
    int *pom = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        pom[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j] && pom[i] < pom[j] + 1)
                pom[i] = pom[j] + 1;

        }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < pom[i])
            max = pom[i];
    }
    free(pom);
    return max;
}

int main() {

    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", najdolgaOpagackaSekvenca(n, a));
}