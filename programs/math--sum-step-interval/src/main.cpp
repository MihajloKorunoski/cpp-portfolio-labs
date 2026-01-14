#include <stdio.h>
int main()
{
	int poc,kraj,chekor;
	int faktor=0;
	int suma=0;
	printf("Vnesete pochetok i kraj na intervalot:");
	scanf("%d %d",&poc,&kraj);
	printf("Vnesete chekor:");
	scanf("%d",&chekor);
	printf("\n");
	while ((poc+faktor*chekor)<kraj)
	{
		printf("%d+", poc+faktor*chekor);
		suma=suma+(poc+faktor*chekor);
		faktor++;
	}
	printf("0=%d\n",suma);
	return 0;
}
