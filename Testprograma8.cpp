#include<iostream>
using namespace std;

class A{
		int x;
	public:
		A(){
			x=0;
		}
		A& operator+=(int i){
			x+=i;
			return *this;
		}
		int getX(){
			return x;
		}
};

int main(){
	A a;
	a+=15;
	cout<<a.getX();
	return 0;
}
