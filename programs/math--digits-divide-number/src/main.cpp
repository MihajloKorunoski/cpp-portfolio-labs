#include <stdio.h>
int main ()
{
	int pom,poc,kraj,i,a,deliv;
	printf("Vnesete pocetok i kraj na intervalot:");
	scanf("%d %d", &poc,&kraj);
	for(i=poc; i<=kraj; i++)
	{
		pom=i;
		deliv=1;
		while(pom>0)
		{
			a=pom%10;
			if(a!=0)
			{
				if(i%a!=0)
				deliv=0;
			}
			pom/=10;
		}
		if(deliv)
		{
			printf("Uslovot e ispolnet kaj brojot %d.\n", i);
		}
	}
	return 0;
}
