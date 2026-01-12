#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class Shtedach{
	private:
		string banka="Nasha Banka";
		static double kamatnastapka;
		string sopstvenik;
		long long smetka;
		double depozit;
		double kapital;
	public:
		Shtedach(){
			sopstvenik=" "; smetka=0; depozit=0;
		}
		Shtedach(string sopstvenik,long long smetka, double depozit){
			postavishtedach(sopstvenik,smetka,depozit);
		}
		void postavishtedach(string sopstvenik,long long smetka, double depozit){
			this->sopstvenik=sopstvenik;
			this->smetka=smetka;
			this->depozit=depozit;
		}
		void zemishtedach(string &sopstvenik, long long &smetka, double &depozit){
			sopstvenik=this->sopstvenik;
			smetka=this->smetka;
			depozit=this->depozit;
		}
		static void postavikamatnastapka(double kstapka){
			kamatnastapka=kstapka;
		}
		double zemikamata(){
			double kamata;
			kamata=depozit*kamatnastapka/100;
			return kamata;
		}
		void prikazhishtedach(){
			cout<<"Shtedach: \t"<<sopstvenik<<endl;
			cout<<"Smetka: \t"<<smetka<<endl;
			cout<<"Kapital: \t"<<depozit<<endl;
			cout<<"Kamata: \t"<<zemikamata()<<endl;
			cout<<endl;
		}
		void prikazhishtedach(Shtedach ovaj){
			ovaj.zemishtedach(sopstvenik,smetka,kapital);
			double kamata=ovaj.zemikamata();
			cout<<setprecision(2)<<fixed;
			cout<<left<<setw(20)<<sopstvenik<<right<<setw(20)<<smetka<<right<<setw(15)<<kapital<<right<<setw(15)<<kamata<<endl;		
		}
		friend void vkupnokapitalikamata(Shtedach*,int);
		friend void listanashtedachi(Shtedach*,int);
		friend void sortiranjeshtedachi(Shtedach*,int);
};

double Shtedach::kamatnastapka=0;

void vkupnokapitalikamata(Shtedach shtedachi[],int brojnalica){
	double vkupenkapital=0,vkupnakamata=0;
	for(int i=0;i<brojnalica;i++){
		vkupenkapital+=shtedachi[i].kapital;
		vkupnakamata+=shtedachi[i].zemikamata();
	}
	cout<<"_______________________________________________________________________________"<<endl;
	cout<<setprecision(2)<<fixed;
	cout<<right<<setw(44)<<"Vkupno"<<setw(15)<<vkupenkapital<<setw(15)<<vkupnakamata<<endl;
}
void listanashtedachi(Shtedach shtedachi[],int brojnalica){
	cout<<endl;
	cout<<left<<setw(8)<<""<<left<<setw(25)<<"Sopstvenik"<<left<<setw(10)<<"Smetka"<<right<<setw(16)<<"Kapital"<<right<<setw(15)<<"Kamata"<<endl<<endl;
	for(int i=0;i<brojnalica;i++){
		cout<<right<<setw(2)<<i+1<<": ";
		shtedachi[i].prikazhishtedach(shtedachi[i]);
	}
}
void sortiranjeshtedachi(Shtedach shtedachi[],int brojnalica){
	Shtedach pom;
	int brojach=1;
	do{
		for(int i=brojnalica-1;i>=brojach;i--){
			if(shtedachi[i].sopstvenik<shtedachi[i-1].sopstvenik){
				pom=shtedachi[i];
				shtedachi[i]=shtedachi[i-1];
				shtedachi[i-1]=pom;
			}
		}
		brojach++;
	}while(brojach<brojnalica);
}
int main(){
	string sopstvenik;
	long long smetkabroj;
	double kapital;
	double kamatnastapka;
	string vlez;
	
	cout<<"Vnesete ja kamatnata stapka: ";
	cin>>kamatnastapka;
	Shtedach::postavikamatnastapka(kamatnastapka);
	system("CLS");
	
	Shtedach shtedachi[100];
	ifstream datoteka("Shtedach2.dat");
	if(!datoteka){
		cout<<"Nemat datoteka"<<endl;
		exit(1);
	}
	
	int i=-1;
	while(true){
		i++;
		getline(datoteka,sopstvenik);
		if(sopstvenik=="KRAJ")
			break;
		getline(datoteka,vlez); smetkabroj=stoll(vlez);
		getline(datoteka,vlez); kapital=stod(vlez);
		
		shtedachi[i]={sopstvenik,smetkabroj,kapital};
		
		getline(datoteka,vlez);
	}
	datoteka.close();
	int brojnalica=i;
	Shtedach nekoj;
	cout<<"\n\t\t\t LISTA NA NESORTIRANI SHTEDACHI \n Kamatna satpka: "<<kamatnastapka<<"%"<<endl;
	listanashtedachi(shtedachi,brojnalica);
	vkupnokapitalikamata(shtedachi,brojnalica);
	
	cout<<endl;
	system("PAUSE");
	system("CLS");
	
	sortiranjeshtedachi(shtedachi,brojnalica);
	
	cout<<"\n\t\t\t LISTA NA SORTIRANI SHTEDACHI \n Kamatna satpka: "<<kamatnastapka<<"%"<<endl;
	listanashtedachi(shtedachi,brojnalica);
	vkupnokapitalikamata(shtedachi,brojnalica);
	
	cout<<endl;
	system("PAUSE");
	return 0;
}





























