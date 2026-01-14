#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Lekar {
protected:
    int faksimil;
    char ime[15];
    char prezime[15];
    double pocetnaPlata;

public:
    //konstruktori
    Lekar() {};
    Lekar(int faksimil, char *ime, char *prezime, double pocetnaPlata) {
        this->faksimil = faksimil;
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->pocetnaPlata = pocetnaPlata;
    };
    Lekar(const Lekar &doctor) {
        this->faksimil = doctor.faksimil;
        strcpy(this->ime, doctor.ime);
        strcpy(this->prezime, doctor.prezime);
        this->pocetnaPlata = doctor.pocetnaPlata;
    };

    // metodi
    void pecati() {
        cout << faksimil << ": " << ime << " " << prezime << endl;
    }

    double plata() {
        return this->pocetnaPlata;
    }

};


class MaticenLekar : public Lekar {
private:
    int brojPacienti;
    double *kotizacii;
public:
    //konstruktori
    MaticenLekar() {};
    MaticenLekar(Lekar &doctor, int brojPacienti, double *kotizacii): Lekar(doctor) {
        this->brojPacienti = brojPacienti;
        this->kotizacii = new double[brojPacienti+1];
        for(int i = 0; i < brojPacienti; i++) {
            this->kotizacii[i] = kotizacii[i];
        }
    }
    MaticenLekar(const MaticenLekar &doctor) {
        this->brojPacienti = doctor.brojPacienti;
        this->kotizacii = new double[doctor.brojPacienti+1];
        for(static int i = 0; i < doctor.brojPacienti; i++) {
            this->kotizacii[i] = doctor.kotizacii[i];
        }
    }

    // metodi
    void pecati() {
        Lekar::pecati();
        cout << "Prosek na kotizacii: ";
        int total = 0;
        for(int i = 0; i<brojPacienti; i++)
        {
            total+=kotizacii[i];
        }
        cout << total/brojPacienti << endl;
    }

    double plata() {
        double total = 0;
        for(int i = 0; i<this->brojPacienti; i++) {
            total+=kotizacii[i];
        }
        return Lekar::pocetnaPlata+total/this->brojPacienti*0.3;
    };



};





int main() {
    int n;
    cin>>n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime [20];
    char prezime [20];
    double osnovnaPlata;

    Lekar * lekari = new Lekar [n];
    MaticenLekar * maticni = new MaticenLekar [n];

    for (int i=0;i<n;i++){
    	cin >> faksimil >> ime >> prezime >> osnovnaPlata;
    	lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
    }

    for (int i=0;i<n;i++){
    	cin >> pacienti;
    	for (int j=0;j<pacienti;j++){
    		cin >> kotizacii[j];
    	}
    	maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
    	cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
    	for (int i=0;i<n;i++){
    		lekari[i].pecati();
    		cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
    	}
    }
    else {
    	cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
    	for (int i=0;i<n;i++){
    		maticni[i].pecati();
    		cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
    	}
    }

    delete [] lekari;
    delete [] maticni;

    return 0;
}