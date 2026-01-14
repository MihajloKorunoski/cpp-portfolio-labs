#include <iostream>
#include <cstring>
using namespace std;

class Film
{
	private:
		char ime[100];
		char rezhiser[50];
		char zhanr[50];
		int godina;
	public:
		Film(){}
		Film(char *ime, char* rezhiser, char* zhanr, int godina)
		{
			strcpy(this->ime, ime);
			strcpy(this->rezhiser,rezhiser);
			strcpy(this->zhanr, zhanr);
			this->godina=godina;
		}
		void pechatiInformaciizaFilm()
		{
			cout <<"Ime: "<< ime<<endl;
			cout <<"Rezhiser: "<<rezhiser<<endl;
			cout<<"Zanr: "<<endl;
			cout<<"Godina: "<<godina<<endl;
		}
		int getgodina()
		{
			return godina;
		}
		friend void pecati_po_godina(Film *f, int n, int godina)
		{
		for (int i=0; i<n; i++)
		{
			if(f[i].getgodina()==godina)
			{
				f[i].pechatiInformaciizaFilm();
			}
		}
}
};

int main()
{
	int n;
	cin>>n;
	Film f[100];
	for(int i=0;i<n;i++)
	{
	char ime[100];
	char rezhiser[100];
	char zhanr[50];
	int god;
	cin>>ime;
	cin>>rezhiser;
	cin>>zhanr;
	cin>>god;
	f[i]=Film(ime,rezhiser,zhanr,god);
	}
	int god;
	cin>>god;
	pecati_po_godina(f,n,god);
	return 0;
}

