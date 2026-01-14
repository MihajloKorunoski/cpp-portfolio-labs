#include<iostream>
#include<cstring>
using namespace std;

class InvalidDateException{
    int d, m, y;
public:
    InvalidDateException(int d, int m, int y){
        this->d=d;this->m=m;this->y=y;
    }
    void show(){
        cout<<"Invalid Date "<<d<<"/"<<m<<"/"<<y<<endl;
    }
};

class NotSupportedCurrencyException{
    char c[3];
public:
    NotSupportedCurrencyException(char *c){
        strcpy(this->c,c);
    }
    void show(){
        cout<<c<<" is not a supported currency"<<endl;
    }
};

class Transakcija{
protected:
    int den, mesec, godina;
    double iznos;
public:
    static double EUR;
    static double USD;
    Transakcija(int den=1, int mesec=1, int godina=1, double iznos=0){
        if(den<1 || den>31 || mesec<1 || mesec>12)
            throw InvalidDateException(den, mesec, godina);
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
        this->iznos=iznos;
    }
    static void setEUR(double newEUR){
        EUR=newEUR;
    }
    static void setUSD(double newUSD){
        USD=newUSD;
    }
    virtual double voDenari()=0;
    virtual void pecati()=0;
    virtual double voEvra()=0;
    virtual double voDolari()=0;
};

double Transakcija::EUR=61;
double Transakcija::USD=50;

class DenarskaTransakcija: public Transakcija{
public:
    DenarskaTransakcija(int den=1, int mesec=1, int godina=1, double iznos=0):
        Transakcija(den, mesec, godina, iznos){}
    double voDenari(){
        return iznos;
    }
    double voEvra(){
        return iznos*EUR;
    }
    double voDolari(){
        return iznos*USD;
    }
    void pecati(){
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" MKD"<<endl;
    }
};

class DeviznaTransakcija: public Transakcija{
private:
    char valuta[3];
public:
    DeviznaTransakcija(int den=1, int mesec=1, int godina=1, double iznos=0, char *valuta=""):
        Transakcija(den, mesec, godina, iznos){
        if(strcmp(valuta,"USD")==0||strcmp(valuta,"EUR")==0)
            strcpy(this->valuta,valuta);
        else
            throw NotSupportedCurrencyException(valuta);
    }
    double voDenari(){
        if(strcmp(valuta,"USD")==0)
            return iznos*USD;
        else if(strcmp(valuta,"EUR")==0)
            return iznos*EUR;

    }
    double voEvra(){
        if(strcmp(valuta,"EUR")==0)
            return iznos;
        else if(strcmp(valuta,"USD")==0)
            return (iznos*USD)/EUR;

    }
    double voDolari(){
        if(strcmp(valuta,"USD")==0)
            return iznos;
        else if(strcmp(valuta,"EUR")==0)
            return (iznos*EUR)/USD;
    }
    void pecati(){
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" "<<valuta<<endl;
    }
};

class Smetka{
private:
    Transakcija **niza;
    int n;
    char brSmetka[15];
    double saldo;
public:
    Smetka(char *brSmetka="", double saldo=0.0){
        this->niza = new Transakcija*[0];
        this->niza=0;
        this->n=0;
        strcpy(this->brSmetka,brSmetka);
        this->saldo=saldo;
    }
    void operator+=(Transakcija *t){
        Transakcija **temp = new Transakcija*[n+1];
        for(int i=0;i<n;i++)
            temp[i]=niza[i];
        temp[n++]=t;
        delete []niza;
        niza=temp;
    }
    void izvestajVoDenari(){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=niza[i]->voDenari();
        }
        cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<sum+saldo<<" MKD"<<endl;
    }
    void izvestajVoEvra(){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=niza[i]->voDenari();
        }
        cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<(sum+saldo)/Transakcija::EUR<<" EUR"<<endl;
    }
    void izvestajVoDolari(){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=niza[i]->voDenari();
        }
        cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<(sum+saldo)/Transakcija::USD<<" USD"<<endl;
    }
    void pecatiTransakcii(){
        for(int i=0;i<n;i++)
            niza[i]->pecati();
    }
};

int main () {

	Smetka s ("300047024112789",1500);

	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [3];

	cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		if (tip==2){
			cin>>valuta;
            try{
				Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);
				s+=t;
            }	//delete t;
            catch(NotSupportedCurrencyException &e){
                e.show();
            }
            catch(InvalidDateException &e){
                e.show();
            }
		}
		else {
            try{
				Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);
				s+=t;
            }//delete t;
            catch(InvalidDateException &e){
                e.show();
            }
		}

	}
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



	return 0;
}


/*
Да се креира класа Transakcija во која што ќе се чуваат информации за:

датумот на реализирање на банкарската трансакција:
ден (int)
месец (int)
година (int)
паричниот износ кој се однесува на трансакцијата (позитивен или негативен, тип double)
моменталната вредност на еврото во денари (static double EUR), иницијално поставен на 61
моменталната вредност на доларот во денари (static double USD), иницијално поставен на 50
За класата да се имплемтнираат соодветните конструктори, како и да се дефинираат следните четири чисто виртуелни методи:

double voDenari()
double voEvra()
double voDolari()
void pecati()
Трансакциите можат да бидат денарски и девизни (DenarskaTransakcija и DeviznaTransakcija). За девизните трансакции се чува дополнителна информација за валутата на трансакцијата (низа од три знаци). Дозволени валути за девизните транскации се USD и EUR.

За двете изведени класи да се напишат соодветните конструктори, деструктори и да се препокријат потребните методи.

Да се дефинира класа Smetka во која што ќе се чуваат информации за:

извршените трансакции (динамички алоцирана низа од покажувачи кон класата Transakcija)
број на извршените трансакции (int)
број на сметката (низа од 15 знаци)
почетно салдо во денари (double)
За класата Smetka да се имплементираат:

потребен конструктор (со два аргументи, видете во main), деструктор
оператор за додавање на нова трансакција во низата од трансакции +=
void izvestajVoDenari() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во денари] MKD

void izvestajVoEvra() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во евра] EUR

void izvestajVoDolari() - функција што печати информации за сметката во форматот:

Korisnikot so smetka: [број на сметката] ima momentalno saldo od [салдо на сметката пресметано во долари] УСД

void pecatiTransakcii() - функција што ги печати сите внесени трансакции

Да се креираат класи за следните исклучоци:

InvalidDateException којшто се фрла доколку при креирање на трансакција не се испочитувани правилата 1<=ден<=31 и 1<=месец<=12
NotSupportedCurrencyException којшто се фрла доколку при креирање на девизна трансакција се внесува вредност за валута што не е дозволена
Овие исклучоци да се фрлат и да се фатат таму каде што е потребно. Истите при фаќање треба да печатат пораки од следниот формат:

Invalid Date 32/12/2018
GBP is not a supported currency
*/