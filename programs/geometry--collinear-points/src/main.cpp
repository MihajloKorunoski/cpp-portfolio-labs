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
	bool kolinearnost(Tocka A, Tocka B, Tocka C)
	{
		int vektorski = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
		if (!vektorski)
			return true;
		else
			return false;
	}
	void prikaziTocka(Tocka M)
	{
		cout << "(" << M.zemiX() << "," << M.zemiY() << ")";
	}
};


int main()
{
	int x, y;
	cout << "Vnesete gi koordinatite na tockata A: " << endl;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	Tocka A(x, y);
	cout << "Vnesete gi koordinatite na tockata B: " << endl;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	Tocka B(x, y);
	cout << "Vnesete gi koordinatite na tockata C: " << endl;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	Tocka C(x, y);
	cout << "Tockite";
	cout << "A:";
	A.prikaziTocka(A);
	cout << ", ";
	cout << "B:";
	B.prikaziTocka(B);
	cout << " i ";
	cout << "C:";
	C.prikaziTocka(C);
	if (A.kolinearnost(A, B, C))
		cout << endl << "Se kolinearni." << endl << endl;
	else
		cout << endl << "Ne se kolinearni." << endl << endl;
	return 0;
}
