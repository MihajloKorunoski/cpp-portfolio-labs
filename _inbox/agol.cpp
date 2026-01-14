#include <iostream>
using namespace std;
class Agol
{
	private:
		int stepeni;
		int minuti;
		int sekundi;
	public:
		Agol(int stepeni=0, int minuti=0, int sekundi=0)
		{
			this->stepeni=stepeni;
			this->minuti=minuti;
			this->sekundi=sekundi;
		}
		~Agol(){}
		void set_minuti(int min)
		{
			min=this->minuti;
		}
		void set_stepeni(int ste)
		{
			ste=this->stepeni;
		}
		void set_sekundi(int sec)
		{
			sec=this->sekundi;
		}
		int getStepeni()
		{
			return stepeni;
		}
		int getMinuti()
		{
			return minuti;
		}
		int getSekundi()
		{
			return sekundi;
		}
		int to_sekundi()
		{
			return getStepeni()*3600+getMinuti()*60+getSekundi();
		}
		
};
bool proveri (int stepeni, int minuti, int sekundi)
{
	return (stepeni>=0&&stepeni<=360&&minuti<=59&&minuti>=0&&sekundi>=0&&sekundi<=59)? true: false;
}
bool changeofseconds(Agol a, int sec)
{
	return a.getSekundi()!=sec;
}
int main()
{
	int deg,min,sec;
	cin>>deg>>min>>sec;
	Agol a1(deg,min,sec);
	if(proveri(deg,min,sec))
	{
		a1.set_stepeni(deg);
		a1.set_minuti(min);
		a1.set_sekundi(sec);
		cout<<a1.to_sekundi();
		if(changeofseconds(a1,sec))
			cout<<"Ne smeete da gi menuvate sekundite vo ramkite na klasata!"<<endl;
	}
	else
	cout<<"Nevalidni vrednosti za agol"<<endl;
	return 0;
}

