#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Lice{
	private:
		string ime;
		string prezime;
		long long matichenBroj;
	public:
		Lice(){
			ime=" ";
			prezime="";
			matichenBroj=0;
		}
		Lice(string ime, string prezime, long long matichenBroj){
			postaviLice(ime,prezime,matichenBroj);
		}
		void postaviLice(string ime, string prezime, long long matichenBroj){
			this->ime=ime;
			this->prezime=prezime;
			this->matichenBroj=matichenBroj;
		}
		string zemiIme(){
			return ime;
		}
		string zemiPrezime(){
			return prezime;
		}
		long long zemiMatichenBroj(){
			return matichenBroj;
		}
		void listaNaLica(Lice lica[], int brojNaLica){
			cout<<left<<setw(8)<<""<<left<<setw(15)<<"Prezime"<<left<<setw(15)<<"Ime"<<left<<setw(15)<<"Matichen broj "<<endl<<endl;
			for(int i=0; i<brojNaLica; i++){
				cout<<"Lice "<<i+1<<": ";
				lica[i].prikazhiLice();
			}
		}
		void sortiranjeLista(Lice lica[], int brojNaLica){
			Lice pom;
			int brojach=1;
			do{
				for(int i=brojNaLica-1; i>=brojach; i--){
					if(lica[i].prezime<lica[i-1].prezime){
						pom=lica[i];
						lica[i]=lica[i-1];
						lica[i-1]=pom;
					}
				}
				brojach++;
			} while(brojach<brojNaLica);
		}
		void prikazhiLice(){
			cout<<left<<setw(15)<<zemiPrezime()<<left<<setw(15)<<zemiIme()<<left<<setw(15)<<zemiMatichenBroj()<<endl;
		}
};
int main(){
	string ime;
	string prezime;
	long long matichenBroj;
	string vlez;
	cout<<"Vnesete gi licata"<<endl;
	cout<<"Za kraj vnesete 9999 za ime na lice"<<endl;
	Lice lica[100];
	int i= -1;
	while(true){
		i++;
		cout<<left<<setw(16)<<endl<<" Ime: ";
		getline(cin,ime);
		if(ime=="9999")
			break;
		cout<<left<<setw(16)<<" Prezime: ";
		getline(cin,prezime);
		cout<<left<<setw(16)<<" Matichen broj: ";
		getline(cin,vlez);
		matichenBroj=stoll(vlez);
		lica[i]={ime,prezime,matichenBroj};
	}
	int brojNaLica=i;
	
	system("cls");
	
	Lice nekoe;
	cout<<endl<<"\t\t NE SORTIRANA LISTA"<<endl;
	nekoe.listaNaLica(lica,brojNaLica);
	
	nekoe.sortiranjeLista(lica,brojNaLica);
	
	cout<<endl<<"\t\t SORTIRANA LISTA"<<endl;
	nekoe.listaNaLica(lica,brojNaLica);
	
	cout<<endl;
	system("PAUSE");
	return 0;
}































