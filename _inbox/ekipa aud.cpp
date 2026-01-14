#include <iostream>
#include <cstring>
using namespace std;

class Ekipa{
	private:
		int godina;
		char ime[20];
		char grad[20];
	public:
		Ekipa(int godina=0, char *ime="", char *grad="")
		{
			this->godina=godina;
			strcpy(this->ime, ime);
			strcpy(this->grad, grad);
		}
		Ekipa(const Ekipa &e)
		{
			godina= e.godina;
			strcpy(ime, e.ime);
			strcpy(grad, e.grad);
		}
		const char *getIme()
		{
			return ime;
		}
		~Ekipa()
		{
		}
};
class Natprevar{
	private: 
		Ekipa domakin, gostin;
		int golovidomakin, golovigostin;
	public:
		Natprevar(const Ekipa &d, const Ekipa &g, int gDom, int gGost)
		{
			domakin=d;
			gostin=g;
			golovidomakin=gDom;
			golovigostin=gGost;
		}
		Ekipa getdomakin()
		{
			return domakin;
		}
		Ekipa getgostin()
		{
			return gostin;
		}
		int getgolovidomakin()
		{
			return golovidomakin;
		}
		int getgolovigostin()
		{
			return golovigostin;
		}
		~Natprevar()
		{
		}
};
bool revans(Natprevar n1, Natprevar n2)
{
	if((strcmp(n1.getdomakin().getIme(),n2.getgostin().getIme())==0)&&strcmp(n1.getgostin().getIme(),n2.getdomakin().getIme())==0)
	{
		return true;
	}
	return false;
}
Ekipa duel(Natprevar n1, Natprevar n2)
{
	if (revans(n1,n2))
	{
		int gol1=n1.getgolovidomakin()+n2.getgolovigostin();
		int gol2=n2.getgolovidomakin()+n1.getgolovigostin();
		if(gol1>gol2)
		return n1.getdomakin();
		else if (gol1<gol2)
		return n1.getgostin();
		else if (n1.getgolovigostin()>n2.getgolovigostin())
		return n1.getgostin();
		else if (n1.getgolovigostin()<n2.getgolovigostin())
		return n1.getdomakin();
		else return 0;
	}
	else
	{
		cout<<"Ne se sofpagjaat"<<endl;
		return 0;
	}
}
int main()
{
	Ekipa e1(1880, "Real Madrid", "Madrid");
  	Ekipa e2(1880, "FC Barcelona", "Barcelona");
  	
  	Natprevar n1(e1,e2,2,0);
  	Natprevar n2(e2,e1,1,0);
  	
  	cout<<duel(n1,n2).getIme();
  	return 0;
}


















