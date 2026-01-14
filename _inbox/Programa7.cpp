#include <stdio.h>
int main ()
{
	int n,i,j,pom,prost;
	printf("Vnesete vrednost za n:");
	scanf("%d", &n);
	pom=2;
	for(i=2; i<n; i++)
	{
		prost=1;
		j=2;
		while(prost && j<=(i/2))
		{
			if(i%j==0)
				prost=0;
			j++;
		}
		if(prost)
		{
			if(pom+2==i)
			printf("Takvi broevi se %d i %d. \n", pom,i);
			pom=i;
		}
	}
	return 0;
}
