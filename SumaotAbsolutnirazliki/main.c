#include<stdio.h>
#include<math.h>

int solve(int numbers[], int N, int K) {
    int rezultat=0;
    int maksabs[1000][1000];
    for (int i = 1; i < N; i++){
        for (int j = 1; j < K; j++){
            for (int a = 0; a < i; a++){
                int rez=abs(numbers[i]-numbers[a]);
                if (maksabs[i][j] < maksabs[a][j-1] + rez)
                    maksabs[i][j] = maksabs[a][j-1] + rez;
            }
            if (maksabs[i][j] > rezultat)
                rezultat = maksabs[i][j];
        }
    }
    return rezultat;

}

int main() {
    int i, N, K;
    int numbers[100];

    scanf("%d %d\n", &N, &K);
    for (i=0;i<N;i++) {
        scanf("%d", &numbers[i]);
    }

    int res = solve(numbers, N, K);
    printf("%d\n", res);

    return 0;
}