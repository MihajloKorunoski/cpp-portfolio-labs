#include <iostream>
#include <string>
using namespace std;

class Roditel{
private:
    string imeiprezimenaroditel;
    string bojanaochinaroditel;
public:
    Roditel(const string &imeiprezimenaroditel, const string &bojanaochinaroditel) : imeiprezimenaroditel(imeiprezimenaroditel), bojanaochinaroditel(bojanaochinaroditel) {}

    const string &getImeiprezimenaroditel() const {
        return imeiprezimenaroditel;
    }

    void setImeiprezimenaroditel(const string &imeiprezimenaroditel) {
        this->imeiprezimenaroditel = imeiprezimenaroditel;
    }

    const string &getBojanaochinaroditel() const {
        return bojanaochinaroditel;
    }

    void setBojanaochinaroditel(const string &bojanaochinaroditel) {
        this->bojanaochinaroditel = bojanaochinaroditel;
    }
    void prikazhiroditel(){
        cout<<"\n Roditelot: "<<getImeiprezimenaroditel();
        cout<<"\n Ima ochi so boja: "<<getBojanaochinaroditel();
        cout<<endl;
    }
};
class Dete: public Roditel{
private:
    string imeiprezimenadete;
    string bojanaochinadete;
public:
    Dete(string imeiprezimenaroditel, string bojanaochinaroditel, string imeiprezimenadete, string bojanaochinadete): Roditel(imeiprezimenaroditel,bojanaochinaroditel){
        this->imeiprezimenadete=imeiprezimenadete;
        this->bojanaochinadete=bojanaochinadete;
    }
    void postaviimeiprezimenadete(string imeiprezimenadete){
        this->imeiprezimenadete=imeiprezimenadete;
    }
    string zemiimeiprezimenadete(){
        return imeiprezimenadete;
    }
    string zemibojanaochinadete(){
        bojanaochinadete=getBojanaochinaroditel();
        return bojanaochinadete;
    }
    void prikazhidete(){
        prikazhiroditel();
        cout<<"\n Deteto: "<<zemiimeiprezimenadete();
        cout<<"\n Nasledilo od roditelot ochi so boja: "<<zemibojanaochinadete();
        cout<<endl;
    }
};

int main(){
    string imeiprezimenaroditel,bojanaochinaroditel;
    string imeiprezimenadete,bojanaochinadete;

    cout<<"Vnesete go imeto i prezimeto na vashiot roditel: ";
    getline(cin,imeiprezimenaroditel);
    cout<<"Vnesete ja bojata na ochite na roditelot: ";
    getline(cin,bojanaochinaroditel);
    cout<<"Vnesete go imeto i prezimeto na deteto: ";
    getline(cin,imeiprezimenadete);

    Dete moedete(imeiprezimenaroditel,bojanaochinaroditel,imeiprezimenadete,bojanaochinadete);
    moedete.prikazhidete();

    cout<<endl;
    system("PAUSE");
    return 0;
}


























