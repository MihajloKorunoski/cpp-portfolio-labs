#include<stdio.h>
long int factorial(int n)
{
	if(n==1)
	return 1;
	return n*factorial(n-1);
}
int main()
{
	int num;
	printf ("Enter an integer number: ");
	scanf ("%d", &num);
	printf("Factorial of %d is = %ld", num,factorial(num));
	printf ("\n");
	return 0;
}
