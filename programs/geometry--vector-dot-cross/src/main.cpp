
#include <iostream>
#include <cstdlib>
using namespace std;
class Vektor
{
private:
	double x;
	double y;
	double z;
public:
	Vektor() {}
	Vektor(double a, double b, double c)
	{
		postaviVektor(a, b, c);
	}
	void postaviVektor(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}
	double skalarenproizvod(Vektor U, Vektor V)
	{

		return U.x * V.x + U.y * V.y + U.z * V.z;
	}
	Vektor vektorskiproizvod(Vektor U, Vektor V)
	{
		Vektor W;
		W.x = U.y * V.z - U.z * V.y;
		W.y = U.z * V.x - U.x * V.z;
		W.z = U.x * V.y - U.y * V.z;
		return W;
	}
	void prikazhivektor(Vektor M)
	{
		cout << M.x << "i";
		(M.y >= 0) ? cout << " + " << M.y << "j" :
			cout << " - " << abs(M.y) << "j";
		(M.z >= 0) ? cout << " + " << M.z << "k" :
			cout << " - " << abs(M.z) << "k";
	}
};
int main()
{
	system("Color 17");
	Vektor U(2, 3, -5);
	Vektor V(5, 6, 7);
	cout << "Za vektorite:" << endl;
	cout << "\tu = ";
	U.prikazhivektor(U);
	cout << endl;
	cout << "\tv = ";
	V.prikazhivektor(V);
	cout << endl;
	cout << "Skalarniot proizvod e: uv = " << V.skalarenproizvod(U, V) << endl;
	Vektor W = W.vektorskiproizvod(U, V);
	cout << "Vektorskiot proizvod e: uxv = ";
	W.prikazhivektor(W);
	cout << endl << endl;
	return 0;
}
