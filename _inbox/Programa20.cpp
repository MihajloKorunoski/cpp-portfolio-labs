#include <stdio.h>
int main ()
{
	int i,j,n;
	scanf("%d", &n);
	if(n>=2)
	{
	for(i=1; i<=n; i++)
	{	
		for(j=1; j<=n; j++)
		{
   				
				   if(i==1)
				   {
				   		printf("*");
				   		break;
					}
					else if((i>=2&&j==1)||(i==n))
				   {
				   		printf("*");
					}
					if(i==j)
				   {
				   		printf("*");
				   		break;
					}
					else printf (" ");
			
		}
		printf("\n");
		
	}	
	}
	else printf("Nevaliden vlez");
	return 0;

}
