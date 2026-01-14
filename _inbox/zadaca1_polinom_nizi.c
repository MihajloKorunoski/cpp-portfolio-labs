
#include<stdio.h>
#define MAX_ELEMENTI 100

typedef int element;

/*

Da se napise funkcija za sobiranje na dva polinoma. Ako polinomot e 

P(x) = bm-1 xem-1 + bm-2xem-2 + ... + boxeo  kade sto   bi  != 0,    em-1 > em-2 > … > eo

polinomot moze da se pretstavi so pole so dolzina 2m+1, odn. 

(m,em-1,bm-1,em-2,bm-2, ...,e0,b0).

*/
main()
{
    int a; 
    void soberiPolinomi(element[], element[], element[]);
    element polinom1[] = {4,4,1,3,10,2,3,0,1};
    element polinom2[] = {2,5,1,0,1}; 
    element rezultat[20];
    soberiPolinomi(polinom1, polinom2, rezultat);
    int i;
    for(i = 0; i<= 2*rezultat[0]; i++)
        printf("%d\n",rezultat[i]);
    scanf("%d",&a);
}
   
void soberiPolinomi(element polinom1[], element polinom2[], element rezultat[])
{
    int i, j, k, n , m;
    
    n = polinom1[0];    // n  broj na nenulev koef vo polinom 1
    m = polinom2[0];    // m  broj na nenulev koef vo polinom 2
    
    i = j = k = 1;
    
    while ((i <= 2*n ) && (j <= 2*m ))
    {
        if (polinom1[i] == polinom2[j])    // sporedba na eksponenti
        {
            rezultat[k+1] = polinom1[i+1] + polinom2[j+1];    // sobiranje na koeficientite
        
                if (rezultat[k+1] != 0) {
                rezultat[k] = polinom1[i]; k+=2;
                }
             i+=2;
             j+=2; 
        }
        else {
        if (polinom1[i] < polinom2[j])
        {
            rezultat[k+1] = polinom2[j+1];
            rezultat[k] = polinom2[j]; 
            k+=2;
            j+=2;
        }else
        if (polinom1[i] > polinom2[j])
        {
            rezultat[k+1] = polinom1[i+1];
            rezultat[k] = polinom1[i]; 
            k+=2;
            i+=2;
        }
            }
    }
    while (i <= 2*n)
    {
        rezultat[k+1] = polinom1[i+1];
        rezultat[k] = polinom1[i]; 
        k+=2;
        i+=2;
    }
    while (j <= 2*m)
    {
        rezultat[k+1] = polinom2[j+1];
        rezultat[k] = polinom2[j]; 
        k+=2;
        j+=2;
    }
    rezultat[0] = k/2;
}
