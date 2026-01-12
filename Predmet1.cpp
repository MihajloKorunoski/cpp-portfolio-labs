#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Predmet{
	private:
		string uchilishte;
		string kod;
		string ime;
	public:
		Predmet();
		Predmet(string,string);
		Predmet(string,string,string);
		void postaviuchilishte(string);
		string zemiuchilishte();
		void postavipredmet(string);
		string zemipredmet();
		void postavikod(string);
		string zemikod();
		void vnesuvanjepodatoci(Predmet [], int&);
		void listanapredmeti(Predmet[], int);
		void prikazhipredmet();
};
Predmet::Predmet(){}
Predmet::Predmet(string kod,string ime){
	this->kod=kod;
	this->ime=ime;
}
Predmet::Predmet(string uchilishte,string kod, string ime){
	this->uchilishte=uchilishte;
	this->kod=kod;
	this->ime=ime;
}
void Predmet::postaviuchilishte(string uchlishte){
	this->uchilishte=uchilishte;
}
string Predmet::zemiuchilishte(){
	return uchilishte;
}
void Predmet::postavipredmet(string ime){
	this->ime=ime;
}
string Predmet::zemipredmet(){
	return ime;
}
void Predmet::postavikod(string kod){
	this->kod=kod;
}
string Predmet::zemikod(){
	return kod;
}
void Predmet::vnesuvanjepodatoci(Predmet predmeti [], int &brojnapredmeti){
	cout<<"Vnesete go uchilishteto: ";
	getline(cin, uchilishte);
	cout<<endl<<"Vnesete gi predmetite."<<endl;
	cout<<"Za kraj vnesete 99999 za kod na predmet."<<endl;
	int i=0;
	while(true){
		i++;
		cout<<endl<<"Kod na predmet:";
		getline(cin,kod);
		if(kod=="99999")
			break;
		cout<<"Ime na predmet: ";
		getline(cin,ime);
		predmeti[i]={kod,ime};
	}
	brojnapredmeti=i-1;
}
void Predmet::listanapredmeti(Predmet predmeti[],int brojnapredmeti){
	system("cls");
	cout<<endl<<"\tPREDMETI VO UCHILISHTETO \n\t"<<uchilishte<<endl<<endl;
	cout<<left<<setw(5)<<""<<setw(10)<<"Kod"<<setw (30)<<"Predmet "<<endl<<endl;
	for(int i=1;i<=brojnapredmeti;i++){
		cout<<right<<setw(2)<<i<<".  "<<left;
		cout<<setw(10)<<predmeti[i].zemikod();
		cout<<setw(30)<<predmeti[i].zemipredmet();
		cout<<endl;
	}
}
void Predmet::prikazhipredmet(){
	cout<<endl<<"Uchilishte \t\t"<<zemiuchilishte()<<endl<<"Kod na predmet: \t"<<zemikod()<<endl<<"Predmet: \t\t"<<zemipredmet();
}
int main(){
	int brojnapredmeti;
	Predmet predmeti[100];
	Predmet nekoj;
	nekoj.vnesuvanjepodatoci(predmeti,brojnapredmeti);
	nekoj.listanapredmeti(predmeti,brojnapredmeti);
	cout<<endl;
	system("PAUSE");
	return 0;
}






















