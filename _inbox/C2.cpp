#include<stdio.h>
#include<ctype.h>
#include<string.h>
int brojSoglaski(char *niza)
{
	int bukva=*niza;
	static int brojach=0;
	if(*niza)
	{
	if(isalpha(bukva))
	if (bukva!='a'&&bukva!='e'&&bukva!='i'&&bukva!='o'&&bukva!='u'&&bukva!='A'&&bukva!='E'&&bukva!='I'&&bukva!='O'&&bukva!='U')
	{
		brojach++;
	}
	brojSoglaski(niza+1);
	return brojach;
	}
	
}
int main ()
{
	char ch,niza[100][100];
	int n,p,i=0;
	for(i=0;i<=n;i++)
    {
        fgets(niza[i],sizeof(niza),stdin);
    }
    for(i=0;i<=n;i++)
    {
	p=brojSoglaski(niza[i]);
	}
	printf("%d",p);
	return 0;
	
}
