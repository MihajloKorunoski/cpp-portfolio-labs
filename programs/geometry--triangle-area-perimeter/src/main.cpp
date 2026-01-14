#include <iostream>
#include <cmath>
using namespace std;
class Triangle 
{
	private:
		int a,b,c;
	public:
		Triangle (int x, int y ,int z)
		{
			a=x;
			b=y;
			c=z;
		}
		~Triangle()
		{}
		int perimeter()
		{
			return a+b+c;
		}
		float area()
		{
			float s=(a+b+c)/2;
			return sqrt(s*(s-a)*(s-b)*(s-c));
		}
};
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	Triangle t(a,b,c);
	cout<<"Area: "<<t.area()<<endl;
	cout<<"Perimeter:"<<t.perimeter()<<endl;
	return 0;
}




















