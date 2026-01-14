#include <stdio.h>
int main()
{
	int i,n,j;
	int s=0;
	printf("Vnesete n=");
	scanf("%i",&n);
	j=1;
	for (i=0;i<n;i++)
	{
		s+=j;
		j+=3;
	}
	printf("Sumata e: %i\n", s);
	return 0;
}
