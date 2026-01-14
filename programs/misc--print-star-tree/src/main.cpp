#include<stdio.h>
void elka(int n)
{
    int i,pom,pom2,pom3;
    for(i=1;i<=n;i+=2)
    {
    	pom=i;
    	pom2=(n-i)/2;
    	pom3=(n-i)/2;
    	while(pom2>0)
    	{
    	printf(" ");
    	pom2--;
		}
        while(pom>0)
        {
        printf("*");
        pom--;
        }
        while(pom3>0)
    	{
    	printf(" ");
    	pom3--;
		}
        printf("\n");
        
    }
}
int main() {    
    int n;    
    scanf("%d", &n);    
    elka(n);    
    return 0;
}
