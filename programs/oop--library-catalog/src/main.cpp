#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class Kniga{
	private:
		string naslov;
		string avtori;
		string izdavach;
		int godina;
		string isbn;
		double cena;
	public:
		Kniga(){
			naslov=avtori=izdavach=isbn="";
			godina=cena=0;
		}
		Kniga(string naslov, string avtori, string izdavach, int godina, string isbn,double cena){
			postavikniga(naslov, avtori, izdavach, godina, isbn, cena);
		}
		void postavikniga (string naslov, string avtori, string izdavach, int godina, string isbn,double cena){
			this->naslov=naslov;
			this->avtori=avtori;
			this->izdavach=izdavach;
			this->godina=godina;
			this->isbn=isbn;
			this->cena=cena;
		}
		void zemikniga(string &naslov, string &avtori, string &izdavach, int &godina, string &isbn,double &cena){
			naslov=this->naslov;
			avtori=this->avtori;
			izdavach=this->izdavach;
			godina=this->godina;
			isbn=this->isbn;
			cena=this->cena;
		}
		void prikazhikniga(Kniga ovaa){
			cout<<left<<endl;
			cout<<setw(10)<<"Naslov: "<<ovaa.naslov<<endl;
			cout<<setw(10)<<"Avtori: "<<ovaa.avtori<<endl;
			cout<<setw(10)<<"Izdavach: "<<ovaa.izdavach<<endl;
			cout<<setw(10)<<"Godina: "<<ovaa.godina<<endl;
			cout<<setw(10)<<"ISBN: "<<ovaa.isbn<<endl;
			cout<<setw(10)<<"Cena: "<<ovaa.cena<<endl;
		}
};
class Biblioteka{
	private:
	public:
		void izlistajknigi();
};
void Biblioteka::izlistajknigi(){
	string naslov,avtori,izdavach,isbn;
	int godina;
	double cena;
	string vlez;
	
	Kniga knigi[100];
	ifstream datoteka("Biblioteka1.dat");
	if(!datoteka){
		cout<<"Nema datoteka"<<endl;
		exit(1);
	}
	
	int i=-1;
	while(true){
		i++;
		getline(datoteka,naslov);
		if(naslov=="KRAJ")
		break;
		getline(datoteka,avtori);
		getline(datoteka,izdavach);
		getline(datoteka,vlez);
		godina=stoi(vlez);
		getline(datoteka,isbn);
		getline(datoteka,vlez);
		cena=stod(vlez);
		knigi[i]={naslov,avtori,izdavach,godina,isbn,cena};
		
	}
	datoteka.close();
	int brojknigi=i;
	
	cout<<"KNIGI VO BIBLIOTEKATA"<<endl;
	for(int i=0;i<brojknigi;i++){
		cout<<"\nKniga"<<i+1<<":";
		knigi[i].prikazhikniga(knigi[i]);
	}
}
int main(){
	Biblioteka moja;
	moja.izlistajknigi();
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}


















