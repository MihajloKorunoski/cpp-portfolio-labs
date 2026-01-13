#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

class A{
	public:
		void fun();
};
void A::fun(){
	cout<<"fun() is static function";
}
int main(){
	A::fun();
	return 0;
}
