#include <stdio.h>
#include <intrin.h>

int main() {
    int M, N;
    int temp = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int a[100];
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < N; j++) {
            if (a[0] > 0) {
                temp = a[j + a[0]];
                a[j + a[0]] = a[j];
                a[j] = temp;
            }
            printf("%d ", a[j]);
        }
        temp = 0;
    }
}
