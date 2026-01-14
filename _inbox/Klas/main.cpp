#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Klas{
        friend ostream& operator<<(ostream& pechatiklas, Klas& ovoj);
private:
    string *niza;
    int brojuchenici;
public:
    Klas(string *z= nullptr,int brojuchenici=0){
        postaviklas(z,brojuchenici);
    }
    void postaviklas(string *z, int brojuchenici){
        this->brojuchenici=brojuchenici;
        niza=new string[brojuchenici];
        this->niza=z;
    }
    void zemiklas(string *z, int&brojuchenici) {
        brojuchenici = this->brojuchenici;
        niza = new string[brojuchenici];
        z = this->niza;
    }
    ~Klas(){
        delete [] niza;
    }
    int zemibrojuchenici(){
        return brojuchenici;
    }
    string* zeminiza(){
        return niza;
    }
    Klas& operator+(string u){
        this->niza[brojuchenici]=u;
        this->brojuchenici++;
        return *this;
    }
};
ostream& operator<<(ostream& pechatiklas, Klas& ovoj){
    int n=ovoj.zemibrojuchenici();
    string *z=new string[n];
    z=ovoj.zeminiza();
    for(int i=0;i<n;i++)
        cout<<right<<setw(5)<<i+1<<"   "<<left<<setw(25)<<z[i]<<endl;
    return pechatiklas;
}

int main() {
    string *uchenik= new string[30];
    uchenik[0]={"Mihaela Babina"};
    uchenik[1]={"Jana Janika"};
    uchenik[2]={"Jovana Zhaklinska"};
    uchenik[3]={"Teo Balevski"};

    int brojuchenici=0;
    Klas mojklas(uchenik,brojuchenici);
    for(int i=0;i<4;i++){
        mojklas+uchenik[i];
    }
    cout<<"Mojot klas ima "<<mojklas.zemibrojuchenici()<<" uchenici:\n"<<endl;
    cout<<right<<setw(6)<<"Broj"<<setw(17)<<"Ime i prezime"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<mojklas;
    cout<<"-------------------------"<<endl;

    string novuchenik("Anastasija Sashovska");
    mojklas=mojklas+novuchenik;
    cout<<"\n\nMojot klas ima "<<mojklas.zemibrojuchenici()<<" uchenici:\n"<<endl;
    cout<<right<<setw(6)<<"Broj"<<setw(17)<<"Ime i prezime"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<mojklas;
    cout<<"-------------------------"<<endl;

    cout<<endl;
    system("PAUSE");
    return 0;
}
















