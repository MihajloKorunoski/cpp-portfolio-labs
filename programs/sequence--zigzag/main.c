#include<stdio.h>

#define MAX 1000

int najdiNajdolgaCikCak(int a[], int N) {
    int brojach = 1;
    int maks, pom;
    maks = pom = 0;
    for (int i = 0; i < N; i++) {
        if ((a[i] * a[i + 1]) < 0)
            brojach++;
        if(pom<brojach){
            if(maks<brojach){
                maks=brojach;
            }
            pom=brojach;
        } else {
            brojach=1;
            pom=0;
        }
    }
    return maks;
}



int main() {
    int i, j, k;
    int a[MAX];
    int N;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    int rez = najdiNajdolgaCikCak(a, N);
    printf("%d\n", rez);

    return 0;
}