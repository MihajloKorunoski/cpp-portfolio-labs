#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string vozrast(string,string,char);

class Kontakt{
		friend string vozrast(string,string,char);
	private:
		string imeiprezime;
		long long telefon;
		string imeil;
		string rodenden;
		char era;
	public:
		Kontakt();
		Kontakt(string,long long,string,string,char);
		void postavikontakt(string,long long,string, string, char);
		void zemikontakt(string&, long long&, string&, string&, char&);
		void listanakontakti(Kontakt[],int,string);
		void prikazhikontakt();
};
Kontakt::Kontakt(){
	imeiprezime=imeil=rodenden="";
	telefon=0;
	era=' ';
}

Kontakt::Kontakt(string imeiprezime,long long telefon, string imeil, string rodenden, char era){
	postavikontakt(imeiprezime,telefon,imeil,rodenden,era);
}
void Kontakt::postavikontakt(string imeiprezime,long long telefon,string imeil,string rodenden, char era){
	this->imeiprezime=imeiprezime;
	this->telefon=telefon;
	this->imeil=imeil;
	this->rodenden=rodenden;
	this->era=era;
}
void Kontakt::zemikontakt(string &imeiprezime, long long &telefon, string &imeil, string &rodenden, char &era){
	imeiprezime=this->imeiprezime;
	telefon=this->telefon;
	imeil=this->imeil;
	rodenden=this->rodenden;
	era=this->era;
}
void Kontakt::listanakontakti(Kontakt kontakti [], int brojkontakti, string denes){
	cout<<left;
	cout<<setw(22)<<"Ime i prezime"<<setw(11)<<"Telefon"<<setw(27)<<"e-mail"<<setw(11)<<"Rodenden"<<setw(15)<<"Vozrast"<<endl;
	cout<<"Denes: "<<denes<<endl<<endl;
	for(int i=0;i<brojkontakti;i++){
		kontakti[i].prikazhikontakt();
		cout<<setw(12)<<vozrast(denes,kontakti[i].rodenden,kontakti[i].era)<<endl;
	}
	
}
void Kontakt::prikazhikontakt(){
		cout<<setw(22)<<imeiprezime<<setw(7)<<telefon<<setw(30)<<imeil<<setw(11)<<rodenden;
	}
	string vozrast(string denes,string rodenden, char era){
		int znak=-1;
		if(era=='p')
			znak=1;
		int denovi=stoi(denes.substr(0,2))+znak*stoi(rodenden.substr(0,2));
		int meseci=stoi(denes.substr(3,2))+znak*stoi(rodenden.substr(3,2));
		int godini=stoi(denes.substr(6,4))+znak*stoi(rodenden.substr(6,4));
		if (denovi<0){
			denovi+=30;
			meseci-=1;
		}
		if (denovi>29){
			denovi-=30;
			meseci+=1;
		}
		if(meseci<0){
			meseci+=12;
			godini-=1;
		}
		if(meseci>11){
			meseci-=12;
			godini+=1;
		}
		string dmg=to_string(godini)+"."+to_string(meseci)+"."+to_string(denovi);
		if((meseci==0)&&(denovi==0))
			dmg=to_string(godini+1)+"-ti";
		return dmg;
	}
	int main(){
		string imeiprezime,imeil,rodenden;
		long long telefon;
		const int brojkontakti=5;
		Kontakt kontakti[brojkontakti];
		kontakti[0]={"Ethan Miller", 389001, "e.miller@makedonija.mk","22.07.0356",'p'};
		kontakti[1]={"Car Samoil", 389002, "car.samoil@makedonija.mk","01.01.0958",'n'};
		kontakti[2]={"Ryan Reed",389003, "ryan.reed@makedonija.mk","23.11.1877",'n'};
		kontakti[3]={"Metodija Andonov",389004,"metodija.andonov@makedonija.mk","17.08.1902",'n'};
		kontakti[4]={"Kiro Gligorov",389005,"kirogligorov@makedonija.mk","03.05.1917",'n'};
		
		string denes;
		cout<<"Vnesete go deneshniot datum vo string \"dd.mm.gggg\" : ";
		cin>>denes;
		system("cls");
		Kontakt jas;
		jas.listanakontakti(kontakti,brojkontakti,denes);
		
		cout<<endl;
		system("PAUSE");
		return 0;
		
	}




























