#include <stdio.h>
int main ()
{
	int n,x,i,cif1,cif2,flag,kopija,kopija2;
	scanf("%d %d", &n, &x);
	for(i=n-1; i>=0; i--)
	{	
	
		kopija=i;
		flag=0;
		while(kopija!=0)
		{
   
			cif1=kopija%10;
			kopija/=10;
            kopija2=x;
			while(kopija2!=0)
			{
			cif2=kopija2%10;
			kopija2/=10;
			}
			if(cif1==cif2)
					flag=1;				
		}
		if(flag==0)
		{
			printf("%d",i);
			break;
		}
		
	}
	return 0;
}
