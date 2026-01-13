#include<iostream>
using namespace std;

class Agol{
	private:
		int stepeni,minuti,sekundi;
	public:
		Agol(int stepeni=0,int minuti=0, int sekundi=0){
			set_stepeni(stepeni);
			set_minuti(minuti);
			set_sekundi(sekundi);
		}
		~Agol(){
		}
		void set_stepeni(int stepeni){
			this->stepeni=stepeni;
		}
		void set_minuti(int minuti){
			this->minuti=minuti;
		}
		void set_sekundi(int sekundi){
			this->sekundi=sekundi;
		}
		int getstepeni(){
			return stepeni;
		}
		int getminuti(){
			return minuti;
		}
		int getsekundi(){
			return sekundi;
		}
		int to_sekundi(){
			return getstepeni()*3600+getminuti()*60+getsekundi();
		}
};
bool proveri(int stepeni,int minuti,int sekundi){
	return (stepeni>=0&&stepeni<=359&&minuti<=59&&minuti>=0&&sekundi>=0&&sekundi<=59)? true : false;
}
bool changeofseconds(Agol a, int sec){
	return a.getsekundi()!=sec;
}

int main(){
	int deg,min,sec;
	cin>>deg>>min>>sec;
	Agol a1(deg,min,sec);
	if (proveri(deg,min,sec)){
		a1.set_stepeni(deg);
		a1.set_minuti(min);
		a1.set_sekundi(sec);
		cout<<a1.to_sekundi();
		if(changeofseconds(a1,sec)){
			cout<<"Ne smeete da gi menuvate sekundite vo ramkite na klasata!"<<endl;
		}
	}
	else
	cout<<"Nevalidni vrednosti za agol"<<endl;
	return 0;
}

















