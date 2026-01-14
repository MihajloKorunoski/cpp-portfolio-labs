#include <iostream>
#include <cmath>
using namespace std;

class Krug
{
	private:
		float radius;
		float pi;
	public:
		Krug(){}
		Krug(float radius=0, const float pi=3.14)
		{
			this->radius=radius;
			this->pi=pi;
		}
		float getradius()
		{
			return radius;
		}
		float getpi()
		{
			return pi;
		}
		float perimetar()
		{
			return 2*getpi()*getradius();
		}
		float ploshtina()
		{
			return pow(getradius(),2)*getpi();
		}
		bool ednakvi()
		{
			return (ploshtina()==perimetar())? true: false;
		}
};
int main()
{
	float r;
	cin>>r;
	Krug k(r);
	cout<<k.perimetar()<<endl;
	cout<<k.ploshtina()<<endl;
	cout<<k.ednakvi()<<endl;
	Krug k1();
	return 0;
}
