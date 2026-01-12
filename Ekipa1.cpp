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
		const char *getime(){
			return ime;
		}
		const char *getgrad(){
			return grad;
		}
		const char *getstadion(){
			return stadion;
		}
		void setime(char *ime){
			strcpy(this->ime,ime);
		}
		~Ekipa(){
		}
};
int main(){
	Ekipa *e1=new Ekipa("Real Madrid", "Madrid", "Santiago");
	Ekipa *e2=new Ekipa(*e1);
	
	cout<<"Ekipite se: ";
	cout<<e1->getime();
	cout<<"-";
	cout<<e2->getime();
	
	e1->setime("Barselona");
	
	cout<<"\nPo promenata ekipite se: ";
	cout<<e1->getime();
	cout<<"-";
	cout<<e2->getime();
	
	delete e1;
	delete e2;
	
	return 0;
}





















