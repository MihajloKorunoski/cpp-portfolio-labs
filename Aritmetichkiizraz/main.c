#include<stdio.h>
#include<string.h>

#define MAX 1000

// funkcija za presmetuvanje na izrazot pocnuvajki
// od indeks l, zavrsuvajki vo indeks r
int presmetaj(char *c, int l, int r) {
    if (r - l + 1 == 5) {
        if (c[l + 2] == '+')
            return (c[l + 1] - '0') + (c[l + 3] - '0');
        if (c[l + 2] == '-')
            return (c[l + 1] - '0') - (c[l + 3] - '0');
    }
    int push,indeks;

    push=indeks=0;

    for (int i = l; i < r; i++) {
        if (c[i] == '(') push++;
        if (c[i] == ')') push--;
        if ((c[i] == '+') || (c[i] == '-')) {
            if (push == 1) {
                indeks = i;
                break;
            }
        }
    }

    if (c[indeks] == '+')
        return presmetaj(c, l + 1, indeks - 1) + presmetaj(c, indeks + 1, r - 1);
    return presmetaj(c, l + 1, indeks - 1) - presmetaj(c, indeks + 1, r - 1);
}

int main() {
    int rez;
    char c[MAX];

    scanf("%s", c);

    rez = presmetaj(c, 0, strlen(c) - 1);
    printf("%d\n", rez);

    return 0;
}
