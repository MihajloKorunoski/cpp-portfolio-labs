#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

struct Student{
	char name[50];
	int index;
};
struct Fakultet{
	char naziv[20];
	struct Student st[1000];
}faks;
int main(){
	strcpy(faks.st[0].name,"Tosho");
	cout<<faks.st[0].name;
	
}
