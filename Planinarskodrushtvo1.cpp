#include<iostream>
#include<cstring>
using namespace std;

class Pldrushtvo{
	private:
		char *ime;
		int broj_turi;
		int broj_chlen;
	public:
		Pldrushtvo(const char *i="",int t=0,int c=0){
			this->ime=new char[strlen(i)+1];
			strcpy(ime,i);
			broj_turi=t;
			broj_chlen=c;
		}
		Pldrushtvo(const Pldrushtvo &p){
			ime=new char[strlen(p.ime)+1];
			broj_turi=p.broj_turi;
			broj_chlen=p.broj_chlen;
		}
		Pldrushtvo & operator =(const Pldrushtvo &p){
			if(this!=&p){
				delete[] ime;
				ime=new char[strlen(p.ime)+1];
				strcpy(ime,p.ime);
				broj_turi=p.broj_turi;
				broj_chlen=p.broj_chlen;
			}
		}
		Pldrushtvo operator +(const Pldrushtvo &p){
				return Pldrushtvo(ime,broj_turi,broj_chlen+p.broj_chlen);
		}
		bool operator >=(const Pldrushtvo &p){
			return (broj_chlen>=p.broj_chlen);
		}
		bool operator <(const Pldrushtvo &p){
			return (broj_chlen<p.broj_chlen);
		}
		friend ostream &operator <<(ostream &o, const Pldrushtvo &p){
			o<<"Ime: "<<p.ime<<" Turi:"<<p.broj_turi<<" Chlenovi: "<<p.broj_chlen<<endl; 
		}
		~Pldrushtvo(){
			delete [] ime;
		}
		int getchlen(){
			return broj_chlen;
		}
};

void najmnoguchlenovi(Pldrushtvo * drushtva, int n){
	cout<<"Najmnogu chlenovi ima planinarskoto drushtvo: ";
	bool first=true;
	Pldrushtvo temp;
	for(int i=0;i<n;i++){
		if(first){
			temp=drushtva[i];
			first=false;
			continue;
		}
		if(drushtva[i].getchlen()>=temp.getchlen()){
			temp=drushtva[i];
		}
	}
	cout<<temp;
}
int main()
{        		
    Pldrushtvo drustva[3];
    Pldrushtvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	Pldrushtvo p(ime,brTuri,brClenovi);
        drustva[i] = p;
    	
   	}
    
    pl = drustva[0] + drustva[1];
    cout<<pl;
    
    najmnoguchlenovi(drustva, 3);
    
    return 0;
}
























 
