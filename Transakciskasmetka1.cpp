#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
using namespace std;

class transakciskasmetka{
	private:
		string sopstvenik;
		string banka;
		long long brojsmetka;
	public:
		transakciskasmetka(){
			sopstvenik="";
			banka="";
			brojsmetka=0;
		}
		transakciskasmetka(string sopstvenik,string banka, long long brojsmetka){
			postavitransakciskasmetka(sopstvenik,banka,brojsmetka);
		}
		void postavitransakciskasmetka(string sopstvenik,string banka, long long brojsmetka){
			this->sopstvenik=sopstvenik;
			this->banka=banka;
			this->brojsmetka=brojsmetka;
		}
		double uplata(){
			double uplata;
			string pom;
			cout<<"Kolku pari uplakjate?:";
			getline(cin,pom); uplata= stod(pom);
			return uplata;
		}
		double isplata(){
			double isplata;
			string pom;
			cout<<"Kolku pari podignuvate?";
			getline(cin,pom);
			isplata=stod(pom);
			return isplata;
		}
		void transakcija(transakciskasmetka &s, double& saldo, ofstream &datoteka){
			cout<<endl<<"Uplakjate ili podignuvate pari? (U-uplata, I-isplata): ";
			string dane,pom;
			getline(cin,dane);
			double uplata=0, isplata=0;
			if(dane.compare("U")==0){
				uplata=s.uplata();
				saldo+=uplata;
			}
			if(dane.compare("I")==0){
				isplata=s.isplata();
				saldo-=isplata;
			}
			SYSTEMTIME LocalTime;
			GetLocalTime(&LocalTime);
			string datum=to_string(LocalTime.wDay)+"."+to_string(LocalTime.wMonth)+"."+to_string(LocalTime.wYear);
			string vreme=to_string(LocalTime.wHour)+":"+to_string(LocalTime.wMinute)+":"+to_string(LocalTime.wSecond);
			datoteka<<endl;
			datoteka<<datum<<" "<<vreme<<" "<<uplata<<" "<<isplata<<" "<<saldo;
		}
		void kreiranjedatoteka(transakciskasmetka moja){
			double pochetnosaldo;
			string pom;
			cout<<endl<<"Kreiranje datoteka"<<endl;
			cout<<"Pochetno saldo: ";
			cin>>pochetnosaldo;
			getline(cin,pom);
			string imenadatoteka;
			cout<<"Vnesete ime na datotekata:";
			cin>>imenadatoteka;
			ofstream datoteka(imenadatoteka);
			datoteka<<pochetnosaldo;
			while(true){
				cout<<endl<<"Za kraj vnesete K, intaku pritisnete Enter: ";
				if(cin.get()=='\n')
					moja.transakcija(moja,pochetnosaldo,datoteka);
				else
					break;
			}
			datoteka.close();
		}
		void prikazhismetka(transakciskasmetka moja){
			cout<<endl;
			cout<<setprecision(2)<<fixed;
			cout<<left<<setw(30)<<moja.sopstvenik<<setw(30)<<moja.banka<<endl<<"Smetka: "<<setw(22)<<moja.brojsmetka;
		}
};
int main(){
	string sopstvenik,banka;
	long long brojsmetka;
	string vlez;
	
	cout<<"Sopstvenik: ";
	getline(cin,sopstvenik);
	cout<<"Banka: ";
	getline(cin,banka);
	cout<<"Broj na smetka(15 Cifri): ";
	getline(cin,vlez);
	brojsmetka=stoll(vlez);
	transakciskasmetka moja(sopstvenik,banka,brojsmetka);
	
	cout<<endl<<"Dali kje kreirate transakciska datoteka? (D-da, N-ne):";
	char dane;cin>>dane;
	if(dane=='D')
		moja.kreiranjedatoteka(moja);
		
	cout<<endl<<"Prikazhuvanje na transakciskata datoteka "<<endl;
	string imenadatoteka;
	cout<<"Vnesete ime na datotekata so transakcii: ";
	cin>>imenadatoteka;
	
	ifstream datoteka(imenadatoteka);
	if(!datoteka){
		cout<<"Nema datoteka"<<endl;
		exit(1);
	}
	moja.prikazhismetka(moja);
	double saldo, pochetnosaldo;
	datoteka>>pochetnosaldo;
	cout<<"Pochetno saldo:"<<pochetnosaldo<<endl<<endl;
	cout<<left<<setw(11)<<" Datum"<<setw(10)<<"Vreme"<<setw(11)<<"Staro saldo"<<right<<setw(15)<<"Uplata"<<setw(15)<<"Isplata"<<setw(15)<<"Novo saldo"<<endl;
	cout<<"_____________________________________________________________________________________________________"<<endl;
	string datum, vreme;
	double uplata,isplata,vkupnouplata=0,vkupnoisplata=0;
	do{
		datoteka>>datum>>vreme>>uplata>>isplata>>saldo;
		vkupnouplata+=uplata;
		vkupnoisplata+=isplata;
		cout<<left<<setw(11)<<datum<<setw(10)<<vreme<<right<<setw(11)<<saldo-uplata+isplata<<setw(15)<<uplata<<setw(15)<<isplata<<setw(15)<<saldo<<endl;
	} while(!datoteka.eof());
	cout<<"_____________________________________________________________________________________________________"<<endl;
	cout<<setw(21)<<" "<<setw(11)<<pochetnosaldo<<setw(15)<<right<<vkupnouplata<<setw(15)<<vkupnoisplata<<setw(15)<<saldo<<endl;
	datoteka.close();
	cout<<endl;
	system("PAUSE");
	return 0;
}






























