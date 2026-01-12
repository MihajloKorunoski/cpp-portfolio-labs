#include<iostream>
using namespace std;

class A{
	public:
		A(){cout<<"K";
		}
		A(A const& a){
			cout<<"C";
		};
		void operator=(A const& a){
			cout<<"E";
		}
};

int main(){
	A x,y;
	x=x;
	return 0;
}
