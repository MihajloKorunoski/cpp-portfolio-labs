#include <iostream>
using namespace std;
class saat{
	private:
		int chas,min,sec;
	public:
		saat(){
			chas=min=sec=0;
		}
		saat(int chas, int min, int sec){
			postavisaat(chas,min,sec);
		}
		void postavisaat(int chas=0, int min=0, int sec=0){
			if(0<=chas&&chas<24)
				this->chas=chas;
			else
				this->chas=chas%24;
			if(0<=min&&min<60)
				this->min=min;
			else
				this->min=min%60;
			if(0<=sec&&sec<60)
				this->sec=sec;
			else
				this->sec=sec%60;
		}
		void zemisaat(int &chas, int &min, int&sec){
			chas=this->chas;
			min=this->min;
			sec=this->sec;
		}
		void prikazhisaat(){
			zemisaat(chas,min,sec);
			(chas<10) ? cout<<"\n" : cout<<"\n";
			cout<<"Tochno "<<chas<<":"<<min<<":"<<sec<<endl;
			cout<<endl;
		}
		void prikazhisaat(saat t){
			(chas<10) ? cout<<"\n" : cout<<"\n";
			cout<<"Tochno "<<t.chas<<":"<<t.min<<":"<<t.sec<<endl;
			cout<<endl;
		}
};
int main(){
	int chas,min,sec;
	saat mojsaat;
	mojsaat.postavisaat(8,19,40);
	saat tvojsaat(8,20,40);
	cout<<"Mojot saat e ";
	mojsaat.prikazhisaat();
	cout<<"Tvojot saat e ";
	tvojsaat.prikazhisaat();
	
	cout<<endl<<"\nVnesete vreme za mojot saat:"<<endl;
	cout<<"Chas: ";
	cin>>chas;
	cout<<"Minuti: ";
	cin>>min;
	cout<<"Sekundi: ";
	cin>>sec;
	mojsaat.postavisaat(chas,min,sec);
	
	cout<<endl<<"\nVnesete vreme za tvojot saat:"<<endl;
	cout<<"Chas: ";
	cin>>chas;
	cout<<"Minuti: ";
	cin>>min;
	cout<<"Sekundi: ";
	cin>>sec;
	tvojsaat.postavisaat(chas,min,sec);
	
	cout<<endl<<"Nashite saati pokazhuvaat:"<<endl;
	cout<<"Mojot saat e ";
	mojsaat.prikazhisaat(mojsaat);
	cout<<"Tvojot saat e ";
	tvojsaat.prikazhisaat(tvojsaat);
	
	cout<<endl;
	system("PAUSE");
	return 0;
}












