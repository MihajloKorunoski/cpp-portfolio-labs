#include<stdio.h>
#include<string.h>
void f(int a)
{
	printf("%d\n", a*a);
	if(a>1)
	f(a-1);
	printf("%d\n",a*a);
}
int main()
{
	char a[]={'3','2','1',0,'\n','\0'};	
	int len=strlen(a);
	printf("%d\n",len);
	f(5);
	return 0;
}
