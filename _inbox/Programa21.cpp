#include <stdio.h>
int main ()
{
	int n,d,e,s,i,kolega,br=0,raz;
	scanf("%d", &n);
	e=n%10;
	d=n%100/10;
	s=n%1000/100;
	i=n%10000/1000;
	printf("%d%d%d%d\n",e,d,s,i);
	if(e==5)
	{
		br++;
		e=6;
	}
	if(d==5)
	{
		br++;
		d=6;
	}
	if(s==5)
	{
		br++;
		s=6;
	}
	if(i==5)
	{
		br++;
		i=6;
	}
	kolega=e+d*10+s*100+i*1000;
	printf("%d\n",kolega);
	raz=kolega-n;
	if(br<2)
	printf("ERROR");
	else
	printf("%.4f%%",(float)raz/kolega*100);
	return 0;

}
