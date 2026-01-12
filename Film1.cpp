#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Film{
	private:
		string naslov;
		string rezhiser;
		string zhanr;
		int godina;
	public:
		Film();
		Film(string,string, string, int );
		void postavifilm(string,string,string,int);
		void zemifilm(string&,string&,string&,int&);
		void prikazhifilm();
};

Film::Film(){
	naslov=rezhiser=zhanr="";
	godina=1900;
}

Film::Film(string naslov,string rezhiser,string zhanr,int godina){
	postavifilm(naslov,rezhiser,zhanr,godina);
}

void Film::postavifilm(string naslov,string rezhiser,string zhanr,int godina){
	this->naslov=naslov;
	this->rezhiser=rezhiser;
	this->zhanr=zhanr;
	this->godina=godina;
}
void Film::zemifilm(string &naslov,string &rezhiser,string &zhanr, int &godina){
	naslov=this->naslov;
	rezhiser=this->rezhiser;
	zhanr=this->zhanr;
	godina=this->godina;
}
void Film::prikazhifilm(){
	cout<<left;
	cout<<setw(30)<<naslov<<setw(20)<<rezhiser<<setw(10)<<zhanr<<right<<setw(10)<<godina<<endl;
}
void listanafilmovi(Film filmovi[],int brojfilmovi){
	cout<<left;
	cout<<setw(10)<<" "<<setw(20)<<"Naslov"<<setw(20)<<"Rezhiser"<<setw(10)<<"Zhanr"<<right<<setw(10)<<"Godina"<<endl;
	cout<<"_________________________________________________________________________________"<<endl;
	for(int i=0;i<brojfilmovi;i++)
	filmovi[i].prikazhifilm();
}
int main(){
	string naslov,rezhiser,zhanr;
	string vlez;
	int godina;
	const int brojfilmovi=2;
	Film filmovi[brojfilmovi];
	for (int i=0; i<brojfilmovi;i++){
		cout<<"Film "<<i+1<<":"<<endl;
		cout<<left;
		cout<<setw(10)<<"Naslov: ";
		getline(cin,naslov);
		cout<<setw(10)<<"Rezhiser: ";
		getline(cin,rezhiser);
		cout<<setw(10)<<"Zhanr: ";
		getline(cin,zhanr);
		cout<<setw(10)<<"Godina: ";
		getline(cin,vlez);
		godina=stoi(vlez);
		filmovi[i]={naslov,rezhiser,zhanr,godina};
	}
	system("CLS");
	
	listanafilmovi(filmovi,brojfilmovi);
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}






























