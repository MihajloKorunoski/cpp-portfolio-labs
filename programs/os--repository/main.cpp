#include<iostream>
#include<cstring>
using namespace std;

enum Tip{LINUX,UNIX,WINDOWS
};
class OperativenSistem{
	private:
		char *ime;
		float verzija;
		Tip tip;
		float golemina;
	public:
		OperativenSistem(const char *ime=" ", float verzija=0, Tip tip=Tip(0),float golemina=0){
			this->verzija=verzija;
			this->golemina=golemina;
			this->tip=tip;
			this->ime=new char[strlen(ime)+1];
			strcpy(this->ime,ime);
		}
		OperativenSistem(const OperativenSistem &os){
			this->verzija=os.verzija;
			this->golemina=os.golemina;
			this->tip=os.tip;
			this->ime=new char[strlen(os.ime)+1];
			strcpy(this->ime,os.ime);
		}
		~OperativenSistem(){
			delete [] ime;
		}
		OperativenSistem &operator=(const OperativenSistem &os){
			if(this!=&os){
				this->verzija=os.verzija;
				this->golemina=os.golemina;
				this->tip=os.tip;
				delete [] ime;
				this->ime= new char[strlen(os.ime)+1];
				strcpy(this->ime,os.ime);
			}
		}
		void pechati(){
			cout<<"Ime: "<<ime<<" "<<"Verzija: "<<verzija<<" "<<"Tip: "<<" "<<"Golemina: "<<golemina<<"GB"<<endl;
		}
		bool ednakvise(const OperativenSistem &os){
				if((strcmp(ime,os.ime)==0)&&verzija==os.verzija&&golemina==os.golemina&&tip==os.tip){
					return true;
				}
				return false;
			}
		int sporediverzija(const OperativenSistem &os){
			if(verzija==os.verzija){
				return 0;
			}
			else if(verzija<os.verzija){
				return -1;
			}
			else
				return 1;
		}
		bool istafamilija(const OperativenSistem &sporedba){
			if(strcmp(ime,sporedba.ime)==0&&tip==sporedba.tip){
				return true;
			}
			return false;
		}
		float getverzija(){
			return verzija;
		}
};

class Reporzitorium{
	private:
		char ime[20];
		OperativenSistem *os;
		int brojos;
	public:
		Reporzitorium(const char *ime){
			strcpy(this->ime,ime);
			os=new OperativenSistem[0];
			brojos=0;
		}
		Reporzitorium(const Reporzitorium &r){
			strcpy(this->ime,r.ime);
			this->brojos=r.brojos;
			this->os=new OperativenSistem[r.brojos];
			for(int i=0;i<r.brojos;i++){
				this->os[i]=r.os[i];
			}
		}
		Reporzitorium &operator=(const Reporzitorium &r){
			if(this!=&r){
				strcpy(this->ime,r.ime);
				this->brojos=r.brojos;
				delete [] os;
				this->os=new OperativenSistem[r.brojos];
				for(int i=0;i<r.brojos;i++){
					this->os[i]=r.os[i];
				}
			}
			return *this;
		}
		~Reporzitorium(){
			delete [] os;
		}
		void izbrishi(const OperativenSistem &operativensistem){
			int novbroj=0,j=0;
			for(int i=0;i<brojos;i++){
				if(!(os[i].ednakvise(operativensistem))){
					novbroj++;
				}
			}
			OperativenSistem *temp=new OperativenSistem[novbroj];
			for(int i=0;i<brojos;i++){
				if(!(os[i].ednakvise(operativensistem))){
					temp[j]=os[i];
					j++;
				}
			}
			delete [] os;
			os=temp;
			brojos=novbroj;
		}
		void dodadi(const OperativenSistem &nov){
			int f=0;
			for(int i=0;i<brojos;i++){
				if(os[i].istafamilija(nov)&&os[i].sporediverzija(nov)==-1){
					f=1;
					break;
				}
			}
			if(f){
				for(int i=0;i<brojos;i++){
					if(os[i].istafamilija(nov)&&os[i].sporediverzija(nov)==-1)
					os[i]=nov;
				}
			}
			else{
				OperativenSistem* temp=new OperativenSistem[brojos+1];
				for(int i=0;i<brojos;i++){
					temp[i]=os[i];
				}
				temp[brojos]=nov;
				delete [] os;
				os=temp;
				brojos++;
			}
		}
		void pechatioperativnisistemi(){
			cout<<"Reporzitorium: "<<ime<<endl;
			for(int i=0;i<brojos;i++){
				this->os[i].pechati();
			}
		}
};
int main() {
    char repoName[20];
    cin>>repoName;
    Reporzitorium reporzitorium=Reporzitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        reporzitorium.dodadi(os);
    }

    reporzitorium.pechatioperativnisistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    reporzitorium.izbrishi(os);
    reporzitorium.pechatioperativnisistemi();
    return 0;
}






















