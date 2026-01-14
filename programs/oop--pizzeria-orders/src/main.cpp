#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Pica{
	private:
		char ime[15];
		int cena;
		char *sostojki;
		int namaluvanje;
	public:
		Pica(const char *ime="", int cena=0, const char *sostojki="",int namaluvanje=0){
			strcpy(this->ime,ime);
			this->cena=cena;
			this->sostojki=new char[strlen(sostojki)+1];
			strcpy(this->sostojki,sostojki);
			this->namaluvanje=namaluvanje;
		}
		Pica (const Pica &p){
			strcpy(this->ime,p.ime);
			this->cena=p.cena;
			this->namaluvanje=p.namaluvanje;
			this->sostojki=new char[strlen(p.sostojki)+1];
			strcpy(this->sostojki,p.sostojki);
		}
		Pica &operator=(const Pica &p){
			if(this!=&p){
				delete [] sostojki;
				sostojki=new char[strlen(p.sostojki)+1];
				strcpy(this->sostojki,p.sostojki);
				strcpy(this->ime,p.ime);
				this->cena=p.cena;
				this->namaluvanje=p.namaluvanje;
			}
			return *this;
		}
		int getnamaluvanje(){
			return namaluvanje;
		}
		int getcena(){
			return cena;
		}
		void pechati(){
			cout<<ime<<" - "<<sostojki<<", "<<cena;
		}
		bool istise(Pica p){
			return (!strcmp(this->sostojki,p.sostojki));
		}
		~Pica(){
			delete[] sostojki;
		}
};
class Picerija{
	private:
		char ime[15];
		Pica *pica;
		int brojnapici;
	public:
		Picerija(const char *ime="",Pica *pica=0,int brojnapici=0){
			strcpy(this->ime,ime);
			this->brojnapici=brojnapici;
			this->pica=new Pica[brojnapici];
			for(int i=0;i<brojnapici;i++){
				this->pica[i]=pica[i];
			}
		}
		Picerija(const Picerija &p){
			strcpy(this->ime,p.ime);
			this->brojnapici=p.brojnapici;
			pica=new Pica[p.brojnapici];
			for(int i=0;i<brojnapici;i++){
				this->pica[i]=p.pica[i];
			}
		}
		Picerija &operator=(const Picerija &p){
			if(this!=&p){
				strcpy(this->ime,p.ime);
				this->brojnapici=p.brojnapici;
				delete [] pica;
				pica=new Pica[brojnapici];
				for(int i=0;i<brojnapici;i++)
				{
					pica[i]=p.pica[i];
				}
			}
			return *this;
		}
		void setime(const char *ime){
			strcpy(this->ime,ime);
		}
		char *getime(){
			return ime;
		}
		~Picerija(){
			delete [] pica;
		}
		void dodadi(Pica &p){
			bool isti_se=false;
			for(int i=0;i<brojnapici;i++){
				if (pica[i].istise(p))
				isti_se=true;
			}
			if(!isti_se){
				Pica *tmp=new Pica[brojnapici+1];
				for(int i=0;i<brojnapici;i++){
					tmp[i]=pica[i];
				}
				tmp[brojnapici++]=p;
				delete[] pica;
				pica=tmp;
			}
		}
		void picinapromocija(){
			for(int i=0;i<brojnapici;i++){
				if(pica[i].getnamaluvanje()!=0){
					pica[i].pechati();
					cout<<" "<<pica[i].getcena()-((pica[i].getcena()*pica[i].getnamaluvanje())/100)<<endl;
				}
			}
		}
};

int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setime(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);
    cout<<p1.getime()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.picinapromocija();

    cout<<p2.getime()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.picinapromocija();

	return 0;
}




















