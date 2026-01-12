#include<iostream>
#include<string>
using namespace std;
string denovi[7]={"Ponedelnik", "Vtornik", "Sreda", "Chetvrtok", "Petok", "Sbota", "Nedelja"};
string meseci[12]={"Januari", "Fevruari", "Mart", "April", "Maj", "Juni", "Juli", "Avgust", "Septemvri", "Oktomvri", "Noemvri", "Dekemvri"};
int denovivomesec[]={31,28,31,30,31,30,31,31,30,31,30,31};
class Godina{
	private:
		int godina;
	public:
		Godina(){
			godina=1;
		}
		Godina(int godina){
			postavigodina(godina);
		}
		void postavigodina(int godina){
			this->godina=godina;
		}
		void zemigodina(int &godina){
			godina=this->godina;
		}
		bool prestapnagodina(int godina){
			bool dane=false;
			if(godina %100==0){
				if(godina % 400 == 0)
					dane=true;
			}
			else if (godina % 4==0)
				dane=true;
			return dane;
		}
		string prvijanuari(int godina){
			int denovivogodina[40000];
			int sumadenovi=0;
			for(int i=1; i<godina;i++){
				denovivogodina[i]=365;
				if(prestapnagodina(i))
				denovivogodina[i]++;
				sumadenovi+=denovivogodina[i];
			}
			return denovi[sumadenovi % 7];
		}	
		int redendenvonedelata(string den){
			int i=-1;
			do{
				i++;
			}while (den.compare(denovi[i])!=0);
			return 0;
		}
		string rodenden(string rodenden,int denovivomesec[]){
			int den=stoi(rodenden.substr(0,2));
			int mesec=stoi(rodenden.substr(3,2));
			int godina=stoi(rodenden.substr(6,4));
			
			Godina ovaa;
			if(ovaa.prestapnagodina(godina))
				denovivomesec[1]++;
			int suma=0;
			for(int i=0;i<mesec-1;i++){
				suma+=denovivomesec[i];
			}
			suma+=den;
			string prvi=ovaa.prvijanuari(godina);
			int prvireden=redendenvonedelata(prvi);
			int rodendenreden=(prvireden+(suma%7)-1)%7;
			return denovi[rodendenreden];
		}
};
int main(){	
	
	string rodenden;
	Godina taagodina;
	cout<<"Vnesete rodenden(dd.mm.gggg): "; 
	cin>>rodenden;
	string den=taagodina.rodenden(rodenden,denovivomesec);
	cout<<"Rodenden na "<<rodenden<<" e vo "<<den<<endl;
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}

