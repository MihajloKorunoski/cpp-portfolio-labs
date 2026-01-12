#include<iostream>
#include<cstring>
using namespace std;

class Potpishuvach{
	private:
		char ime[20];
		char prezime[20];
		char embg[14];
	public:
		Potpishuvach(){
			*ime='\0';
			*prezime='\0';
			*embg='\0';
		}
		Potpishuvach(char* ime , char* prezime, char* embg){
			strcpy(this->ime,ime);
			strcpy(this->prezime,prezime);
			strcpy(this->embg,embg);
		}
		Potpishuvach(const Potpishuvach& src){
			strcpy(this->ime,src.ime);
			strcpy(this->prezime,src.prezime);
			strcpy(this->embg,src.embg);
		}
		char* getEmbg(){
			return embg;
		}
};
class Dogovor{
	private:
		int brojnadogovor;
		char kategorijadogovor[50];
		Potpishuvach potpishuvachi[3];
	public:
		Dogovor(){
		}
		Dogovor(int brojnadogovor, char* kategorijadogovor,Potpishuvach* potpishuvachi):brojnadogovor(brojnadogovor){
			strncpy(this->kategorijadogovor,kategorijadogovor,50);
			for(int i=0; i<3;i++){
				this->potpishuvachi[i]=potpishuvachi[i];
			}
		}
		bool proverka(){
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					if((strcmp(potpishuvachi[i].getEmbg(),potpishuvachi[j].getEmbg())==0)&&(i!=j)){
						return true;
					}
				}
			}
			return false;
		}	
};
int main(){
	char embg[13], ime[20], prezime[20],kategorija[20];
	int broj, n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>embg>>ime>>prezime;
		Potpishuvach p1(ime,prezime,embg);
		cin>>embg>>ime>>prezime;
		Potpishuvach p2(ime,prezime,embg);
		cin>>embg>>ime>>prezime;
		Potpishuvach p3(ime,prezime,embg);
		cin>>broj>>kategorija;
		Potpishuvach p[3];
		p[0]=p1;
		p[1]=p2;
		p[2]=p3;
		Dogovor d(broj,kategorija,p);
		cout<<"Dogovor"<<broj<<":"<<endl;
		if(d.proverka()==true){
			cout<<"Postojat potpishuvachi so ist EMBG"<<endl;
		}
		else
			cout<<"Ne postojat potpishuvachi so ist EMBG"<<endl;
	}
	return 0;
}















