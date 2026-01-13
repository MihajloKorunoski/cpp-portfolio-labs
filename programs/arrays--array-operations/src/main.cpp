#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Niza {
private:
public:
    virtual void dodavanjeelement(Niza *) = 0;

    virtual void brishenjeelementi(Niza *) = 0;

    virtual Niza *sobiranje2nizi(Niza *, Niza *) = 0;

    virtual void prikazhuvanjeniza() = 0;
};

class Brojnaniza : public Niza {
private:
    int brojelementi;
    double *x;
public:
    Brojnaniza() {
        brojelementi = 0;
        x = nullptr;
    }

    Brojnaniza(int brojelementi, double *x) {
        this->brojelementi = brojelementi;
        this->x = x;
        for (int i = 0; i < brojelementi; i++)
            this->x[i] = x[i];
    }

    ~Brojnaniza() = default;

    int zemibrojelementi() {
        return brojelementi;
    }

    virtual void dodavanjeelement(Niza *u) {
        Brojnaniza *a = (Brojnaniza *) u;
        double vrednost;
        cout << "Vnesete brojna vrednost: ";
        cin >> vrednost;
        a->x[brojelementi] = vrednost;
        a->brojelementi++;
        u = a;
    }

    virtual void brishenjeelementi(Niza *u) {
        Brojnaniza *a = (Brojnaniza *) u;
        double vrednost;
        cout << "Vnesete brojna vrednost na elementot sho se brishe: ";
        cin >> vrednost;
        for (int i = 0; i < a->brojelementi; i++) {
            if (a->x[i] == vrednost)
                a->x[i] = a->x[brojelementi - 1];
        }
        a->brojelementi--;
        u = a;
    }

    virtual Niza *sobiranje2nizi(Niza *u, Niza *v) {
        int i;
        Brojnaniza *a = (Brojnaniza *) u;
        Brojnaniza *b = (Brojnaniza *) v;
        Brojnaniza *c = new Brojnaniza();
        int max = a->brojelementi;
        if (a->brojelementi < b->brojelementi)
            max = b->brojelementi;
        if (a->brojelementi < max)
            for (i = a->brojelementi; i < max; i++)
                a->x[i] = 0;
        else
            for (int i = b->brojelementi; i < max; i++)
                b->x[i] = 0;
        c->brojelementi = max;
        c->x = new double(max);
        for (int i = 0; i < max; i++) {
            c->x[i] = a->x[i] + b->x[i];
        }
        Niza *w = c;
        return w;
    }

    virtual void prikazhuvanjeniza() {
        cout << "Brojnata niza ima " << brojelementi << " elementi i toa:" << endl;
        cout << "\t";
        for (int i = 0; i < brojelementi; i++)
            cout << setw(5) << x[i];
        cout << endl;
    }
};

class Tekstualnaniza : public Niza {
private:
    string s;
public:
    Tekstualnaniza() {
        s = "";
    }

    Tekstualnaniza(string s) {
        this->s = s;
    }

    ~Tekstualnaniza() = default;

    virtual void dodavanjeelement(Niza *u) {
        Tekstualnaniza *a = (Tekstualnaniza *) u;
        char znak;
        cout << "Vnesete znak: ";
        cin >> znak;
        a->s += znak;
        u = a;
    }

    virtual void brishenjeelementi(Niza *u) {
        Tekstualnaniza *a = (Tekstualnaniza *) u;
        char znak;
        cout << "Vnesete go znakot shto se brishe: ";
        cin >> znak;
        int i = (a->s).find(znak);
        string s1 = (a->s).substr(0, i);
        string s2 = (a->s).substr(i + 1, a->s.length() - i - 1);
        a->s = s1 + s2;
        u = a;
    }

    virtual Niza *sobiranje2nizi(Niza *u, Niza *v) {
        Tekstualnaniza *a = (Tekstualnaniza *) u;
        Tekstualnaniza *b = (Tekstualnaniza *) v;
        Tekstualnaniza *c = new Tekstualnaniza();
        c->s = a->s + b->s;
        Niza *w = c;
        return w;
    }

    virtual void prikazhuvanjeniza() {
        cout << "Tekstualnata niza ima " << this->s.length() << " elementi i toa:" << endl;
        cout << "\t";
        cout << this->s;
        cout << endl;
    }
};

double x[100], y[100];

int main() {
   const int brojnizi = 2;
    int i, brojelementi;
      Niza *u[brojnizi];


      cout << "Vnesete broj na elementi na brojnata niza: ";
      cin >> brojelementi;
      for (int i = 0; i < brojelementi; i++) {
          cout << "x[" << i << "]=";
          cin >> x[i];
      }
      double *p = x;
      Brojnaniza a(brojelementi, p);
      u[0] = &a;
      string s;
      cout << "Vnesete tekstualna niza/string: ";
      cin >> s;
      Tekstualnaniza b(s);
      u[1] = &b;

      for (int i = 0; i < brojnizi; i++) {
          cout << "\nDodavanje element vo niza:   ";
          u[i]->prikazhuvanjeniza();
          u[i]->dodavanjeelement(u[i]);
          cout << "Nizata sega e:                ";
          u[i]->prikazhuvanjeniza();

          cout << "\nBrishenje element ot niza:  ";
          u[i]->prikazhuvanjeniza();
          u[i]->brishenjeelementi(u[i]);
          cout << "Nizata sega e:                ";
          u[i]->prikazhuvanjeniza();
      }

    Niza *c[brojnizi],*d[brojnizi],*e;
    cout<<"SOBIRANJE BROJNI NIZI"<<endl;
    cout<<"Vnesete broj na elementi vo prvata brojna niza: ";
    cin>>brojelementi;
    for (int i = 0; i < brojelementi; i++) {
        cout << "x[" << i << "]=";
        cin >> x[i];
    }
    double *q=x;
    Brojnaniza f(brojelementi,q);
    c[0]=&f;
    cout<<"Vnesete broj na elementi vo vtorata brojna niza: ";
    cin>>brojelementi;
    for (int i = 0; i < brojelementi; i++) {
        cout << "y[" << i << "]=";
        cin >> y[i];
    }
    double *r=y;
    Brojnaniza g(brojelementi,r);
    d[0]=&g;

    cout<<"SOBIRANJE TEKSTUALNI NIZI"<<endl;
    string s1;
    cout<<"Vnesete ja prvata tekstualna niza / string: ";
    cin>>s1;
    Tekstualnaniza h(s1);
    c[1]=&h;

    string s2;
    cout<<"Vnesete ja vtorata tekstualna niza / string: ";
    cin>>s2;
    Tekstualnaniza j(s2);
    d[1]=&j;

    for(int i=0; i<brojnizi;i++){
        cout<<"\n\tZbir na dvete nizi:"<<endl;
        cout<<"Prva:";
        c[i]->prikazhuvanjeniza();
        cout<<"Vtora:";
        d[i]->prikazhuvanjeniza();
        cout<<"Zbir:";
        e=c[i]->sobiranje2nizi(c[i],d[i]);
        e->prikazhuvanjeniza();
    }
    cout<<endl;
    system("PAUSE");
    return 0;

    cout << endl;
    system("PAUSE");
    return 0;

}



















