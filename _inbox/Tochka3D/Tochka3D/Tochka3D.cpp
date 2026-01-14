#include <iostream>
using namespace std;
class Tocka3D
{
private:
	double x;
	double y;
	double z;
public:
	Tocka3D(){}
	Tocka3D(double a, double b, double c)
	{
		postavitocka(a, b, c);
	}
	void postavitocka(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}
	double volumen(Tocka3D A, Tocka3D B, Tocka3D C)
	{
		double V = A.x * B.y * C.z + A.y * B.z * C.x + A.z * B.x * C.y - A.z * B.y * C.x - A.x * B.z * C.y - A.y * B.x * C.z;
		return abs(V / 6);
	}
	bool komplanarnost(Tocka3D A, Tocka3D B, Tocka3D C)
	{
		return (volumen(A, B, C) == 0) ? true : false;
	}
	void prikazitocka(Tocka3D M)
	{
		cout << "(" << M.x << "," << M.y << "," << M.z << ")";
	}

};
int main()
{
	system("Color A");
	Tocka3D A(1, 2, -3);
	Tocka3D B(-2, 3, -1);
	Tocka3D C(4, 1, -5);
	
	bool DaNe = A.komplanarnost(A, B, C);
	cout << "Tockite: ";
	cout << "A";
	A.prikazitocka(A);
	cout << " , ";
	cout << "B";
	B.prikazitocka(B);
	cout << " i ";
	cout << "C";
	C.prikazitocka(C);
	if (DaNe)
	{
		cout << endl << "Komplanarni se. " << endl << "Volumenot na piramidata iznesuva: " << A.volumen(A, B, C);
	}
	else
	{
		cout << endl << "Ne se komplanarni. " << endl << "Volumenot na piramidata iznesuva: " << A.volumen(A, B, C);
	}
	cout << endl << endl;
	return 0;
}
