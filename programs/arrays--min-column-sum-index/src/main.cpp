#include <stdio.h>
#define MAX 100
int main()
{
    int mat[MAX][MAX];
    int a,b,i,j,zbir,pom=0,maxpom=0,pom2=0,flag;
   	scanf("%d %d",&a,&b);
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
    {
        scanf("%d",&mat[i][j]);
    }
    for(j=0;j<b;j++)   
    {	
        for(i=0;i<a;i++)
        {
        zbir=zbir+mat[i][j]; 
        pom=zbir;
        }
        if(flag==0)
        {
            flag=1;
            maxpom=pom;
        }
        else
        {
        if(pom<maxpom)
        {
            maxpom=pom;
            pom2=j;
        }
        }
        zbir=0;
        
    }
    printf("%d", pom2);
	return 0;
}
