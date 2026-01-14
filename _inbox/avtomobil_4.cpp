#include <iostream>
#include <cstring>

using namespace std;

class Automobile {
private:
    char *marka;
    int *reg;
    int brzina;
public:
  Automobile (const char *m = "")
  {
      marka = new char[strlen(m)+1];
      strcpy(marka, m);
      reg = NULL;
      brzina = 0;
  };
    Automobile(const char *m, const int *r, int b) {
        marka = new char[strlen(m) + 1];
        strcpy(marka, m);
        reg = new int[5];
        for(int i = 0; i<5; i++) {
        reg[i] = r[i];
        }
        brzina = b;
    }
    Automobile & operator =(const Automobile &a) {
        if(this != &a) {
            delete [] marka;
            this->marka = new char[strlen(a.marka)+1];
            strcpy(this->marka, a.marka);
            delete [] reg;
            this->reg = new int[5];
            for(int i=0; i< 5; i++) {
                reg[i] = a.reg[i];
                brzina = a.brzina;
            }
            return *this;

        }


    }
    ~Automobile() {
        delete [] reg;
        delete [] marka;
    }
    bool operator ==(const Automobile &a) {
        for (int i=0; i<5; i++) {
            if(reg[i] != a.reg[i])
                return 0;
        }
        return 1;
    }
    friend ostream & operator << (ostream &o, const Automobile &a) {
        o << "Marka" << "\t" << a.marka << "\t" << "Registracija[";
        for (int i = 0; i<5; i++) {
            o<< " " << a.reg[i];
        }
        o << " ]" << endl;
        return o;
    }

    int getBrzina() {
        return brzina;
    }
};

class RentACar {
private:
    char *ime;
    Automobile *cars;
    int broj;
public:
    RentACar(const char*i = "") {
        this->ime = new char[strlen(i)+1];
        strcpy(this->ime, i);
        cars = NULL;
        broj = 0;
    }
    ~RentACar() {
        delete [] ime;
        delete [] cars;
    };
    
     RentACar & operator +=(const Automobile &a) {
        Automobile *temp = new Automobile[broj+1];
        for(int i = 0; i<broj; i++) {
            temp[i] = cars[i];
        } 
         temp[broj++] = a;
         delete [] cars;
         cars = temp;
         return *this;
    }
    
    

    RentACar & operator -=(const Automobile &a) {
        Automobile *temp = new Automobile[broj];
        for(int i = 0; i<broj; i++) {
            if(cars[i]==a)
                temp[i] = a;
            else
                temp[i] = cars[i];
        }
        delete [] cars;
        cars = temp;
        return *this;
    }

    void pecatiNadBrzina(int max) {
        cout << ime << endl;
        for(int i = 0; i < broj; i++) {
            if(cars[i].getBrzina()>max) {
                cout << cars[i];
            }
        }
    }


};



int main() {
    RentACar agencija("FINKI-Car");
     int n;
     cin>>n;

     for (int i=0;i<n;i++)
     {
      	char marka[100];
      	int regisracija[5];
      	int maximumBrzina;

         	cin>>marka;

         	for (int i=0;i<5;i++)
      		cin>>regisracija[i];

      	cin>>maximumBrzina;

         	Automobile nov=Automobile(marka,regisracija,maximumBrzina);

      	//dodavanje na avtomobil
         	agencija+=nov;

     }
      //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
      char marka[100];
      int regisracija[5];
      int maximumBrzina;
      cin>>marka;
      for (int i=0;i<5;i++)
      cin>>regisracija[i];
      cin>>maximumBrzina;

      Automobile greshka=Automobile(marka,regisracija,maximumBrzina);

      //brishenje na avtomobil
      agencija-=greshka;

      agencija.pecatiNadBrzina(150);

      return 0;
}