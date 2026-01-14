// Napishi programa vo koja kje koristish celosno rekurzivna funkcija kade kje presmetash proizvod na cifrite na broj koi se pomali od 6
#include<stdio.h>
int rekurzija(int n)
{
	int pom;
	pom=n%10;
	if(n==0)
	return 1;
	else
	{
	if(pom<=6)
	return pom*rekurzija(n/10);
	else
	return 1*rekurzija(n/10);
	}
}
int main()
{
	int n,p;
	scanf("%d",&n);
	p=rekurzija (n);
	printf("%d",p);
	return 0;
}





