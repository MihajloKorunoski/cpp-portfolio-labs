#include <iostream>
#include <cstring>
using namespace std;
class Datum{
	private:
		int den, mesec, godina;
	public:
		Datum( int den= 0, int mesec= 0, int godina= 0)
		{
			this->godina=godina;
			this->mesec=mesec;
			this->den=den;
		}
		Datum(const Datum &d)
		{
			godina=d.godina;
			mesec=d.mesec;
			den=d.den;
		}
		~Datum(){
		}
		int getden()
		{
			return den;
		}
		int getmesec()
		{
			return mesec;
		}
		int getgodina()
		{
			return godina;
		}
};
class Vraboten{
	private:
		char ime[20];
		int plata;
		Datum dataragjanje;
	public:
		Vraboten(){
		}
		Vraboten(char *ime, int plata, const Datum &data)
		{
			strcpy(this->ime, ime);
			this->plata=plata;
			dataragjanje=data;
		}
		~Vraboten(){
		}
		int getplata()
		{
			return plata;
		}
		Datum getdataragjanje()
		{
			return dataragjanje;
		}
		void print()
		{
			cout<<"Ime: "<<ime<<endl;
			cout<<"Plata: "<<plata<<endl;
			cout<<"Datum na ragjanje: "<<dataragjanje.getden()<<"."<<dataragjanje.getmesec()<<"."<<dataragjanje.getgodina()<<endl;
		}
};
Vraboten najgolemaplata(Vraboten v[],int n)
{
	int max=v[0].getplata();
	int index=0;
	for(int i=1; i<n;i++)
	{
		if(v[i].getplata()>max)
		{
			max=v[i].getplata();
			index=i;
		}
	}
	return v[index];
}
int sporedba(Datum d1, Datum d2)
{
	if(d1.getgodina()>d2.getgodina()) return 1;
	if(d1.getgodina()<d2.getgodina()) return 2;
	if(d1.getmesec()>d2.getmesec()) return 1;
	if(d1.getmesec()<d2.getmesec()) return 2;
	if(d1.getden()>d2.getden()) return 1;
	if(d1.getden()<d2.getden()) return 2;
}
Vraboten najmlad(Vraboten v[],int n)
{
	Datum datum(v[0].getdataragjanje());
	int index=0;
	for(int i=1; i<n;i++)
	{
		if(sporedba(v[i].getdataragjanje(),datum))
		{
			datum=v[i].getdataragjanje();
			index=i;
		}
	}
	return v[index];
}
int main()
{
	Datum d1(1,1,1980);
	Datum d2(1,2,1983);
	Datum d3(11,12,1984);
	
	Vraboten v[3];
	Vraboten v1("Marjan", 40000, d1);
	Vraboten v2("Stefan", 30000, d2);
	Vraboten v3("Marko", 20000, d3);
	v[0] = v1; 
	v[1] = v2; 
	v[2] = v3;
	cout<<"Najmlad vraboten: "<<endl;
	najmlad(v,3).print();
	cout<<"Vraboten so najgolema plata: "<<endl;
	najgolemaplata(v,3).print();
	
	return 0;
}


























