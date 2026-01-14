#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo
{
    private:
    char *ime;
    int broj_turi;
    int broj_chlen;
    
    public:
    PlDrustvo(const char *i = "", int t = 0, int c = 0)
    {
        this->ime = new char[strlen(i)+1];
        strcpy(ime, i);
        broj_turi = t;
        broj_chlen = c;
    }
    PlDrustvo(const PlDrustvo &p)
    {
    ime = new char[strlen(p.ime)+1];
     strcpy(ime, p.ime);
        broj_turi = p.broj_turi;
        broj_chlen = p.broj_chlen;
    }
    PlDrustvo & operator = (const PlDrustvo &p){
        if(this!=&p){
        delete [] ime;
            ime = new char[strlen(p.ime)+1];
            strcpy(ime, p.ime);
            broj_turi = p.broj_turi;
            broj_chlen = p.broj_chlen;
        }
        return *this;
    }
    
    PlDrustvo operator +(const PlDrustvo &p)
    {
      if(broj_chlen >= p.broj_chlen)
          return PlDrustvo(ime, broj_turi, broj_chlen + p.broj_chlen);
        else
            return PlDrustvo(p.ime, p.broj_turi, broj_chlen + p.broj_chlen);
    }
    
    bool operator >= (const PlDrustvo &p)
    {
        return (broj_chlen >= p.broj_chlen);
    }
    
     bool operator < (const PlDrustvo &p)
    {
        return (broj_chlen >= p.broj_chlen);
    }

    friend ostream &operator << (ostream &o, const PlDrustvo &p)
    {
        o << "Ime: " << p.ime << " Turi: " << p.broj_turi << " Clenovi: " << p.broj_chlen << endl;
        return o;
    }
    ~PlDrustvo(){
        delete [] ime;
    }
    
    int getClen() {
    return broj_chlen;
    }
};

void najmnoguClenovi(PlDrustvo *drustva, int n)
{
cout << "Najmnogu clenovi ima planinarskoto drustvo: ";
    bool first = true;
    PlDrustvo temp;
    for(int i = 0; i<n; i++){
        if(first){
            temp = drustva[i];
            first = false;
            continue;
        }
       if(drustva[i].getClen()>=temp.getClen())
       {
           temp = drustva[i];
       }
    }
    cout << temp;
}


int main()
{        		
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;
    	
   	}
    
    pl = drustva[0] + drustva[1];
    cout<<pl;
    
    najmnoguClenovi(drustva, 3);
    
    return 0;
}
