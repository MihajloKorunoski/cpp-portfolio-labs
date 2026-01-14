#include<stdio.h>

void oddEvenSort(int a[], int n) {
    // Vasiot kod tuka
    int pom = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; i < n - i-1; j++) {
            if (a[j] % 2 == 0) {
                pom = a[j];
                a[j] = a[j + 1];
                a[j + 1] = pom;
            }
            if (a[j] % 2 == 1 && a[j + 1] % 2 == 1) {
                if (a[j] > a[j + 1]) {
                    pom = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = pom;
                }
            } else if (a[j] % 2 == 0 && a[j + 1] % 2 == 0) {
                if (a[j] < a[j + 1]) {
                    pom = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = pom;
                }
            }
        }
    for (i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d", a[i]);
}


int main() {
    int i, n;
    int a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    oddEvenSort(a, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d", a[i]);

    return 0;
}