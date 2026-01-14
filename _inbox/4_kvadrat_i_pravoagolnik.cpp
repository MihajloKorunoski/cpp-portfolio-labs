#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#include <iostream>
#include <cmath>
using namespace std;

class Kvadrat {
protected:
    double a;
public:
    Kvadrat () {}
    Kvadrat (double a) {
    	this->a=a;
    }
    Kvadrat (const Kvadrat &kvadrat) {
    	this->a=kvadrat.a;
    }
    void pecati () {
        cout<<"Kvadrat so dolzina a="<<a<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
    }
    double perimetar () {
    	return 4*a;
    }
    double plostina () {
    	return a*a;
    }
};
class Pravoagolnik : public Kvadrat {
    double x;
    double y;
public:
    Pravoagolnik () {}
    Pravoagolnik (const Kvadrat &k, double x, double y) : Kvadrat (k) {
    	this->x=x;
        this->y=y;
    }
    Pravoagolnik (const Pravoagolnik &pravoagolnik) : Kvadrat(pravoagolnik) {
    	this->x=pravoagolnik.x;
        this->y=pravoagolnik.y;
    }
    void pecati () {
    	if ((x==0&&y==0) || (x==y))
            cout<<"Kvadrat so dolzina a="<<a+x<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
        else
            cout<<"Pravoagolnik so strani: "<<a+x<<" i "<<a+y<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;

    }
    double perimetar () {
    	if (x==0 && y==0) return Kvadrat::perimetar();
        else return 2*(a+x)+2*(a+y);
    }
    double plostina () {
    	if (x==0 && y==0) return Kvadrat::plostina();
        else return (a+x)*(a+y);
    }
};

int main() {
    int n;
    double a,x,y;
    Kvadrat * kvadrati;
    Pravoagolnik * pravoagolnici;

    cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

    for (int i=0; i<n; i++) {
        cin>>a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i=0; i<n; i++) {
        cin>>x>>y;

        pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"===Testiranje na klasata Kvadrat==="<<endl;
        for (int i=0; i<n; i++)
            kvadrati[i].pecati();
    } else {
        cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
        for (int i=0; i<n; i++)
            pravoagolnici[i].pecati();
    }
}