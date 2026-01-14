#include<iostream>
#include<cstring>
using namespace std;
class Rabotnik
{
	private:
		char ime[30];
		char prezime[30];
		int plata;
	public:
		Rabotnik()
		{
		}
		Rabotnik(char *ime, char *prezime, int plata):plata(plata)
		{
			strncpy(this->ime,ime,30);
			strncpy(this->prezime,prezime,30);
		}
		~Rabotnik(){
		}
		int getPlata()
		{
			return plata;
		}
		void pechati()
		{
			cout<<ime<<" "<<prezime<<" "<<plata<<endl;
		}
};
class Fabrika
{
	private:
		Rabotnik rabotnik[100];
		int brojvraboteni;
	public:
		Fabrika()
		{
		}
		Fabrika(const Rabotnik *rab, int brojvraboteni):brojvraboteni(brojvraboteni)
		{
			for(int i=0;i<100;i++)
			{
				rabotnik[i]=rab[i];
			}
		}
		~Fabrika()
		{
		}
		void pecativraboteni()
		{
			for(int i=0;i<brojvraboteni;i++)
			{
				rabotnik[i].pechati();
			}
		}
		void pechatisoplata(int plata)
		{
			for(int i=0;i<brojvraboteni;i++)
			{
				if(rabotnik[i].getPlata()>=plata)
				rabotnik[i].pechati();
			}
		}
};
int main()
{
	int n, minimalna;
	cin>>n;
	Rabotnik *rabotnik= new Rabotnik[n];
	
	for (int i=0;i<n;i++)
	{
		char ime[30],prezime [30];
		int plata;
		cin>>ime>>prezime>>plata;
		rabotnik[i]=Rabotnik(ime,prezime,plata);
	}
	Fabrika fab(rabotnik,n);
	
	cin>>minimalna;
	cout<<"Site vraboteni:"<<endl;
	fab.pecativraboteni();
	cout<<"Vraboteni so plata povisoka od "<<minimalna<<" :"<<endl;
	fab.pechatisoplata(minimalna);
	delete[] rabotnik;
}














