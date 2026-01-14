#include<iostream>
using namespace std;
class Tocka
{
	public:
		double x;
		double y;
};
int main()
{
	system ("Color A");
	system ("Color 17");
	Tocka A;
	A.x=5;
	A.y=8;
	
	Tocka B;
	B.x= -2;
	B.y = 3;
	
	Tocka C;
	C.x= (A.x+B.x)/2;
	C.y= (A.y+B.y)/2;
	
	cout<<"Na otsechkata AB: "<<"A("<<A.x<<","<<A.y<<"), "<<"B("<<B.x<<","<<B.y<<")"<<"\nsredna tocka e C("<<C.x<<","<<C.y<<")"<<endl;
	cout<<endl;
	return 0;
}
