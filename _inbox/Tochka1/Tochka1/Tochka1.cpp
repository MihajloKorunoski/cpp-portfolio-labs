
#include <iostream>
using namespace std;
class Tocka
{
private: 
	double x;
	double y;
public:
	Tocka() {}
	Tocka (double a, double b)
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
	void srednaTocka(double Ax, double Ay, double Bx, double By)
	{
		double Cx = (Ax + Bx) / 2;
		double Cy = (Ay + By) / 2;
		cout << "\nSredna tocka e C(" << Cx << "," << Cy << ")" << endl;
	}
	void prikaziTocka(double x, double y)
	{
		cout << "(" << x << "," << y << ")";
	}
};

int main()
{
	Tocka A(5, 8);
	Tocka B(-2, 3);
	cout << "Na otsechkata AB: ";
	cout << "A:";
	A.prikaziTocka(A.zemiX(), A.zemiY());
	cout << ",";
	B.prikaziTocka(B.zemiX(), B.zemiY());
	Tocka C;
	C.srednaTocka(A.zemiX(), A.zemiY(), B.zemiX(), B.zemiY());
	cout << endl;
	return 0;
}
