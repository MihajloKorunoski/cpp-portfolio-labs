#include<stdio.h>
void getFibonacii(int a, int b, int n)
{
	int sum;
	if (n>0)
	{
		sum=a+b;
		printf("%d ",sum);
		a=b;
		b=sum;
		getFibonacii(a,b,n-1);
	}
}
int main()
{
	int a,b,sum,n;
	int i;
	a=0;
	b=1;
	printf("Enter total number of terms: ");
	scanf("%d",&n);
	printf("%d %d ",a,b);
	getFibonacii(a,b,n-2);
	printf("\n");
	return 0;
}
