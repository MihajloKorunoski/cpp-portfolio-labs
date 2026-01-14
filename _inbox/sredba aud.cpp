#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Momche 
{
	private:
		int godini;
		char ime[20];
		char prezime[20];
	public:
		Momche(int godini=0, char *ime="", char *prezime="")
		{
			this->godini=godini;
			strcpy(this->ime,ime);
			strcpy(this->prezime,prezime);
		}
		Momche(const Momche &m)
		{
			godini=m.godini;
			strcpy(ime,m.ime);
			strcpy(prezime,m.prezime);
		}
		~Momche(){
		}
		int getgodini()
		{
			return godini;
		}
		void print()
		{
			cout<<"Momche: "<<ime<<" "<< prezime << " "<<godini<<" ";
		}
		
};
class Momiche
{
	private:
		int godini;
		char ime[20];
		char prezime[20];
	public:
		Momiche(int godini=0, char *ime="", char *prezime="")
		{
			this->godini=godini;
			strcpy(this->ime,ime);
			strcpy(this->prezime,prezime);
		}
		Momiche(const Momiche &mo)
		{
			godini=mo.godini;
			strcpy(ime,mo.ime);
			strcpy(prezime,mo.prezime);
		}
		~Momiche(){
		}
		int getgodini()
		{
			return godini;
		}
		void print()
		{
			cout<<"Momiche: "<<ime<<" "<< prezime << " "<<godini<<" ";
		}
};
class Sredba
{
	private:
		Momche momche;
		Momiche momiche;
	public:
		Sredba(const Momche &m, const Momiche &mo)
		{
			momche=m;
			momiche=mo;
		}
		~Sredba(){
		}
		void print()
		{
			cout<<"Sredba: ";
			momche.print();
			momiche.print();
		}
		void dalisiodgovaraat()
		{
			if(abs(momche.getgodini()-momiche.getgodini())<5)
			cout<<"Si odgovaraat"<<endl;
			else
			cout<<"Ne si odgovaraat"<<endl;
		}
};
int main()
{
	int godini;
	char ime[20], prezime[20];
	cout<<"Informacii za momche:"<<endl;
	cout<<"Ime: ";
	cin >> ime;
	cout << "Prezime: ";
 	cin >> prezime;
  	cout << "Godini: ";
  	cin >> godini;
  	Momche m(godini, ime, prezime);
  	Momche momche(m);
  	
  	cout << "Informacii za Momiche: " << endl;
  	cout << "Ime: ";
  	cin >> ime;
  	cout << "Prezime: ";
 	cin >> prezime;
  	cout << "Godini: ";
  	cin >> godini;
  	Momiche mo(godini, ime, prezime);
  	Momiche momiche = mo; 
	
	Sredba s(momche,momiche);
	s.print();
	s.dalisiodgovaraat();
	return 0;
}






































