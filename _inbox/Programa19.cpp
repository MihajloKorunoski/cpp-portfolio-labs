#include<stdio.h>
int main()
{
	int a,N;
	float zbir=0.0;
	scanf("%d", &N);
	char ddv;
	for(int i=0; i<N; i++);
	{
		scanf("%d %c", &a, &ddv);
		if(ddv=='A')
			zbir+=a*18.0/100;
		else if (ddv== 'B')
			zbir+=a*5.0/100;
			
	}
	zbir=zbir/100*15;
	printf("Total: %.2f",zbir);
}
