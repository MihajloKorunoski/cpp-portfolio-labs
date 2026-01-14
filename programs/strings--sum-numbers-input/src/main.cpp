#include <stdio.h>
int main()
{
char ch;
int sum = 0, temp = 0;
while((ch = getchar()) != '!')
{
if(ch >= '0'&&ch <= '9')
{
temp = (temp*10) + ch - '0';
//sum = sum + temp;
}
else
{
sum = sum + temp;
temp = 0;
}
}
printf("%d", sum+temp);
return 0;
}
