#include<iostream>
#include<string>
using namespace std;

class Dmg{
	private:
		int den,mesec,godina;
	public:
		Dmg(int den=1,int mesec=1,int godina=1){
			this->den=den;
			this->mesec=mesec;
			this->godina=godina;
		}
		void zemidmg(int &den,int &mesec, int &godina){
			den=this->den;
			mesec=this->mesec;
			godina=this->godina;
		}
};

string denovi[7]={"Ponedelnik","Vtornik","Sreda","Chetvrtok","Petok","Sbota","Nedelja"};
int meseci[12]={31,28,31,30,31,30,31,31,30,31,30,31};

class Den{
		friend Den operator+(Den, int);
	private:
		string datum;
	public:
		Den(string datum=""){
			postaviden(datum);
		}
		void postaviden(string datum){
			this->datum=datum;
		}
		void zemiden(string &datum){
			datum=this->datum;
		}
		Dmg datumdenvodmg(){
			string d=datum.substr(0,2);
			string m=datum.substr(3,2);
			string g=datum.substr(6,4);
			int den=stoi(d);
			int mesec=stoi(m);
			int godina=stoi(g);
			return Dmg(den,mesec,godina);
		}
		Den datumdmgvoden(Dmg dmg){
			int den,mesec,godina;
			dmg.zemidmg(den,mesec,godina);
			string datum=to_string(den) +"."+to_string(mesec)+"."+to_string(godina);
			return Den(datum);
		}
		int redendenvonedelata(string den){
			int i=-1;
			do{
				i++;
			}while(den.compare(denovi[i])!=0);
			return i;
		}
		string prikazhiden(){
			return datum;
		}
};

Den operator+(Den denes, int denovi){
	Dmg denesdmg;
	denesdmg=denes.datumdenvodmg();
	int den,mesec,godina;
	denesdmg.zemidmg(den,mesec,godina);
	int ostatok=0;
	int itimesec;
	do{
		itimesec=mesec-1;
		ostatok=meseci[itimesec]-den;
		if(denovi<=ostatok){
			den+=denovi;
			denovi=0;
		}
		else{
			mesec=++mesec%13;
			if(mesec==1)
				godina++;
			denovi-=ostatok;
			den=0;
		}
	} while(denovi>0);
	Dmg togashdmg(den,mesec,godina);
	Den togash=togash.datumdmgvoden(togashdmg);
	return togash;
}

int main(){
	string datum;
	int plusndenovi;
	cout<<"Vnesete deneshen datum(dd.mm.gggg): ";
	cin>>datum;
	cout<<"Vnesete kolku denovi ot denes(<365): ";
	cin>>plusndenovi;
	
	Den denes(datum);
	Den togash;
	togash=denes+plusndenovi;
	
	cout<<"\nDenes et "<<denes.prikazhiden()<<", a po "<<plusndenovi<<" denovi kje bide "<<togash.prikazhiden();
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}





















