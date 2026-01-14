#include <stdio.h>
int main() {
  int n,i,i2,obraten=0,c=0,broj_cifri=0,k,k2;
  scanf("%d", n);
   if (n>9)
   {
   	for(i=n-1; i>=0;i--)
   	{
   	k=i;
   	obraten=0;
   	broj_cifri=0;
   	while(k!=0)
   	{
   		k2=k%10;
   		k=k/10;
   		obraten=obraten*10+k2;
   		broj_cifri++;
   		if(k==0&&obraten%broj_cifri==0)
   		{
   			c++;
		}
		}
		if(c==1)
		break;
	}
	 printf ("%d",i);
   }
   else printf ("Brojot ne e validen");
  return 0;
}
