#include <iostream>
using namespace std;
class Tocka
{
	private:
		int x;
		int y;
	public:
		void postaviX(int a)
		{
			x=a;
		}
		void postaviY(int b)
		{
			y=b;
		}
		int zemiX()
		{
			return x;
		}
		int zemiY()
		{
			return y;
		}
};
int main()
{
	Tocka A;
	A.postaviX(5);
	A.postaviY(8);
	cout<<"Tocka A("<<A.zemiX()<<","<<A.zemiY()<<")"<<endl;
	cout<<endl;
	return 0;
}
