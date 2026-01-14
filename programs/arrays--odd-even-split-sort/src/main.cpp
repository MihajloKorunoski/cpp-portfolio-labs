#include<stdio.h>

void sortiranje(int *, int, char);

void oddEvenSort(int a[], int n) {
    // Vasiot kod tuka
    int neparna[100];
    int parna[100];
    int neparnibroevi = 0;
    int parnibroevi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0){
            parna[parnibroevi] = a[i];
            parnibroevi++;
        }
        else{
            neparna[neparnibroevi] = a[i];
            neparnibroevi++;
        }
    }
    sortiranje(parna, parnibroevi, '<');
    sortiranje(neparna, neparnibroevi, '>');
    for (int i = 0; i < neparnibroevi; ++i)
        a[i] = neparna[i];
    for (int i = 0; i < parnibroevi; ++i)
        a[neparnibroevi + i] = parna[i];

}

void sortiranje(int a[], int n, char znak) {

    for (int i = 0; i < n - 1; ++i) {
        bool flag = 1;
        for (int j = i + 1; j < n; ++j) {

            if (znak == '>') {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    flag = 0;
                }
            } else if (znak== '<') {
                if (a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    flag = 0;
                }
            }
        }
        if (flag)
            break;
    }
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
