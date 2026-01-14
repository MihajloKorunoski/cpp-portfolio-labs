#include<stdio.h>
int obratenBroj (int);
int sumaNaCifri (int);
void pecatiVoInterval (int, int);
int obratenBroj (int broj)
{
    int broj2=0,cif;
    while(broj>0)
    {
        cif=broj%10;
        broj2=broj2*10+cif;
        broj=broj/10;
    }
    return broj2;
}
int sumaNaCifri (int broj)
{
    int broj2=0,cif;
    while(broj>0)
    {
        cif=broj%10;
        broj2=broj2+cif;
        broj=broj/10;
    }
    return broj2;
}
void pecatiVoInterval (int a, int b)
{
    int i;
    for(i=a; i<=b; i++)
    {
        if((i+obratenBroj(i))%sumaNaCifri(i+obratenBroj(i))==0)
        {
        
            printf("%d\n", i);
    	}
    }
}

int main () 
{
    
    int a,b;
    scanf("%d %d", &a, &b);   
    pecatiVoInterval(a,b);    
    return 0;

}
