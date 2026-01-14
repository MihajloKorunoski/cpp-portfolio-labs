#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Inventar{
	private:
		string ime;
		int inventarskibroj;
		double cena;
		int brojnaparchinja;
	public:
		Inventar(){
			ime=""; inventarskibroj=0;
			cena=0;
			brojnaparchinja=0;
		}
		Inventar(string ime, int inventarskibroj, double cena, int brojnaparchinja){
			postaviinventar(ime,inventarskibroj,cena,brojnaparchinja);
		}
		void postaviinventar(string ime,int inventarskibroj, double cena, int brojnaparchinja){
			this->ime=ime;
			this->inventarskibroj=inventarskibroj;
			this->cena=cena;
			this->brojnaparchinja=brojnaparchinja;
		}
		Inventar zemiinventar(Inventar predmeti[],int i){
			ime=predmeti[i].ime;
			inventarskibroj=predmeti[i].inventarskibroj;
			cena=predmeti[i].cena;
			brojnaparchinja=predmeti[i].brojnaparchinja;
			return Inventar(ime,inventarskibroj,cena,brojnaparchinja);
		}
		void vnesipodatoci(Inventar predmeti[],int &brojnapredmeti){
			cout<<"Vnesete gi predmetite"<<endl;
			cout<<"Za kraj vnesete ime na predmet 9999"<<endl;
			char enter;
			int i=-1;
			cout<<"\nIme na predmet: ";
			getline(cin,ime);
			while(ime!="9999"){
				i++;
				cout<<"Inventarski broj: ";
				cin>>inventarskibroj;
				cout<<"Cena \t\t: ";
				cin>>cena;
				cout<<"Broj na parchinja: ";
				cin>>brojnaparchinja;
				predmeti[i]={ime,inventarskibroj,cena,brojnaparchinja};
				
				cin.get(enter);
				cout<<"\nIme na predmet: ";
				getline(cin,ime);
			}
			brojnapredmeti=i+1;
		}
		double presmetajvrednostnainventar(Inventar predmeti[],int brojnapredmeti){
			double suma=0;
			Inventar ovoj;
			for(int i=0;i<brojnapredmeti;i++){
				ovoj=zemiinventar(predmeti,i);
				suma+=ovoj.cena*ovoj.brojnaparchinja;
			}
			return suma;
		}
		void prikazhiinvnetarskalista(Inventar predmeti[], int brojnapredmeti){
			cout<<"\n\t\t\t INVENTARSKA LISTA"<<endl;
			cout<<"\n\t\t"<<setw(5)<<"Ime"<<right<<setw(17)<<"Inv.broj"<<setw(15)<<"Cena"<<setw(12)<<"Parchinja"<<setw(12)<<"Vrednost"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
			Inventar ovoj;
			for(int i=0;i<brojnapredmeti;i++){
				cout<<"Predmet"<<i+1<<": ";
				ovoj=zemiinventar(predmeti,i);
				prikazhiinventar(ovoj);
			}
		}
		void prikazhiinventar(Inventar ovoj){
			cout<<left<<setw(15)<<ovoj.ime;
			cout<<right<<setw(10)<<ovoj.inventarskibroj;
			pechatidecimalenbroj(ovoj.cena);
			cout<<right<<setw(10)<<ovoj.brojnaparchinja;
			cout<<setw(15);
			pechatidecimalenbroj(ovoj.cena*ovoj.brojnaparchinja);
			cout<<endl;
		}
		void pechatidecimalenbroj(double broj){
			cout<<fixed<<showpoint<<setprecision(2);
			if(broj>1000){
				string brojstring=to_string(int (broj));
				int n=brojstring.length();
				string iljadi=brojstring.substr(0,n-3);
				string edinici=brojstring.substr(n-3,3);
				string dec=to_string(int(100*broj));
				n=dec.length();
				dec=dec.substr(n-2,2);
				cout<<right<<setw(8)<<iljadi<<','<<edinici<<'.'<<dec;
			}
			else
			cout<<right<<setw(15)<<broj;
		}
};
int main(){
	string ime;
	int inventarskibroj;
	double cena;
	int brojnaparchinja;
	string vlez;
	int brojnapredmeti=0;
	Inventar predmeti[100];
	Inventar nekoj;
	nekoj.vnesipodatoci(predmeti,brojnapredmeti);
	
	Inventar cel;
	cel.prikazhiinvnetarskalista(predmeti, brojnapredmeti);
	double vkupnavrednost=cel.presmetajvrednostnainventar(predmeti,brojnapredmeti);
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<setw(28)<<" "<<"Vkupnata vrednost na inventarot e:";
	cout<<fixed<<showpoint<<setprecision(2);
	cel.pechatidecimalenbroj(vkupnavrednost);
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}


























