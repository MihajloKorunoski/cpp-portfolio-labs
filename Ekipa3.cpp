#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Ekipa{
	private:
		char ime[20];
		char grad[20];
		char stadion[30];
	public:
		Ekipa(char *ime="", char*grad="",char*stadion=""){
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
void sort (Ekipa *p, int n){
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++){
			if(strcmp(p[i].getime(),p[j].getime())>0){
				Ekipa pom=p[i];
				p[i]=p[j];
				p[j]=pom;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	Ekipa *prvenstvo=new Ekipa[n];
	char ime[20],grad[20],stadion[30];
	
	for(int i=0;i<n;i++){
		cin>>ime>>grad>>stadion;
		prvenstvo[i]=Ekipa(ime,grad,stadion);
	}
	sort(prvenstvo,n);
	 for (int i = 0; i < n; i++) {
  		cout << i + 1 << " " << prvenstvo[i].getime() << " (" << prvenstvo[i].getgrad() <<", " << prvenstvo[i].getstadion() << ")" << endl;
  	}
  	delete [] prvenstvo;
  	
  	return 0;
}



























