#include <iostream>
#include<string>
using namespace std;

class Ekipa{
private:
    string ime;
    string mesto;
public:
    Ekipa(string ime= "", string mesto=""){
        postaviekipa(ime,mesto);
    }
    ~Ekipa(){

    }
    void postaviekipa(string ime, string mesto){
        this->ime=ime;
        this->mesto=mesto;
    }
    void zemiekipa(string &ime, string &mesto){
        ime=this->ime;
        mesto=this->mesto;
    }
    void prikazhiekipa(){
        cout<<ime<<" ("<<mesto<<")";
    }
};
class Natprevar{
private:
    Ekipa A,B;
    int golovia,golovib;
public:
    Natprevar(Ekipa A,Ekipa B, int golovia, int golovib){
        postavinatprevar(A,B,golovia,golovib);
    }
    ~Natprevar(){

    }
    void postavinatprevar(Ekipa A, Ekipa B, int golovia, int golovib){
        this->A=A;
        this->B=B;
        this->golovia=golovia;
        this->golovib=golovib;
    }
    void zeminatprevar(Ekipa &A, Ekipa &B, int &golovia, int &golovib){
        A=this->A;
        B=this->B;
        golovia=this->golovia;
        golovib=this->golovib;
    }
    void rezultat(Natprevar ovoj){
        cout<<"Rezultat: "<<endl;
        ovoj.A.prikazhiekipa();
        cout<<" - ";
        ovoj.B.prikazhiekipa();
        cout<<"\t"<<ovoj.golovia<<" : "<<ovoj.golovib<<endl;
    }
};
int main(){
    Ekipa A("Vardar", "Skopje");
    Ekipa B("Pelister", "Bitola");
    Natprevar kolo5(A,B,2,3);
    kolo5.rezultat(kolo5);

    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}