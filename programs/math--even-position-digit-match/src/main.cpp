#include <stdio.h>
int main() {
  int m, n, x,y,pomosna,x2,brojac1=0,y2,brojac2=0,totalno=0;
  scanf("%d %d", &x,&y);
   if (y<x&& x>0 && y>0)
   {
   	pomosna=y;
   	y=x;
   	x=pomosna;
   }
   if (x>0&& y>0)
   {
   	while (x>0)
   	{
   	
	   x2=x%10;
	   x=x/10;
	   brojac1++;
	   	while (y>0)
	   	{
	   		int c=0;
	   		y2=y%10;
	   		y=y/10;
	   		brojac2++;
	   		if(brojac2%2==0 && x2==y2)
	   		{
	   			totalno++;
	   			break;
			   }
		}
	 }
	 if(totalno==brojac1 && y<10) printf ("PAREN");
	 else printf ("NE");
   }
   else printf ("Invalid Input");
  return 0;
}
