#include<iostream>
#include <cstring>

using namespace std;

class Avtomobil {
    char boja[20];
    char brend[20];
    char model[20];
public:
    friend class ParkingPlac;
    Avtomobil() {};
    Avtomobil(char *boja, char *brend, char *model) {
        strcpy(this->boja, boja);
        strcpy(this->brend, brend);
        strcpy(this->model, model);
    }
    Avtomobil (const Avtomobil &a) {
        strcpy(boja, a.boja);
        strcpy(brend, a.brend);
        strcpy(model, a.model);
    }
    Avtomobil & operator=(const Avtomobil &a) {
        if(this!= &a) {
            strcpy(boja, a.boja);
            strcpy(brend, a.brend);
            strcpy(model, a.model);
        }
        return *this;
    }
    ~Avtomobil(){};
};

class ParkingPlac {
private:
    char adresa[20];
    char *idBroj;
    int cena;
    int zarabotka;
    int parkirani;
    Avtomobil *niza;

public:
    friend class Avtomobil;
    ParkingPlac () {
        idBroj = new char [0];
        zarabotka = 0;
        parkirani = 0;
        niza = new Avtomobil[0];
    }
    ParkingPlac(char *adr,char *id,int c) {
        strcpy(adresa,adr);
        idBroj=new char[strlen(id)+1];
        strcpy(idBroj,id);
        cena=c;
        zarabotka=0;
        parkirani=0;
        niza=new Avtomobil[0];
    }
    ParkingPlac(const ParkingPlac &p) {
        strcpy(adresa,p.adresa);
        idBroj=new char[strlen(p.idBroj)+1];
        parkirani=p.parkirani;
        niza=new Avtomobil[parkirani];
        strcpy(idBroj,p.idBroj);
        cena=p.cena;
        zarabotka=p.zarabotka;
        for(int i=0; i<parkirani; i++) {
            niza[i]=p.niza[i];
        }
    }
    ParkingPlac & operator=(const ParkingPlac &p) {
        if(this!=&p) {
            delete[]idBroj;
            idBroj=new char[strlen(p.idBroj)+1];
            delete[]niza;
            parkirani=p.parkirani;
            niza=new Avtomobil[parkirani];
            strcpy(adresa,p.adresa);
            strcpy(idBroj,p.idBroj);
            cena=p.cena;
            zarabotka=p.zarabotka;
            for(int i=0; i<parkirani; i++) {
                niza[i]=p.niza[i];
            }
        }
        return *this;
    }
    ~ParkingPlac() {
        delete[]idBroj;
        delete[]niza;
    } void pecati() {
        if(zarabotka>0)
            cout<<idBroj<< " " <<adresa<< " - " <<zarabotka<< " denari" <<endl;
        else cout<<idBroj<< " " <<adresa<<endl;
    } void platiCasovi(int casovi) {
        zarabotka+=casovi*cena;
    }
    bool daliIstaAdresa(ParkingPlac p) {
        if(strcmp(adresa,p.adresa)==0)
            return
                true;
        else
            return
                false;
    }
    void parkirajVozilo(Avtomobil novoVozilo) {
        Avtomobil *temp=new Avtomobil[parkirani+1];
        for(int i=0; i<parkirani; i++) {
            temp[i]=niza[i];
        }
        temp[parkirani]=novoVozilo;
        parkirani++;
        delete[]niza;
        niza=temp;
    } void pecatiParkiraniVozila() {
        cout<<"Vo parkingot se parkirani slednite vozila: "<<endl;
        for(int i=0; i<parkirani; i++) {
            cout<<i+1<<"."<<niza[i].boja<<" "<<niza[i].brend<<" "<<niza[i].model<<endl;
        }
    }
    char *getId() {
        return idBroj;
    }


};


int main() {

    ParkingPlac p[100];
    int n,m;
    char adresa[50],id[50];
    int brojcasovi,cenacas;
    cin>>n;
    if(n > 0){


    	for (int i=0;i<n;i++){
            cin.get();
    		cin.getline(adresa,50);
    		cin>>id>>cenacas;

    		ParkingPlac edna(adresa,id,cenacas);

            p[i]=edna;
    	}

    	//plakjanje
    	cin>>m;
    	for (int i=0;i<m;i++){

    		cin>>id>>brojcasovi;

            int findId=false;
            for (int j=0;j<m;j++){
                if (strcmp(p[j].getId(),id)==0){
                    p[j].platiCasovi(brojcasovi);
                    findId=true;
                }
            }
    		if (!findId)
            cout<<"Ne e platen parking. Greshen ID."<<endl;
    	}

        cout<<"========="<<endl;
        ParkingPlac pCentar("Cvetan Dimov","C10",80);
    	for (int i=0;i<n;i++)
            if (p[i].daliIstaAdresa(pCentar))
                p[i].pecati();
    } else {

    	ParkingPlac najdobarPlac("Mars", "1337", 1);
        int brVozila;
        cin >> brVozila;
        for(int i = 0; i < brVozila; ++i){

        	char boja[20];
        	char brend[20];
        	char model[20];

        	cin >> boja >> brend >> model;
        	Avtomobil novAvtomobil(boja, brend, model);
        	najdobarPlac.parkirajVozilo(novAvtomobil);
        }
        if(brVozila != 0)
        najdobarPlac.pecatiParkiraniVozila();

    }  
}





















