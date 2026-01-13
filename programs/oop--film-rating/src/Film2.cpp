#include<iostream>
#include<cstring>
using namespace std;

class Film{
	private:
		char ime[100];
		char rezhiser[50];
		char zhanr[50];
		int godina;
	public:
		Film(){
		}
		Film(char* ime, char* rezhiser, char* zhanr, int godina){
			strcpy(this->ime,ime);
			strcpy(this->rezhiser,rezhiser);
			strcpy(this->zhanr,zhanr);
			this->godina=godina;
		}
		void pechatiInformacijazaFilm(){
			cout<<"Ime: "<<ime<<endl;
			cout<<"Rezhiser:"<<rezhiser<<endl;
			cout<<"Zhanr: "<<zhanr<<endl;
			cout<<"Godina: "<<godina<<endl;
		}
		int getgodina(){
			return godina;
		}
};
void pechati_po_godina(Film *f,int n, int godina){
	for(int i=0;i<n;i++){
		if(f[i].getgodina()==godina){
			f[i].pechatiInformacijazaFilm();
		}
	}
}
int main(){
	int n;
	cin>>n;
	Film f[100];
	for (int i=0; i<n; ++i){
		char ime[100];
		char rezhiser[50];
		char zhanr[50];
		int godina;
		cin>>ime;
		cin>>rezhiser;
		cin>>zhanr;
		cin>>godina;
		f[i]={ime,rezhiser,zhanr,godina};
	}
	int godina;
	cin>>godina;
	pechati_po_godina(f,n,godina);
	return 0;
}
