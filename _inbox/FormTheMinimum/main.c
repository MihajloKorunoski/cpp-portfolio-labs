#include<stdio.h>
#include <stdlib.h>


int minValue(const int *values, const size_t n) {
    int golemina = n;
    int *pom = malloc(n * sizeof(int));
    for (int i = 0; i < golemina; i++)
        pom[i] = values[i];

    for (int i = 0; i < golemina; i++) {
        for (int j = i + 1; j < golemina; j++) {
            if (pom[i] == pom[j]) {
                for (int k = j; k < golemina; k++)
                    pom[k] = pom[k + 1];
                golemina--;
                j--;
            }
        }
    }

    int temp;
    for (int i = 0; i < golemina - 1; i++)
        for (int j = 0; j < golemina - i - 1; j++) {
            if (pom[j] > pom[j + 1]) {
                temp = pom[j];
                pom[j] = pom[j + 1];
                pom[j + 1] = temp;
            }
        }

    int pom2 = 0;

    for (int i = 0; i < golemina; i++) {
        pom2 = pom2 * 10 + pom[i];
    }
    return pom2;
}

int main() {
    const int expected = 678;
    const int arr[] = {6, 7, 8, 7, 6, 6};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    const int actual = minValue(arr, len);
    printf("%d", actual);

}
