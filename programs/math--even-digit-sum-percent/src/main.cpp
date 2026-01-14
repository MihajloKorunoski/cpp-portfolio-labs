#include<stdio.h>

int main()
{
    int n,m,i,j,k,cifra,rez;
    int suma=0,proizvod=1, duplikat, broj, procent;


    scanf("%d%d", &broj,&procent );

        while(   broj    )
        {
            duplikat=broj;


            while ( duplikat ){

                cifra=duplikat%10;

                if( (cifra%2)==0 )
                {
                    suma+= cifra;
                }

                duplikat /= 10;// kratenje na duplikat
            }

            if((suma*100)/broj==procent ) printf("%d\n", broj );

            broj--;
            suma=0;

        }


    return 0;
}
