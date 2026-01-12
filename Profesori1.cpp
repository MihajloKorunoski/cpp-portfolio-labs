#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Profesor{
	private:
		string ime;
		string prezime;
		string zvanje;
	public:
		Profesor();
		Profesor(string,string,string);
		string zemiime();
		string zemiprezime();
		string zemizvanje();
		void prikazhiprofesor();
};
Profesor::Profesor(){
}
Profesor::Profesor(string ime, string prezime, string zvanje){
	this->ime=ime;
	this->prezime=prezime;
	this->zvanje=zvanje;
}
string Profesor::zemiime(){
	return ime;
}
string Profesor::zemiprezime(){
	return prezime;
}
string Profesor::zemizvanje(){
	return zvanje;
}
void Profesor::prikazhiprofesor(){
	cout<<endl<<"Ime na profesor: \t"<<zemiime()<<endl<<"Prezimeme na profesor: \t"<<zemiprezime()<<endl<<"Zvanje na profesor: \t"<<zemizvanje();
}
int main(){
	string ime;
	string prezime;
	string zvanje;
	cout<<"Vnesete gi profesorite:"<<endl;
	cout<<"Za kraj vnesete 9999 za ime na profesor."<<endl;
	Profesor profesori[100];
	int i=0;
	while(true){
		i++;
		cout<<endl<<"Ime na profesor: ";
		getline(cin,ime);
		if(ime=="9999"){
			break;
		}
		cout<<"Prezime na profesor: ";
		getline(cin, prezime);
		cout<<"Zvanje na profesor: ";
		getline(cin,zvanje);
		profesori[i]={ime,prezime,zvanje};
	}
	int brojnaprofesori=i-1;
	system("cls");
	cout<<endl<<"\tLista na profesori"<<endl<<endl;
	for(int i=1; i<=brojnaprofesori;i++){
		cout<<setw(2)<<i<<". ";
		cout<<profesori[i].zemiime();
		cout<<" ";
		cout<<profesori[i].zemiprezime();
		cout<<" ";
		cout<<profesori[i].zemizvanje();
		cout<<endl;
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}




























