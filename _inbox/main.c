#include<stdio.h>
#include<string.h>
#define N 10

void print(int *num, int n)
{
    int i;
    for ( i = 0 ; i < n ; i++)
        printf("%d ", num[i]);
    printf("\n");
}
int main()
{
    int num[N];
    int temp;
    int i, n, j;
    printf("\nHow many number you want to enter: ");
    scanf("%d", &n);
    printf("\nEnter a list of numbers to see all combinations:\n");
    for (i = 0 ; i < n; i++)
        scanf("%d", &num[i]);
    for (j = 1; j <= n; j++) {
        for (i = 0; i < n-1; i++) {
            temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
            print(num, n);
        }
    }
    return 0;
}
//2 1 3 4 5
//2 3 1 4 5
//2 3 4 1 5
//2 3 4 5 1
//3 2 4 5 1
//3 4 2 5 1
//3 4 5 2 1
//3 4 5 1 2
//4 3 5 1 2
//4 5 3 1 2
//4 5 1 3 2
//4 5 1 2 3
//5 4 1 2 3
//5 1 4 2 3
//5 1 2 4 3
//5 1 2 3 4
//1 5 2 3 4
//1 2 5 3 4
//1 2 3 5 4
//1 2 3 4 5
//
//Process finished with exit code 0
