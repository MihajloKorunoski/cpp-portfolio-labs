#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Prodavach{
		static const int nedeli=4;
	private:
		string imeiprezime;
		double nedelnaprodazhba[nedeli];
	public:
		Prodavach();
		Prodavach(string,double[]);
		void postaviprodazhba(string, double[]);
		double mesechnaprodazhba();
		void listanaprodavachi(Prodavach[],int);
		void prikazhiprodavach();
};

Prodavach::Prodavach(){
	imeiprezime="";
	for(int i=0;i<nedeli;i++){
		nedelnaprodazhba[i]=0.0;
	}
}
Prodavach::Prodavach(string imeiprezime,double nedelnaprodazhba[]){
	postaviprodazhba(imeiprezime,nedelnaprodazhba);
}
void Prodavach::postaviprodazhba(string imeiprezime,double nedelnaprodazhba[]){
	this->imeiprezime=imeiprezime;
	for(int i=0;i<nedeli;i++){
		this->nedelnaprodazhba[i]=nedelnaprodazhba[i];
	}
}
double Prodavach::mesechnaprodazhba(){
	double vkupno=0.0;
	for (int i=0;i<nedeli;i++)
		vkupno+=nedelnaprodazhba[i];
	return vkupno;
}

void Prodavach::listanaprodavachi(Prodavach prodavachi[], int brojnaprodavachi){
	cout<<fixed<<setprecision(2)<<endl;
	cout<<setw(45)<<"PRODAZHBA"<<endl<<endl;
	cout<<left<<setw(5)<<" "<<setw(20)<<"Prodavach"<<right;
	for(int i=0; i<nedeli;i++){
		cout<<setw(8)<<"Nedela"<<setw(2)<<i+1;
	}
	cout<<setw(10)<<"Vkupno"<<endl;
	cout<<"_________________________________________________________________________________"<<endl;
	double vkupnomesechno=0;
	for (int i=0;i<brojnaprodavachi;i++){
		prodavachi[i].prikazhiprodavach();
		vkupnomesechno+=prodavachi[i].mesechnaprodazhba();
	}
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<setw(65)<<"Vkupna mesechna prodazhba:"<<setw(10)<<vkupnomesechno;
}
void Prodavach::prikazhiprodavach(){
	cout<<left<<setw(25)<<imeiprezime;
	cout<<right;
	for(int i=0;i<nedeli;i++){
		cout<<setw(10)<<nedelnaprodazhba[i];
	}
	cout<<setw(10)<<mesechnaprodazhba()<<endl;
} 
int main(){
	string imeiprezime;
	const int brojnanedeli=4;
	const int brojnaprodavachi=2;
	
	Prodavach prodavachi[brojnaprodavachi];
	
	double nedelnaprodazhba0[]={12.3,45.6,78.9,100.0};
	prodavachi[0]={"Emily Miller", nedelnaprodazhba0};
	
	double nedelnaprodazhba1[]={34.5,45.6,90.9,230.0};
	prodavachi[1]={"Jake Miller", nedelnaprodazhba1};
	
	Prodavach jas;
	jas.listanaprodavachi(prodavachi,brojnaprodavachi);
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
























