#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

struct faculty{
	int years;
	char name[20];
}f;

int main(){
	f.years=9;
	strcpy(f.name, "FINKI");
	printf("%s-%d",f.name,f.years);
	return 0;
}
