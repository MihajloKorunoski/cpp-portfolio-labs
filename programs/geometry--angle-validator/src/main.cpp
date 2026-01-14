#include<iostream>
using namespace std;
class Agol {
	private:
		int stepeni;
		int minuti;
		int sekundi;
	public:
		Agol();
		Agol(int,int,int);
		~Agol();
		void postaviStepeni(int);
		void postaviMinuti(int);
		void postaviSekundi(int);
		int zemiStepeni();
		int zemiMinuti();
		int zemiSekundi();
		void prikazhiAgol();
};
Agol::Agol() {
	stepeni=minuti=sekundi=0;
}
Agol::Agol(int stepeni, int minuti, int sekundi){
	postaviStepeni(stepeni);
	postaviMinuti(minuti);
	postaviSekundi(sekundi);
}
Agol::~Agol(){
}
void Agol::postaviStepeni(int stepeni){
	this->stepeni=stepeni;
}
void Agol::postaviMinuti(int minuti){
	this->minuti=minuti;
}
void Agol::postaviSekundi(int sekundi){
	this->sekundi=sekundi;
}
int Agol::zemiStepeni(){
	return stepeni;
}
int Agol::zemiMinuti(){
	return minuti;
}
int Agol::zemiSekundi(){
	return sekundi;
}
bool proveriAgol(int stepeni, int minuti, int sekundi){
	if(((0<=minuti)&&(minuti<60))&&((0<=sekundi)&&(sekundi<60)))
		return true;
	else
		return false;
}
void Agol::prikazhiAgol(){
	cout<<endl<<"Agol: "<<stepeni<<"*"<<minuti<<"'"<<sekundi<<"\""<<endl;
}
int main(){
	int stepeni, minuti, sekundi;
	bool tochno;
	Agol alfa;
	do{
		cout<<"Vnesete agol:"<<endl;
		cout<<"Stepeni: ";
		cin>>stepeni;
		cout<<"Minuti: ";
		cin>>minuti;
		cout<<"Sekundi: ";
		cin>>sekundi;
		tochno=proveriAgol(stepeni,minuti,sekundi);
		if(tochno)
			alfa={stepeni,minuti,sekundi};
		else
			cout<<endl<<"Pogreshni podatoci. Obidete se povtorno."<<endl;
	} while(!tochno);
	alfa.prikazhiAgol();
	cout<<endl;
	system("PAUSE");
	return 0;
}















