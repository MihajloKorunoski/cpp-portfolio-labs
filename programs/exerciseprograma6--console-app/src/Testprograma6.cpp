#include<iostream>
using namespace std;

template <typename T>
T Max(T x,T y)
{
	return (x>y)? x: y;
}

int main(){
	
	cout<<Max(3,7)<<std::endl;
	cout<<Max(3.0,7.0)<<std::endl;
	cout<<Max(3,7.0)<<std::endl;
	return 0;
}
