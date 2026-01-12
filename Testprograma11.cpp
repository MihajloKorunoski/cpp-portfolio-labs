#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

class Test{
	private:
		static int x;
	public:
		Test(){
			x++;
		}
		static int getX(){
			return x;
		}
};
int Test::x=0;
int main(){
	cout<<Test::getX()<<" ";
	Test t[5];
	cout<<Test::getX();
}
