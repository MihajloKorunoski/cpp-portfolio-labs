#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct proizvod
{
	string ime;
	double cena;
	double kolichina;

};
int main()
{
	int i, n;
	proizvod p[1000];
	double vksuma = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> p[i].ime;
		cin >> p[i].cena;
		cin >> p[i].kolichina;
	}
	for (i = 1; i <= n; i++)
	{
		cout << i << ". " << p[i].ime;
		cout << '\t' << setprecision(2) << fixed << p[i].cena;
		cout << " x ";
		cout << setprecision(1) << fixed << p[i].kolichina;
		cout << " = ";
		cout<< setprecision(2) << fixed << p[i].cena * p[i].kolichina << endl;
		vksuma += p[i].cena * p[i].kolichina;
	}
	cout << "Total: " << setprecision(2) << fixed << vksuma;
	return 0;
}