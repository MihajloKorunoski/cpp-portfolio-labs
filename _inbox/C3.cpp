#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wtf() //Ova kako sho ti e daeno tamu taka ostaj go, jas vaka go naprajv za da raboti vo mojot kompjuter
{
    FILE *f = fopen("dat.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}
int main() 
{
    wtf();
    FILE *f=fopen("dat.txt","r");
    int brojach=0,brojach2,maxbrojach=0,i;
    char a[1000],b[1000];
    char *cp;
    while(fgets(a,1000,f)!=NULL)
    {
    	brojach2=0;
    	brojach++;
    	for(i=0;i<strlen(a);i++)
    	{
    		if(isalpha(a[i]))
    		{
    			if(isupper(a[i]))
    			brojach2++;
			}
		}
		if(maxbrojach<brojach2)
		{
			maxbrojach=brojach2;
			strcpy(b,a);

			
		}
	}
	fclose(f);
	if(maxbrojach==0)
	{
		printf("Nema nitu eden zbor so golema bukva.");
	}
	else
	{
		for(cp=b; *cp; cp++)
        if(isalpha(*cp))
        printf("%c", *cp);
		printf(" %d",maxbrojach);
	}
	return 0;
	
}
    
