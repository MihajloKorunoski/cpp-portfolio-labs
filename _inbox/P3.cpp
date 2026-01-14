#include <stdio.h>
#define MAX 100
int main ()
{
	int a[MAX],b[MAX],n,i,scalar=0;
	printf("Golemina na nizite:  ");
	scanf("%d", &n);
	printf("Elementi na prvata nizata se: \n");
	for(i=0; i<n; ++i)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("Elementi na vtorata nizata se: \n");
	for(i=0; i<n; ++i)
	{
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
	}
	for(i=0; i<n; ++i)
	{
		scalar+=(a[i]*b[i]);
	}
	printf("Skalarniot proizvod e: %d\n", scalar);
	return 0;
}
