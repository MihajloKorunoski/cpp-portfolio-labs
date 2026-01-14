#include <stdio.h>
int main ()
{
	int i,n,maxPoeni, maxIndeks, f=1;
	int pobedi,porazi,poeni,nivo;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf ("%d %d %d", &nivo, &pobedi, &porazi);
		if (nivo==1)
		poeni=pobedi*13-porazi;
		if (nivo==2)
		poeni=pobedi*13-porazi*3;
		if(poeni>0)
		printf("Dobar Igrac\n");
		else
		printf("Losh Igrach\n");
		f=0;
		maxPoeni=poeni;
		maxIndeks=1;

		if (poeni>maxPoeni)
		{
			maxPoeni=poeni;
			maxIndeks=i;
		}
	}
	printf("Najdobar igrac: br. %d, %d poeni\n", maxIndeks,maxPoeni );
	return 0;
}
