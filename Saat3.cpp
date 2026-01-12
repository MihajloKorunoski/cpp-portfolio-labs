#include<iostream>
using namespace std;
class Saat{
	private:
		int chas;
		int minuti;
		int sekundi;
	public:
		Saat(){
			chas=minuti=sekundi=0;
		}
		Saat(int chas,int minuti,int sekundi){
			postaviSaat(chas,minuti,sekundi);
		}
		void postaviSaat(int chas,int minuti,int sekundi){
			this->chas=chas;
			this->minuti=minuti;
			this->sekundi=sekundi;
		}
		Saat vreme(Saat tstop){
			int sekundiRazlika,minutiRazlika,chasRazlika;
			sekundiRazlika=tstop.sekundi-sekundi;
			if(sekundiRazlika < 0){
				sekundiRazlika+=60;
				tstop.minuti-=1;
			}
			minutiRazlika=tstop.minuti-minuti;
			if(minutiRazlika < 0){
				minutiRazlika+=60;
				tstop.chas-=1;
			}
			chasRazlika=tstop.chas-chas;
			return Saat(chasRazlika,minutiRazlika,sekundiRazlika);
		}
		Saat vreme(Saat tstart, Saat tstop)
		{
			sekundi=tstop.sekundi-tstart.sekundi;
			if(sekundi < 0){
				sekundi+=60;
				tstop.minuti--;
			}
			minuti=tstop.minuti-tstart.minuti;
			if(minuti < 0){
				minuti+=60;
				tstop.chas-=1;
			}
			chas=tstop.chas-tstart.chas;
			return Saat(chas,minuti,sekundi);
		}
		void prikazhiVreme(Saat t){
			(chas<10) ? cout<<"\n" : cout<<"\n";
			cout<<"Tochno "<<t.chas<<":"<<t.minuti<<":"<<t.sekundi<<endl;
			cout<<endl;
		}
};
int main(){
	int chas,minuti,sekundi;
	cout<<"Vnesete pochetno vreme:"<<endl;
	cout<<"Chas: ";
	cin>>chas;
	cout<<"Minuti: ";
	cin>>minuti;
	cout<<"Sekundi: ";
	cin>>sekundi;
	Saat tStart(chas,minuti,sekundi);
	cout<<"Vnesete krajno vreme:"<<endl;
	cout<<"Chas: ";
	cin>>chas;
	cout<<"Minuti: ";
	cin>>minuti;
	cout<<"Sekundi: ";
	cin>>sekundi;
	Saat tStop(chas,minuti,sekundi);
	Saat trkach;
	cout<<endl<<"So funkcija chlenka so eden argument: "<<endl;
	trkach.prikazhiVreme(tStart.vreme(tStop));
	cout<<endl<<"So funkcija chlenka so dva argumenti: "<<endl;
	trkach.prikazhiVreme(tStart.vreme(tStart,tStop));
	cout<<endl<<endl;
	return 0;
}












