#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Kontakt{
	private:
		string imeiprezime;
		long long telefon;
		string imeil;
		string rodenden;
	public:
		Kontakt();
		Kontakt(string,long long, string, string){
			postavikontakt(imeiprezime,telefon,imeil,rodenden);
		}
		void postavikontakt(string, long long, string, string);
		void zemikontakt(string&, long long&, string&, string&);
		void listanakontakti(Kontakt[],int,string);
		void prikazhikontakt();
};
Kontakt::Kontakt(){
	imeiprezime=imeil=rodenden="";
	telefon=0;
}
void Kontakt::postavikontakt(string imeiprezime,long long telefon,string imeil, string rodenden){
	this->imeiprezime=imeiprezime;
	this->telefon=telefon;
	this->imeil=imeil;
	this->rodenden=rodenden;
}
void Kontakt::zemikontakt(string &imeiprezime, long long &telefon, string &imeil, string &rodenden){
	imeiprezime=this->imeiprezime;
	telefon=this->telefon;
	imeil=this->imeil;
	rodenden=this->rodenden;
}
void Kontakt::listanakontakti(Kontakt kontakti[],int brojkontakti,string denes){
	cout<<left;
	cout<<setw(22)<<"Ime i Prezime"<<setw(21)<<"Telefon"<<setw(27)<<"e-mail"<<setw(11)<<"Rodenden"<<endl<<endl;
	for(int i=0;i<brojkontakti;i++){
		kontakti[i].prikazhikontakt();
	}
	string denmesecdenes=denes.substr(0,5);
	string denmesecrodenden;
	cout<<endl<<"Denes "<<denes<<" imaat rodenden:"<<endl;
	for(int i=0;i<brojkontakti;i++){
		denmesecrodenden=(kontakti[i].rodenden).substr(0,5);
		if(denmesecrodenden.compare(denmesecdenes)==0)
		{
			cout<<"\t"<<kontakti[i].imeiprezime<<endl;
		}
	}
}
void Kontakt::prikazhikontakt(){
	cout<<setw(22)<<imeiprezime<<setw(21)<<telefon<<setw(27)<<imeil<<setw(11)<<rodenden;
}
int main(){
	string imeiprezime,imeil,rodenden;
	long long telefon;
	Kontakt kontakti[100];
	string vlez;
	cout<<"Vnesete podatoci za kontaktite."<<endl;
	cout<<"Za kraj vnesete 9999 za ime i prezime"<<endl;
	int i=-9;
	while(true){
		i++;
		cout<<left<<setw(25)<<endl<<"Ime i prezime";
		getline(cin,imeiprezime);
		if(imeiprezime=="9999"){
			break;
		}
		cout<<left<<setw(25)<<" Telefon:";
		getline(cin,vlez); telefon=stoll(vlez);
		cout<<left<<setw(25)<<" E-mail:";
		getline(cin,imeil);
		cout<<left<<setw(25)<<" Rodenden(dd.mm.gggg):";
		getline(cin,rodenden);
		kontakti[i]={imeiprezime,telefon,imeil,rodenden};	
	}
	int brojkontakti=i;
	string denes;
	cout<<"Vnesete go denesniot datum vo string \"dd.mm.gggg\" : ";
	cin>>denes;
	system("cls");
	Kontakt jas;
	jas.listanakontakti(kontakti,brojkontakti,denes);
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}




























