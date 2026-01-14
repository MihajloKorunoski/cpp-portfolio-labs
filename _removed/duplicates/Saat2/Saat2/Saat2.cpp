#include <iostream>
using namespace std;
class Saat
{
private:
	int chas, min, sec;
public:
	Saat()
	{
		chas = min = sec = 0;
	}
	Saat(int chas, int min, int sec)
	{
		postaviSaat(chas, min, sec);
	}
	void postaviSaat(int chas=0,int min=0,int sec=0)
	{
		if (0 <= chas && chas < 24)
			this->chas = chas;
		else
			this->chas = chas % 24;
		if (0 <= min && min < 60)
			this->min = min;
		else
			this->min = min % 60;
		if (0 <= sec && sec < 60)
			this->sec = sec;
		else
			this->sec = sec % 60;
	}
	void zemiSaat(int& chas, int& min, int& sec)
	{
		chas = this->chas;
		min = this->min;
		sec = this->sec;
	}
	void prikaziSaat()
	{
		zemiSaat(chas, min, sec);
		(chas < 10) ? cout << endl : cout << endl;
		cout << "Tochno " << chas << ":" << min << ":" << sec << endl;
		cout << endl;
	}
	void prikaziSaat(Saat t)
	{
		(t.chas < 10) ? cout << endl : cout << endl;
		cout << "Tochno " << t.chas << ":" << t.min << ":" << t.sec << endl;
		cout << endl;
	}
};
int main()
{
	system("Color A");
	int chas, min, sec;
	Saat mojSaat;
	mojSaat.postaviSaat(8, 19, 40);
	
	Saat tvojSaat;
	tvojSaat.postaviSaat(8, 20, 40);
	cout << "Mojot saat e";
	mojSaat.prikaziSaat();
	cout << "Tvoj saat e";
	tvojSaat.prikaziSaat();

	cout << endl << "Vnesete vreme za mojot saat:" << endl;
	cout << "Chas:";
	cin >> chas;
	cout << "Minuti:";
	cin >> min;
	cout << "Sekundi:";
	cin >> sec;
	mojSaat.postaviSaat(chas, min, sec);

	cout << endl << "Vnesete vreme za tvojot saat:" << endl;
	cout << "Chas:";
	cin >> chas;
	cout << "Minuti:";
	cin >> min;
	cout << "Sekundi:";
	cin >> sec;
	tvojSaat.postaviSaat(chas, min, sec);

	cout << endl << "Nashite saati pokazhuvaat:" << endl << endl;
	cout << "Mojot saat e";
	mojSaat.prikaziSaat();
	cout << "Tvoj saat e";
	tvojSaat.prikaziSaat();

	cout << endl;
	system("pause");
	return 0;
}