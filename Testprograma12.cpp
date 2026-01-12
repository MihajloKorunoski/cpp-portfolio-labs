#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
class A{
	int x;
	public:
		A(int xx=0){
			x=xx;
		}
		void f(int i){
			x=i*i;
		}
		void print(){
			cout<<x;
		}
};
class B: public A{
	public:
		B(){
			f(3);
		}
};
class C: public A{
	public:
		C(){
			f(15);
		}
};
class D : public B, public C{
};
int main(){
	D d;
	d.print();
	return 0;
}
