
#include <iostream> 
using namespace std;
class Tocka
{
private:
	double x;
	double y;
public:
	Tocka() {}
	Tocka(double a, double b)
	{
		x = a;
		y = b;
	}
	void postaviX(double a)
	{
		x = a;
	}
	void postaviY(double b)
	{
		y = b;
	}
	double zemiX()
	{
		return x;
	}
	double zemiY()
	{
		return y;
	}
	Tocka srednaTocka(Tocka A, Tocka B)
	{
		double Cx = (A.zemiX() + B.zemiX()) / 2;
		double Cy = (A.zemiY() + B.zemiY()) / 2;
		return Tocka(Cx, Cy);
	}
	void prikazhiTocka(Tocka M)
	{
		cout << "(" << M.zemiX() << "," << M.zemiY() << ")";
	}
};
int main()
{
	Tocka A(5, 8);
	Tocka B(-2, 3);
	Tocka C;
	C = C.srednaTocka(A, B);
	cout << "Na otsechkata AB: ";
	cout << "A:";
	A.prikazhiTocka(A);
	cout << ",";
	B.prikazhiTocka(B);
	cout << "\nSredna tocka e C:";
	C.prikazhiTocka(C);
	cout << endl << endl;
	return 0;
}
