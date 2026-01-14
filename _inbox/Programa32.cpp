#include <stdio.h>
int main() 
{
  int m,n,i,x,x2,br1,br2,c=0;
  scanf("%d %d",&m, &n);
  for(i=m+1; i<=1; i++)
 {
	br1=0;
	br2=0;
	x=i;
	while(x!=0)
	{
		x2=x%10;
		x=x/10;
		br1++;
		if(x2%2==0)
		br2++;
		
	}
	if(x==0&&br2==br1)
	{
		printf("%d", i);
		c=1;
		break;
	}
  }
  if(c==0) printf("NE");
  return 0;
}
