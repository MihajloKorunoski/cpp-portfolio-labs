#include<iostream>
using namespace std;
class Datum{
		friend Datum operator-(Datum,Datum);
	private:
		int den,mesec,godina;
	public:
		Datum();
		Datum(int,int,int);
		void postavidatum(int,int,int);
		void zemidatum(int&,int&,int&);
		Datum vozrast(Datum,Datum);
		void prikazhidatum(Datum);
		Datum operator/(const Datum&);
};
Datum::Datum(){
	den=mesec=godina=0;
}
Datum::Datum(int den,int mesec, int godina){
	postavidatum(den,mesec,godina);
}
void Datum::postavidatum(int den, int mesec,int godina){
	this->den=den;
	this->mesec=mesec;
	this->godina=godina;
}
void Datum::zemidatum(int &den, int &mesec,int &godina){
	den=this->den;
	mesec=this->mesec;
	godina=this->godina;
}
void Datum::prikazhidatum(Datum dmg){
	cout<<dmg.den<<"."<<dmg.mesec<<"."<<dmg.godina<<endl;
}
Datum Datum::operator/(const Datum& rodenden){
	Datum vozrast;
	vozrast.den=this->den-rodenden.den;
	if(vozrast.den<0){
		vozrast.den+=30;
		this->mesec-=1;
	}
	vozrast.mesec=this->mesec-rodenden.mesec;
	if(vozrast.mesec<0){
		vozrast.mesec+=12;
		this->godina-=1;
	}
	vozrast.godina=this->godina-rodenden.godina;
	return vozrast;
}
Datum operator-(Datum denes,Datum rodenden){
	Datum vozrast;
	vozrast.den=denes.den-rodenden.den;
	if(vozrast.den<0){
		vozrast.den+=30;
		denes.mesec-=1;
	}
	vozrast.mesec=denes.mesec-rodenden.mesec;
	if(vozrast.mesec<0){
		vozrast.mesec+=12;
		denes.godina-=1;
	}
	vozrast.godina=denes.godina-rodenden.godina;
	return vozrast;
}
Datum Datum::vozrast(Datum rodenden, Datum denes){
	Datum vozrast;
	vozrast.den=denes.den-rodenden.den;
	if(vozrast.den<0){
		vozrast.den+=30;
		vozrast.mesec-=1;
	}
	vozrast.mesec=denes.mesec-rodenden.mesec;
	if(vozrast.mesec<0){
		vozrast.mesec+=12;
		vozrast.godina-=1;
	}
	vozrast.godina=denes.godina-rodenden.godina;
	return vozrast;
}
int main(){
	int den,mesec,godina;
	cout<<"Vnesete go rodendenot:"<<endl;
	cout<<"Den: ";
	cin>>den;
	cout<<"Mesec:";
	cin>>mesec;
	cout<<"Godina:";
	cin>>godina;
	
	Datum rodenden(den,mesec,godina);
	cout<<"Vnesete go deneshniot datum:"<<endl;
	cout<<"Den: ";
	cin>>den;
	cout<<"Mesec:";
	cin>>mesec;
	cout<<"Godina:";
	cin>>godina;
	
	Datum denes(den,mesec,godina);
	Datum golem= denes-rodenden; // so edniot
	golem= denes/rodenden; // so drugiot
	cout<<"Vie ste na vozrast od ";
	golem.prikazhidatum(golem);
	cout<<endl;
	system("Pause");
	return 0;
}
