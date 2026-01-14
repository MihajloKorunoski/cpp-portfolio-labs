#include <stdio.h>
#include <conio.h>
int main ()
{
	int a,zbir=0,i;
	float p;
	scanf("%d %f", &a, &p);
	int brojac=0;
	
	for (i=a-1; i>0; i--)
	{
		zbir=0;
		int temp=i;
		while(temp>0)
		{
			zbir+=(temp%10);
			temp/=10;
		}

		if(i*(p/100)==zbir)
		{
			brojac++;
			printf("%d\n",i);
			if(brojac==5)
			break;
		}
	}
	if(brojac==0)
	{
		printf ("NEMA");
	}
	return 0;
}
