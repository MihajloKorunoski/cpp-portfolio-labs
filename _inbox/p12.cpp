#include <stdio.h>
long int stepen(int n, int m)
{
	if (m==0)
	return 1;
	if (n==1)
	return 1;
	else
	return (n*stepen(n,(m-1)));
}
int main()
{
	int i,n,m;
	long int a[100];
	printf ("Kolku elementi da ima nizata? ");
	scanf ("%d",&n);
	printf("Vnesete ja nizata:\n");
	for (i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d", &a[i]);
	}
	printf("Na koj stepen da se stepenuvaat: ");
	scanf("%d",&m);
	printf("Stepenuvanata niza e: ");
	for (i=0;i<n;i++)
	{
		a[i]=stepen(a[i],m);
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
