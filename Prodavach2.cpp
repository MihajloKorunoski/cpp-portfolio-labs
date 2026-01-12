#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Prodavach{
		static const int nedeli=4;
	private:
		string imeiprezime;
		double *p;
	public:
		Prodavach();
		Prodavach(string,double*);
		void postaviprodazhba(string, double*);
		double mesechnaprodazhba();
		void listanaprodavachi(Prodavach[],int);
		void prikazhiprodavach();
};

Prodavach::Prodavach(){
	imeiprezime="";
	p=nullptr;
}
Prodavach::Prodavach(string imeiprezime,double *p){
	postaviprodazhba(imeiprezime,p);
}
void Prodavach::postaviprodazhba(string imeiprezime,double *p){
	this->imeiprezime=imeiprezime;
	this->p=p;
	for(int i=0;i<nedeli;i++){
		this->p[i]=p[i];
	}
}
double Prodavach::mesechnaprodazhba(){
	double vkupno=0.0;
	for (int i=0;i<nedeli;i++)
		vkupno+=p[i];
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
		cout<<setw(10)<<p[i];
	}
	cout<<setw(10)<<mesechnaprodazhba()<<endl;
} 
int main(){
	string pom;
	const int brojnanedeli=4;
	int brojnaprodavachi;
	cout<<"Vnesete broj na prodavachi: ";
	getline(cin,pom); brojnaprodavachi=stoi(pom);
	Prodavach prodavachi[10];
	double nedelnaprodazhba[10][brojnanedeli];
	string iminja[10];
	double *p[10];
	for(int k=0; k<brojnaprodavachi;k++){
		cout<<"Vnesete ime i prezime na prodavachot: ";
		getline(cin,iminja[k]);
		cout<<"Vnesete nedelna prodazhba na prodavachot: "<<iminja[k]<<endl;
		for(int j=0;j<brojnanedeli;j++){
			cout<<"\tNedela"<<setw(2)<<j+1<<": ";
			getline(cin,pom);
			nedelnaprodazhba[k][j]=stod(pom);
		}
		cout<<*nedelnaprodazhba[k];
		p[k]=nedelnaprodazhba[k];
		prodavachi[k]={iminja[k],p[k]};
		cout<<endl;
	}
	Prodavach jas;
	jas.listanaprodavachi(prodavachi,brojnaprodavachi);
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}




















