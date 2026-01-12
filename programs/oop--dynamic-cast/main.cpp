#include<iostream>
using namespace std;

class A{
	public:
		virtual void print(){
			cout<<"A - print called"<<endl;
		}
};
class B : public A{
	public:
		void print(){
			cout<<"B - print called"<<endl;
		}
};
class C : public B{
	public:
		void print(){
			cout<<"C - print called"<<endl;
		}
};
int main(){
	A *a;
	B b;
	C c;
	a = &c;
	B *pok=dynamic_cast<B *>(a);
	if (pok){
		pok->print();
	}
	return 0;
}
