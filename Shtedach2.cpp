#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Shtedach{
	private:
		const string banka="Nasha Banka";
		static double kamatnastapka;
		string sopstvenik;
		long long smetka;
		double depozit;
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
};
double Shtedach::kamatnastapka=0;

int main(){
	string sopstvenik;
	long long smetka;
	double depozit;
	double kamatnastapka;
	string vlez;
	cout<<"Vnesete ja kamatnata stapka: ";
	cin>>kamatnastapka;
	Shtedach::postavikamatnastapka(kamatnastapka);
	system("CLS");
	ifstream datoteka("Shtedach2.dat");
	if(!datoteka){
		cout<<"Nemat datoteka"<<endl;
		exit(1);
	}
	Shtedach shtedachi[100];
	int i=-1;
	while(true){
		i++;
		getline(datoteka,sopstvenik);
		if(sopstvenik=="KRAJ")
			break;
		getline(datoteka,vlez); smetka=stoll(vlez);
		getline(datoteka,vlez); depozit=stod(vlez);
		
		shtedachi[i].postavishtedach(sopstvenik,smetka,depozit);
		
		getline(datoteka,vlez);
	}
	datoteka.close();
	int brojnashtedachi=i;
	Shtedach nekoj;
	cout<<"\n\t LISTA NA SHTEDACHI \n\t Kamatna stapka: "<<kamatnastapka<<"% \n"<<endl;
	for(int i=0;i<brojnashtedachi;i++){
		shtedachi[i].prikazhishtedach();
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}



























