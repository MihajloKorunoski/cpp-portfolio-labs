#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float pogolem (float x, float y)
{
	if (x>y)
	return x;
	else
	return y;
}
int main ()
{
	double s;
	s=sqrt(2);
	int a,b,c,d,p,q,n;
	cout<<"Vnesi cetiri broja:"<<endl;
	cin>>a>>b>>c>>d;
	p=pogolem (a,b);
	n=pogolem (p,c);
	q=pogolem (n,d);
	cout<<"Najgolem e brojot:"<<q<<endl;
	cout<<"F iznesuva:"<<setprecision(99999)<<s<<endl;
	return 0;
}
