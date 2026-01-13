#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int main(){
	try {
		int a=15;
		if(1>18){
			cout<<"1";
		}
		else{
			throw 0;
		}
	}
	catch (int myNum){
		cout<<"2";
	}
	return 0;
}
