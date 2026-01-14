#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Datum{
private:
    int den,mesec,godina;
public:
    Datum();
    Datum(int, int ,int);
    void postavidatum(int, int ,int);
    void zemidatum(int&, int&, int&);
    void prikazhidatum(Datum);
};

Datum::Datum() {
    den=mesec=godina=0;
}
Datum::Datum(int den,int mesec,int godina) {
    postavidatum(den,mesec,godina);
}
void Datum::postavidatum(int den, int mesec, int godina) {
    this->den=den;
    this->mesec=mesec;
    this->godina=godina;
}
void Datum::zemidatum(int &den, int &mesec, int &godina) {
    den=this->den;
    mesec=this->mesec;
    godina=this->godina;
}
void Datum::prikazhidatum(Datum dmg) {
    string rodenden = to_string(dmg.den) + "."+ to_string(dmg.mesec) + "." + to_string(dmg.godina);
    cout<<right<<setw(12)<<rodenden<<endl;
}

class Lice{
private:
    string ime,prezime;
    long long matichenbroj;
    Datum rodenden;
public:
    Lice();
    Lice(string,string,long long, Datum);
    void postavilice(string, string, long long, Datum);
    void zemilice(string&, string&, long long& , Datum&);
    void prikazhilice();
};
Lice::Lice(){
    matichenbroj=0;
    ime=prezime="";
    rodenden=Datum();
}
Lice::Lice(string ime, string prezime, long long matichenbroj, Datum rodenden) {
    postavilice(ime,prezime,matichenbroj,rodenden);
}
void Lice::postavilice(string ime , string prezime, long long matichenbroj, Datum rodenden) {
    this->matichenbroj=matichenbroj;
    this->ime=ime;
    this->prezime=prezime;
    this->rodenden=rodenden;
}

void Lice::zemilice(string &ime, string &prezime, long long &matichenbroj, Datum &rodenden) {
    matichenbroj=this->matichenbroj;
    ime=this->ime;
    prezime=this->prezime;
    rodenden=this->rodenden;
}
void Lice::prikazhilice() {
    zemilice(ime,prezime,matichenbroj,rodenden);
    cout<<left<<setw(10)<<ime<<" "<<setw(15)<< prezime << "EMBG: "<<setw(15)<<matichenbroj<<"Roden: ";
    rodenden.prikazhidatum(rodenden);
}
int main() {
    const int brojnalica=5;
    Lice lica[brojnalica];
    Datum datumi[brojnalica];

    datumi[0]={22,7,356};
    datumi[1]={1,1,958};
    datumi[2]={23,11,1877};
    datumi[3]={17,8,1902};
    datumi[4]={3,5,1917};

    lica[0]={"Ethan", "Miller", 1234567890123, datumi[0]};
    lica[1]={"Car", "Samoil", 1234567890124, datumi[1]};
    lica[2]={"Ryan", "Reed", 1234567890125, datumi[2]};
    lica[3]={"Metodija", "Andonov",1234567890126,datumi[3]};
    lica[4]={"Kiro", "Gligorov", 1234567890127, datumi[4]};

    cout<<left<<setw(25)<<"Ime i Prezime"<<setw(20)<<"EMBG"<<setw(15)<<" Rodenden"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    for(int i=0;i<brojnalica;i++){
        lica[i].prikazhilice();
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}























