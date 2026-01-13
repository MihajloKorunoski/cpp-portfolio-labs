#include<stdio.h>
#define MAX 1000

int najdiNajdolgaCikCak(int a[], int N) {
    int brojach=0;

    for(int i=0;i<N;i++){
        if((a[i]<0&&a[i+i]>0)||(a[i]>0&&a[i+1]<0))
            brojach++;

    }
    return brojach;
}

int main() {
    int i,j,k;
    int a[MAX];
    int N;

    scanf("%d", &N);

    for (i=0;i<N;i++)
        scanf("%d", &a[i]);

    int rez = najdiNajdolgaCikCak(a, N);
    printf("%d\n", rez);

    return 0;
}