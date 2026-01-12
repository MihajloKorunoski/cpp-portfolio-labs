#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
class Base1{
	public:
		void someFunction(){
			cout<<"A ";
		}
};
class Base2{
	public:
		void someFunction(){
			cout<<"B ";
		}
};
class Derived: public Base1, Base2{
};
int main(){
	Derived d;
	d.Base1::someFunction();
	return 0;
}
