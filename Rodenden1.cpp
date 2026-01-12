#include<iostream>
#include<string>
using namespace std;
string denovi[7] = { "Ponedelnik", "Vtornik", "Sreda", "Chetvrtok", "Petok", "Sbota", "Nedelja" };
int denovivomesec[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
class Rodenden {
private:
	string datum;
public:
	Rodenden() {
		datum= "";
	}
	Rodenden(string datum) {
		postavirodenden(datum);
	}
	void postavirodenden(string datum) {
		this->datum = datum;
	}
	void zemirodenden(string& datum) {
		datum = this->datum;
	}
	bool prestapnagodina(int godina) {
		bool dane = false;
		if (godina % 100 == 0) {
			if (godina % 400 == 0)
				dane = true;
		}
		else{
		if (godina % 4 == 0)
			dane = true;
		}
		return dane;
	}
	
	string rodendenvonedelata(string rodenden) {
		int den = stoi(rodenden.substr(0, 2));
		int mesec = stoi(rodenden.substr(3, 2));
		int godina = stoi(rodenden.substr(6, 4));
		int denovivogodina[2100];
		int sumadenovi = 0;
		for (int i = 1; i < godina; i++) {
			denovivogodina[i] = 365;
			if (prestapnagodina(i))
				denovivogodina[i]++;
			sumadenovi += denovivogodina[i];
		}
		if(prestapnagodina(godina))
			denovivomesec[1]++;
		for(int i=0;i<mesec-1;i++)
			sumadenovi+=denovivomesec[i];
		sumadenovi+=den;
		return denovi[sumadenovi&7-1];
	}
};
int main() {

	string rodenden;
	cout << "Vnesete rodenden(dd.mm.gggg): ";
	cin >> rodenden;
	Rodenden moj(rodenden);
	string den = moj.rodendenvonedelata(rodenden);
	cout << "Rodenden na " << rodenden << " e vo " << den << endl;
	cout << endl << endl;
	system("PAUSE");
	return 0;
}

