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
    string vrabotuvanje = to_string(dmg.den) + "."+ to_string(dmg.mesec) + "." + to_string(dmg.godina);
    cout<<right<<vrabotuvanje<<endl;
}

class Vraboten{
    friend Datum stazh(Vraboten,Datum);
private:
    string imeiprezime;
    string rabotnomesto;
    Datum vrabotuvanje;
public:
    Vraboten(){

    }
    Vraboten(string imeiprezime,string rabotnomesto,Datum vrabotuvanje){
        postavivraboten(imeiprezime,rabotnomesto,vrabotuvanje);
    }
    ~Vraboten(){

    }
    void postavivraboten(string imeiprezime,string rabotnomesto,Datum vrabotuvanje){
        this->imeiprezime=imeiprezime;
        this->rabotnomesto=rabotnomesto;
        this->vrabotuvanje=vrabotuvanje;
    }
    void zemivraboten(string &imeiprezime, string &rabotnomesto, Datum &vrabotuvanje){
        imeiprezime=this->imeiprezime;
        rabotnomesto=this->rabotnomesto;
        vrabotuvanje=this->vrabotuvanje;
    }
    void prikazhivraboten(){
        zemivraboten(imeiprezime,rabotnomesto,vrabotuvanje);
        cout<<left<<setw(15)<<"Ime i prezime : "<<setw(25)<< imeiprezime<<endl;
        cout<<setw(15)<<"Rabotnomesto  : "<<setw(25)<<rabotnomesto<<endl;
        cout<<setw(15)<<"Vrabotuvanje  : ";
        vrabotuvanje.prikazhidatum(vrabotuvanje);
    }
    void prikazhistazh(Vraboten nekoj, Datum denes) {
        Datum st = stazh(nekoj, denes);
        int godini, meseci, denovi;
        st.zemidatum(denovi, meseci, godini);
        cout << setw(16) << "Stazh  : " << godini << " godini, " << meseci << " meseci i " << denovi << "dena." << endl;
    }
};
Datum stazh(Vraboten nekoj,Datum denes){
    int denvrabotuvanje,mesecvrabotuvanje,godinavrabotuvanje;
    nekoj.vrabotuvanje.zemidatum(denvrabotuvanje,mesecvrabotuvanje,godinavrabotuvanje);
    int dendenes,mesecdenes,godinadenes;
    denes.zemidatum(dendenes,mesecdenes,godinadenes);
    int den,mesec,godina;
    den=dendenes-denvrabotuvanje;
    if(den<0){
        den+=30;
        mesecdenes-=1;
    }
    mesec=mesecdenes-mesecvrabotuvanje;
    if(mesec<0){
        mesec+=12;
        godinadenes-=1;
    }
    godina=godinadenes-godinavrabotuvanje;
    return Datum(den,mesec,godina);
}
int main(){
    Datum denes(30,04,2017);
    Datum vrabotuvanje(20,04,1978);
    Vraboten logan{"Logan Larson","Geodeziski Inzhener", vrabotuvanje};
    logan.prikazhivraboten();
    logan.prikazhistazh(logan,denes);
    cout<<endl;
    system("PAUSE");
    return 0;
}
