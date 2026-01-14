#include <stdio.h>
int main ()
{
	int pom,poc,kraj,i,j,n,br;
	printf("Vnesete pocetok i kraj na intervalot:");
	scanf("%d %d", &poc,&kraj);
	printf("Vnesete kolku deliteli se baraat po broj:");
	scanf("%d", &n);
	for(i=poc; i<=kraj; i++)
	{
		j=2;
		br=1;
		while(j<=i/2)
		{
			if(i%j==0)
				br++;
			j++;
		}
		if(br==n)
		{
			printf("Uslovot e ispolnet kaj brojot %d.\n", i);
		}
	}
	return 0;
}
