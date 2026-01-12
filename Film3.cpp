#include<iostream>
#include<cstring>
using namespace std;
enum zhanr{
	akcija,komedija,drama
};
class Film{
	private:
		char *ime;
		int memorija;
		zhanr zanr;
	public:
		Film(){
			this->ime=new char[0];
		}
		Film(char *ime,int memorija,zhanr zanr){
			this->ime=new char[strlen(ime)+1];
			strcpy(this->ime,ime);
			this->memorija=memorija;
			this->zanr=zanr;
		}
		Film & operator=(const Film &f){
			if(this!=&f){
				delete[] this->ime;
				this->ime= new char[strlen(f.ime)+1];
				strcpy(this->ime,f.ime);
				this->memorija=f.memorija;
				this->zanr=f.zanr;
			}
			return *this;
		}
		~Film(){
			delete[] ime;
		}
		void pechati(){
			cout<<memorija<<"MB-\""<<ime<<"\""<<endl;
		}
		int getmemorija(){
			return memorija;
		}
		zhanr getzhanr(){
			return zanr;
		}
};
class Dvd{
	private:
		Film filmovi[5];
		int n;
		int memorijadvd;
	public:
		Dvd(int memorijadvd=0,Film *filmovi=NULL, int n=0){
			this->memorijadvd=memorijadvd;
			this->n=n;
			for(int i=0;i<n;i++)
			{
				this->filmovi[i]=filmovi[i];
			}
		}	
		~Dvd(){
		}
		void dodadifilm(Film &f){
			int suma=0;
			for(int i=0;i<n;i++){
				suma+=filmovi[i].getmemorija();
			}
			int preostanato=memorijadvd-suma;
			if(preostanato>=f.getmemorija()&&n<5){
				filmovi[n]=f;
				n++;
			}
		}
		void pechatifilmovidrugzhanr(zhanr z){
			for(int i=0;i<n;i++){
				if(filmovi[i].getzhanr()!=z)
				filmovi[i].pechati();
			}
		}
		Film &getfilm(int i){
			return filmovi[i];
		}
		int getbroj(){
			return n;
		}
		float procentnamemorijaodzhanr(zhanr z){
			int suma=0;
			int vkupno=0;
			for(int i=0;i<n;i++){
				if(filmovi[i].getzhanr()==z){
					suma+=filmovi[i].getmemorija();
					vkupno+=filmovi[i].getmemorija();
				}
			}
			return (float) suma/vkupno*100.0;
		}
};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zhanr) kojzanr);
        f.pechati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        Dvd omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zhanr) kojzanr);
            omileno.dodadifilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getfilm(i)).pechati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        Dvd omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zhanr) kojzanr);
            omileno.dodadifilm(f);
        }
        for (int i = 0; i < omileno.getbroj(); i++)
            (omileno.getfilm(i)).pechati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        Dvd omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zhanr) kojzanr);
            omileno.dodadifilm(f);
        }
        cin >> kojzanr;
        omileno.pechatifilmovidrugzhanr((zhanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        Dvd omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zhanr) kojzanr);
            omileno.dodadifilm(f);
        }
        cin >> kojzanr;
        omileno.pechatifilmovidrugzhanr((zhanr) kojzanr);

    } else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		Dvd omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zhanr) kojzanr);
            omileno.dodadifilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentnamemorijaodzhanr((zhanr) kojzanr)<<"%\n";
		
	}

    return 0;
}



























