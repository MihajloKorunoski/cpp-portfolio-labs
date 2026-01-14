#include <stdio.h>
int main()
{
	int a[100][100];
	int m,n,i,j,p,p2,brojach=0,brojach2=0,brojach3=0;
	scanf("%d %d", &m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);

	for(i=0;i<m;i++)	
		for(j=0;j<n;j++)
		{
			for(p=0;p<m;p++)
			if(a[p][j]==1)
			{
				brojach2++;
			}
			for(p2=0;p2<n;p2++)
			if(a[i][p2]==1)
			{
				brojach++;
			}
			if(brojach==n&&brojach2==m)
			{
				printf("(%d,%d)\n",i,j);
				brojach3++;
			}
			brojach=0;
			brojach2=0;
		}
	printf("%d",brojach3);
	return 0;	
	
}
