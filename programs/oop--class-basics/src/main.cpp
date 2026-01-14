#include <string>
#include <iostream>
#include<iomanip>
using namespace std;

class Uchenik{
    friend ostream &operator <<(ostream& pechatiuchenik, const Uchenik& u);
private:
    string imeiprezime;
    int brojvodnevnik;
    double prosek;
public:
    Uchenik(){

    }
    Uchenik(string imeiprezime,int brojvodnevnik, double prosek){
        postaviuchenik(imeiprezime,brojvodnevnik,prosek);
    }
    ~Uchenik(){

    }
    void postaviuchenik(string imeiprezime,int brojvodnevnik, double prosek){
        this->imeiprezime=imeiprezime;
        this->brojvodnevnik=brojvodnevnik;
        this->prosek=prosek;
    }
    void zemiuchenik(string &imeiprezime, int &brojvodnevnik, double &prosek){
        imeiprezime=this->imeiprezime;
        brojvodnevnik=this->brojvodnevnik;
        prosek=this->prosek;
    }
};

ostream& operator<<(ostream& pechatiuchenik,const Uchenik& u){
    return pechatiuchenik<<right<<setw(5)<<u.brojvodnevnik<<"   "<<left<<setw(25)<<u.imeiprezime<<right<<fixed<<setw(5)<<setprecision(2)<<u.prosek<<endl;
}

class Klas{
    friend ostream &operator <<(ostream& pechatiklas, const Klas& klas);
private:
    Uchenik *niza;
    int brojnauchenici;
public:
    Klas(Uchenik *z = nullptr, int brojnauchenici = 0) {
        postaviklas(z,brojnauchenici);
    }
    void postaviklas(Uchenik *z,int brojnauchenici){
        this->brojnauchenici=brojnauchenici;
        niza=new Uchenik[brojnauchenici];
        this->niza=z;
    }
    void zemiklas(Uchenik *z, int& brojnauchenici){
        brojnauchenici=this->brojnauchenici;
        niza=new Uchenik[brojnauchenici];
        z=this->niza;
    }
    ~Klas(){
        delete[] niza;
    }
    int zemibrojnauchenici(){
        return brojnauchenici;
    }
    Uchenik *zeminiza(){
        return niza;
    }
    Klas & operator+(Uchenik u){
        this->niza[brojnauchenici]=u;
        this->brojnauchenici++;
        return *this;
    }
    double prosek(Klas klas){
        klas.zemiklas(niza,brojnauchenici);
        double pro=0;
        for(int i=0;i<brojnauchenici;i++){
            string imeiprezime;
            int brojvodnevnik;
            double prosek;
            niza[i].zemiuchenik(imeiprezime,brojvodnevnik,prosek);
            pro+=prosek;
        }
        return pro/brojnauchenici;
    }
};
ostream & operator <<(ostream &pechatiklas, Klas& klas){
    Uchenik *z = new Uchenik[klas.zemibrojnauchenici()];
    z=klas.zeminiza();
    for(int i=0;i<klas.zemibrojnauchenici();i++){
        cout<<z[i];
    }
    return pechatiklas;
}

int main(){
    Uchenik *uchenik = new Uchenik[30];
    uchenik[0]={"Megan Nelson",1,5};
    uchenik[1]={"Lauren Carlson", 2 , 4.5};
    uchenik[2]={"Jovana Jovanova",3,4};
    uchenik[3]={"Teo Teov",4,3.5};

    int brojnauchenici=0;
    Klas mojklas(uchenik,brojnauchenici);
    for(int i=0;i<4;i++){
        mojklas+uchenik[i];
    }
    cout<<"\nMojot klas ima "<<mojklas.zemibrojnauchenici()<<" uchenici:"<<endl;
    cout<<setw(6)<<"Broj"<<setw(17)<<"Ime i prezime"<<setw(16)<<"Prosek"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<mojklas;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<setw(33)<<"Prosek na klasot e "<<setw(5)<<right<<mojklas.prosek(mojklas)<<endl;

    Uchenik novuchenik("Madison Thompson",5,5);
    mojklas=mojklas+novuchenik;
    cout<<endl<<endl;
    cout<<"\nMojot klas ima "<<mojklas.zemibrojnauchenici()<<" uchenici:"<<endl;
    cout<<setw(6)<<"Broj"<<setw(17)<<"Ime i prezime"<<setw(16)<<"Prosek"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<mojklas;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<setw(33)<<"Prosek na klasot e "<<setw(5)<<right<<mojklas.prosek(mojklas)<<endl;

    cout<<endl;
    system("PAUSE");
    return 0;

}



















