#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

template<typename T>
void print_mydata(T output){
	cout<<output<<endl;
}

int main(){
	double d=5.5;
	string s("Hello World");
	print_mydata(d);
	print_mydata(s);
}
