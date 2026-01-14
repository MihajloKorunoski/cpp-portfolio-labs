#include<stdio.h>

void swapni(int *a, int *b) {
    int pom = *a;
    *a = *b;
    *b = pom;
}

void shakerSort(int a[], int n) {
    if (n==1){
        printf("%d \n%d ",a[n-1],a[n-1]);
    }
    for (int i = 0; i < n / 2; i++) {
        int flag=0;
        for (int j = n - 1; j > 0; j--)
            if (a[j] < a[j - 1]) {
                swapni(&a[j], &a[j - 1]);
                flag++;
            }
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                swapni(&a[j], &a[j + 1]);
                flag++;
            }
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        if(flag==0)
            break;
    }
}

int main() {
    int i, n;
    int a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    shakerSort(a, n);
    return 0;
}