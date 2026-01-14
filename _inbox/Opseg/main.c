#include<stdio.h>
#include<math.h>

int s(int x) {
    int pom = 0;
    while (x > 0) {
        pom += x % 10;
        x = x / 10;
    }
    return pom;
}

long proveri(long N, long A, long B) {
    if (A == B)
        return -1;
    if (pow(A, 2) + s(A) + 200 * A == N)
        return A;
    if (pow(B, 2) + s(B) + 200 * B == N)
        return B;
    long sredina = (A + B) / 2;
    long temp;
    temp = s(sredina) + pow(sredina, 2) + (200 * sredina);
    if (temp > N)
        return proveri(N, A, sredina);
    else if (temp < N)
        return proveri(N, sredina, B);
    return sredina;
}

int main() {
    long N, A, B;

    scanf("%ld", &N);
    scanf("%ld", &A);
    scanf("%ld", &B);

    long res = proveri(N, A, B);
    printf("%ld\n", res);

    return 0;
}