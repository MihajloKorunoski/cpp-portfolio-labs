#include<iostream>
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
	double kamatnastapka;
	cout<<"Vnesete kamatna stapka (Primer 4.2): ";
	cin>>kamatnastapka;
	system("CLS");
	
	Shtedach nekoj;
	nekoj.postavikamatnastapka(kamatnastapka);
	cout<<"Kamatna stapka: "<<kamatnastapka<<"% "<<endl<<endl;
	
	const int brojnashtedachi=2;
	Shtedach shtedachi[brojnashtedachi];
	shtedachi[0].postavishtedach("Jake Miller", 123456789012345, 10000);
	shtedachi[1].postavishtedach("Tosho Malerot", 123456789123456, 100000);
	
	for(int i=0;i<brojnashtedachi;i++){
		shtedachi[i].prikazhishtedach();
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}









































	
