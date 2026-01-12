#include<iostream>
#include<cstring>
using namespace std;

class Ekipa{
	private:
		char ime[20];
		char grad[20];
		char stadion[30];
	public:
		Ekipa(char *ime="", char*grad="",char*stradion=""){
			strcpy(this->ime,ime);
			strcpy(this->grad,grad);
			strcpy(this->stadion,stadion);
		}
		Ekipa(const Ekipa &e){
			strcpy(ime,e.ime);
			strcpy(grad,e.grad);
			strcpy(stadion,e.stadion);
		}
		const char *getime()const{
			return ime;
		}
		const char *getgrad()const{
			return grad;
		}
		const char *getstadion()const{
			return stadion;
		}
		void setime(char *ime){
			strcpy(this->ime,ime);
		}
		~Ekipa(){
		}
};
class Natprevar{
	private:
		Ekipa *domakin,*gostin;
		int golovidomakin,golovigostin;
	public:
		Natprevar(const Ekipa &d,const Ekipa &g, int golovidomakin,int golovigostin){
			domakin=new Ekipa(d);
			gostin=new Ekipa(g);
			this->golovidomakin=golovidomakin;
			this->golovigostin=golovigostin;
		}
		Natprevar(const Natprevar& n){
			domakin=new Ekipa(*n.domakin);
			gostin=new Ekipa(*n.gostin);
			golovidomakin=n.golovidomakin;
			golovigostin=n.golovigostin;
		}
		Ekipa *getdomakin(){
			return domakin;
		}
		const Ekipa* getgostin(){
			return gostin;
		}
		int getgolovidomakin(){
			return golovidomakin;
		}
		int getgolovigostin(){
			return golovigostin;
		}
		~Natprevar(){
			cout<<"\nVo destruktor"<<endl;
			delete domakin;
			delete gostin;
		}
		friend bool istip(Natprevar n, char tip);
};
bool istip(Natprevar n, char tip){
	if (n.golovidomakin==n.golovigostin&& tip=='X')
	return true;
	if(n.golovidomakin>n.golovigostin &&tip=='1')
	return true;
	if(n.golovidomakin<n.golovigostin && tip=='2')
	return true;
	return false;
}
int main(){
	Ekipa e1("Real Madrid", "Madrid", "Santiago Bernabeu");
	Ekipa e2("FC Barcelona", "Barcelona","Camp Nou");
	
	Natprevar first(e1,e2,1,3);
	
	cout<<"Vnesi tip za natprevarot: ";
	cout<<first.getdomakin()->getime();
	cout<<"-";
	cout << first.getgostin()->getime();
	cout<<endl;
	
	char tip;
	cin>>tip;
	
	if(istip(first,tip))
	cout<<"Tipot et pogoden";
	else cout<<"Tipot ne et pogoden";
	
	first.getdomakin()->setime("RLM");
	
	cout<<"\nNatprevarot beshe megju: ";
	cout<<first.getdomakin()->getime();
	cout<<"-";
	cout<<first.getgostin()->getime();
	
	return 0;
}

























