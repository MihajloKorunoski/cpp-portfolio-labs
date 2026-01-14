#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Kniga {
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
		Kniga(string naslov, string avtori,string izdavach, int godina, string isbn, double cena){
			postavikniga(naslov,avtori,izdavach,godina,isbn,cena);
		}
		void postavikniga(string naslov,string avtori,string izdavach, int godina, string isbn,double cena){
			this->naslov=naslov;
			this->avtori=avtori;
			this->izdavach=izdavach;
			this->godina=godina;
			this->isbn=isbn;
			this->cena=cena;
		}
		void zemikniga(string &naslov,string &avtori,string &izdavach, int &godina, string &isbn,double &cena){
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
int main(){
	const int brojknigi=2;
	Kniga knigi[brojknigi];
	knigi[0]={"C++ Osnovi na programiranje","Tyler Johnson,Hannah Anderson, Claire Peterson", "GOCMAR",2007,"ISBN-10:9989-684-48-0",234.5};
	knigi[1]={"C++ Objektno programiranje","Tyler Johnson","GOCMAR",2017,"ISBN-13:987-9989-684-63-0",345.5};
	cout<<"KNIGI"<<endl;
	for(int i=0;i<brojknigi;i++){
		cout<<endl<<"Kniga"<<i+1<<":";
		knigi[i].prikazhikniga(knigi[i]);
	}
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}




















