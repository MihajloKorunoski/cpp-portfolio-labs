#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Produkt{
	private:
		string produkt;
		double cena;
		double kolichina;
	public:
		Produkt();
		Produkt(string, double, double);
		void postaviprodukt(string,double,double);
		void zemiprodukt(string&,double&,double&);
		void prikazhiprodukt();
		friend void listanaprodukti(Produkt[],int);
};
Produkt::Produkt(){
	produkt="";
	cena=kolichina=0;
}
Produkt::Produkt(string produkt,double cena, double kolichina){
	postaviprodukt(produkt,cena,kolichina);
}
void Produkt::postaviprodukt(string produkt, double cena, double kolichina){
	this->produkt=produkt;
	this->cena=cena;
	this->kolichina=kolichina;
}

void Produkt::zemiprodukt(string& produkt, double& cena, double& kolichina){
	produkt=this->produkt;
	cena=this->cena;
	kolichina=this->kolichina;
}

void Produkt::prikazhiprodukt(){
	cout<<left;
	cout<<setw(30)<<produkt<<right<<setw(10)<<cena<<setw(10)<<kolichina<<setw(10)<<cena*kolichina<<endl;
}

void listanaprodukti(Produkt produkti[],int brojprodukti){
	cout<<left<<setw(10)<<" "<<right<<setw(10)<<"Produkt"<<setw(20)<<"Cena"<<setw(10)<<"Kolichina"<<right<<setw(10)<<"Vkupno"<<endl;
	cout<<"_________________________________________________________________________________"<<endl;
	string produkt;
	double cena,kolichina;
	double vkupno=0;
	for (int i=0; i<brojprodukti;i++){
		produkti[i].zemiprodukt(produkt,cena,kolichina);
		produkti[i].prikazhiprodukt();
		vkupno+=cena*kolichina;
	}
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<setw(50)<<"Vkupno plateno: "<<setw(10)<<vkupno<<endl;
}
int main(){
	string produkt;
	double cena,kolichina;
	string pom;
	const int brojprodukti=2;
	Produkt produkti[brojprodukti];
	
	for(int i=0;i<brojprodukti; ++i){
		cout<<"Produkt "<<i+1<<":"<<endl;
		cout<<left;
		cout<<setw(10)<<" Ime:";
		getline(cin,produkt);
		cout<<setw(10)<<" Cena:";
		getline(cin,pom);
		cena=stod(pom);
		cout<<setw(10)<<" Kolichina:";
		getline(cin,pom);
		kolichina=stod(pom);
		produkti[i]={produkt,cena,kolichina};
	}
	system("cls");
	
	listanaprodukti(produkti,brojprodukti);
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
























