#include<stdio.h>
#include<string.h>
#include <ctype.h>

void writeToFile()
{
	FILE *f = fopen("text.txt","w");
	char c;
	while ((c=getchar())!='#')
	{
		fputc(c,f);
	}
	fclose(f);
}
int main()
{
	writeToFile();
	FILE *f=fopen("text.txt","r");
	char a[1000],b[1000];
	int count,max=0,c1=0;
	float sum=0;
	while(fgets(a,1000,f)!=NULL)
	{
		count=1;
		max=0;
		c1++;
		for(int i=0;i<strlen(a);i++)
		{
			if (a[i]== ' ')
			count++;
		}
		sum+=count;
		if(!max)
		{
			max=1;
			strcpy(b,a);
			for(int i=0;i<strlen(b);i++)
			{
				if(isalpha(b[i]))
				{
					if(islower(b[i]))
					b[i]=toupper(b[i]);
					else if (isupper(b[i]))
					b[i]=tolower(b[i]);
				}
			}
		}
		printf("%d\n",count);
	}
	
	printf("%.2f\n",sum/c1);
	printf("%s",b);
	return 0;
}
