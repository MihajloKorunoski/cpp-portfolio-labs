#include <stdio.h>
int main()
{
	int poc,kraj,a,b,c;
	printf("Vnesete pochetok i kraj na intervalot:");
	scanf("%d %d",&poc,&kraj);
	printf("\n");
	for(a=poc;a<=kraj;a++)
	for(b=poc;b<=kraj;b++)
	for(c=poc;c<=kraj;c++)
	if(a*a+b*b==c*c)
	{
		printf("Uslovot go zadovoluvaat broevite %d, %d i %d.\n", a,b,c);
		printf("%d+%d=%d\n\n", a*a,b*b,c*c);
	}
	return 0;
}
