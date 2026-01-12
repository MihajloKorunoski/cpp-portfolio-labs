#include<iostream>
using namespace std;
 

int main(){
	int a=15;
	try{
		if (a>18){
			cout<<"1";
		}
		else
		throw 0;
	}
	catch(int myNum){
		cout<<"2";
	}
	cout<<"3";
}

