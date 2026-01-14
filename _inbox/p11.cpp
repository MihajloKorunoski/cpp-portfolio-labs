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
	int a,b;
	printf("Vnesete broj i eksponent: ");
	scanf("%d %d", &a, &b);
	printf("%d na stepen %d = %ld\n" ,a,b,stepen(a,b));
	return 0;
}
