#include <stdio.h>
#include <ctype.h>
void writeToFile()
{
    FILE *f = fopen("text.txt","w");
    char c;
    while ((c=getchar())!= '#')
    {
        fputc(c,f);
    }
    fclose(f);
}

int main()
{
    writeToFile();

    FILE *pok;
    if((pok=fopen("text.txt", "r"))==NULL);
    {
        printf("Ne mozhe da se otvori datotekata! ");
        return -1;
    }

    char ch;
    int golemi=0, mali=0;
    while((ch=fgetc(pok))!=EOF)
    {
        if(isalpha(ch))
        {
        if(islower(ch))
            mali++;
        if(isupper(ch))
            golemi++;

        }
    }
    printf("%.4f\n%.4f",(float)golemi/(mali+golemi),(float)mali/(mali+golemi));
    fclose(pok);
    return 0;
}
