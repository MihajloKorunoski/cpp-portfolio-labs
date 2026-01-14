#include <stdio.h>

#define MAX_ELEMENTI 100
typedef struct {
    int info;
} element;

int main() {
    int a;
    element pole[MAX_ELEMENTI];
    element nov;
    void vnesi_element(element[], int, element, int *);
    void najdi_element(element[], element, int);
    void brishi_element(element[], element, int *);
    int m = 10;
    for (int i = 0; i < m; i++) {
        pole[i].info = 1;
    }
    for (int i = 0; i < m; i++)
        printf("%d", pole[i].info);
    printf("\nbroj na elementi %d\n", m);

    nov.info = 2;
    vnesi_element(pole, 3, nov, &m);
    for (int i = 0; i < m; i++)
        printf("%d",pole[i].info);
    printf("\nbroj na elementi %d\n",m);

    najdi_element(pole,nov,&m);

    brishi_element(pole,nov,&m);

    for(int i=0;i<m;i++)
        printf("%d", pole[i].info);
    printf("\nbroj na elementi %d\n", m);
    scanf("%d",&a);
}
void vnesi_element(element pole[], int index,element nov_element,int *n){
    int broj_na_elementi=*n;

    if(index>broj_na_elementi)
        printf("Izberete nov index! brojot na elementi vo nizata e %d\n",broj_na_elementi);
    else if(broj_na_elementi==MAX_ELEMENTI)
        printf("Nizata e polna \n");
    else{
        for(int i=broj_na_elementi-1;i>=index;i--)
            pole[i+1].info=pole[i].info;
        pole[index].info=nov_element.info;
        printf("Elementot e vnesen!\n");

        (*n)++;
    }
}

void najdi_element(element pole[], element element1, int n){
    int i;
    for(int i=0;i<n;i++)
        if(pole[i].info==element1.info)
            break;
        if(i==n)
            printf("Elementot ne e pronajden\n");
        else printf("Elementot e pronajden na index &d\n",i);
}

void brishi_element(element pole[],element element1, int *n){
    int broj_na_elementi=*n;
    int i;
    for(i=0;i<broj_na_elementi;i++)
        if(pole[i].info==element1.info){
            for( int j=i;j<broj_na_elementi-1;j++)
                pole[j].info=pole[j+1].info;
            *n=*n-1;
            break;
        }
    if (i==broj_na_elementi)
        printf("Elementot ne e pronajden\n");
    else
        printf("Elementot e izbrishan\n");
}













