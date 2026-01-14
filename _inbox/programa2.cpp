#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int i,n;
	int niza[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&niza[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d",niza[i]);
		cout<<niza[i];
	}
	printf("\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d",niza[i]);
	}
	printf("\n");
	for(i=n-1;i>=0;i=i-2)
	{
		printf("%d",niza[i]);
	}
	printf("\n");
	for(i=0;i<n;i=i+2)
	{
		printf("%d",niza[i]);
	}
	return 0;
}
