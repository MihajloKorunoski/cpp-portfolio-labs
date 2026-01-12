#include<iostream>
using namespace std;

class Datum{
		friend void razlikanadatumi(Datum,Datum,int&,int&,int&);
	private:
		int den,mesec,godina;
	public:
		Datum();
		Datum(int,int,int);
		void prikazhiobjekt(int,int,int);
};

Datum::Datum(){
}
Datum::Datum(int denes,int ovojmesec,int ovaagodina){
	den=denes;
	mesec=ovojmesec;
	godina=ovaagodina;
}
void Datum::prikazhiobjekt(int den,int mesec,int godina){
	cout<<den<<"."<<mesec<<"."<<godina<<endl;
}
void razlikanadatumi(Datum rodenden,Datum denes,int &denovi,int &meseci,int &godini){
	denovi=denes.den-rodenden.den;
	if(denovi<0){
		denovi+=30;
		denes.mesec-=1;
	}
	meseci=denes.mesec-rodenden.mesec;
	if(meseci<0){
		meseci+=12;
		denes.godina-=1;
	}
	godini=denes.godina-rodenden.godina;
}
int main(){
	int den,mesec,godina;
	cout<<"Vnesete rodenden:\n";
	cout<<"Den: ";
	cin>>den;
	cout<<"Mesec: ";
	cin>>mesec;
	cout<<"Godina: ";
	cin>>godina;
	
	Datum rodenden(den,mesec,godina);
	
	cout<<"\nVnesete go deneshniot datum:\n";
	cout<<"Den: ";
	cin>>den;
	cout<<"Mesec: ";
	cin>>mesec;
	cout<<"Godina: ";
	cin>>godina;
	
	Datum denes(den,mesec,godina);
	
	int denovi,meseci,godini;
	razlikanadatumi(rodenden,denes,denovi,meseci,godini);
	cout<<"\nVashata vozrast e: "<<godini<<" godini, "<<meseci<<" meseci i"<<denovi<<" denovi."<<endl;
	cout<<endl;
	return 0;
}
