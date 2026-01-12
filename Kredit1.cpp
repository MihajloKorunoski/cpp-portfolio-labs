#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Transakciskasmetka;

class Bankarskasmetka{
		friend void kredit(Transakciskasmetka&,Bankarskasmetka&);
	private:
		string banka;
		string klient;
		long long smetka;
		long double kredit;
	public:
		Bankarskasmetka(string banka="",string klient="", long long smetka=0, long double kredit=0){
			postavibankarskasmetka(banka,klient,smetka,kredit);
		}
		void postavibankarskasmetka(string banka,string klient, long long smetka, long double kredit){
			this->banka=banka;
			this->klient=klient;
			this->smetka=smetka;
			this->kredit=kredit;
		}
		void zemibankarskasmetka(string &banka, string &klient, long long& smetka, long double& kredit){
			banka=this->banka;
			klient=this->klient;
			smetka=this->smetka;
			kredit=this->kredit;
		}
		void azhurirajkredit(long double& kredit, double uplata){
			kredit-=uplata;
		}
		void prikazhibankarskasmetka(){
			cout<<left<<setw(10)<<" Banka: "<<setw(20)<<banka<<endl;
			cout<<left<<setw(10)<<" Klient: "<<setw(20)<<klient<<endl;
			cout<<setw(10)<<" Smetka: "<<setw(15)<<smetka<<endl;
			cout<<setw(10)<<" Kredit: "<<setw(10)<<fixed<<setprecision(2)<<kredit<<endl;
			cout<<endl;
		}
};

class Transakciskasmetka{
		friend void kredit(Transakciskasmetka&,Bankarskasmetka&);
	private:
		string banka;
		string lice;
		long long smetka;
		double saldo;
	public:
		Transakciskasmetka(string banka="", string lice="", long long smetka=0, double saldo=0){
			postavitransakciskasmetka(banka,lice,smetka,saldo);
		}
		void postavitransakciskasmetka(string banka, string lice, long long smetka, double saldo){
			this->banka=banka;
			this->lice=lice;
			this->smetka=smetka;
			this->saldo=saldo;
		}
		void zemitransakciskasmetka(string &banka, string& lice, long long &smetka, double& saldo){
			banka=this->banka;
			lice=this->lice;
			smetka=this->smetka;
			saldo=this->saldo;
		}
		void azhurirajsaldo(double&saldo, double isplata){
			saldo-=isplata;
		}
		void prikazhitransakciskasmetka(){
			cout<<left<<setw(10)<<" Banka: "<<setw(20)<<banka<<endl;
			cout<<left<<setw(10)<<" Lice: "<<setw(20)<<lice<<endl;
			cout<<setw(10)<<" Smetka: "<<setw(15)<<smetka<<endl;
			cout<<setw(10)<<" Saldo: "<<setw(10)<<saldo<<endl;
			cout<<endl;
		}
};
void kredit(Transakciskasmetka& t, Bankarskasmetka& b){
	b.prikazhibankarskasmetka();
	t.prikazhitransakciskasmetka();
	cout<<"\nKolku uplakjate?: ";
	double iznos;
	cin>>iznos;
	cout<<endl;
	t.azhurirajsaldo(t.saldo,iznos);
	b.azhurirajkredit(b.kredit,iznos);
	b.prikazhibankarskasmetka();
	t.prikazhitransakciskasmetka();
}
int main(){
	Bankarskasmetka b("Makedonska banka", "Gjorgji Jovanchevski",1234567890123,1200000);
	Transakciskasmetka t("NLB banka", "Gjorgji Jovanchevski",5678901234567,20000);
	kredit(t,b);
	cout<<endl;
	system("PAUSE");
	return 0;
}





















