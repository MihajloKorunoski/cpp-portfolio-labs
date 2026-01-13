#include<iostream>
#include<cmath>
using namespace std;

class Kvadrat{
	private:
		double strana;
	public:
		Kvadrat();
		Kvadrat(double);
		double zemistrana();
		double zemiploshtina();
		Kvadrat operator+(Kvadrat);
		bool operator==(Kvadrat);
		void prikazhikvadrat();
};
Kvadrat::Kvadrat(){
}
Kvadrat::Kvadrat(double strana){
	this->strana=strana;
}
double Kvadrat::zemistrana(){
	return strana;
}
double Kvadrat::zemiploshtina(){
	return strana*strana;
}
Kvadrat Kvadrat::operator+(Kvadrat k){
	double a=sqrt(zemiploshtina()+k.zemiploshtina());
	return Kvadrat(a);
}
bool Kvadrat::operator==(Kvadrat k){
	return zemiploshtina()==k.zemiploshtina();
}
void Kvadrat::prikazhikvadrat(){
	cout<<"Kvadrat: a = "<<strana<<", Ploshtina = "<<zemiploshtina()<<endl;
}
int main(){
	double otsechkaa=3,otsechkab=4,otsechkac=5;
	Kvadrat K1(otsechkaa);
	Kvadrat K2(otsechkab);
	Kvadrat K3(otsechkac);
	Kvadrat Kzbir=K1+K2;
	bool dane=Kzbir==K3;
	cout<<"Dali otsechkite: "<<otsechkaa<<", "<<otsechkab<<" i "<<otsechkac<<" se strani na pravoagolen triagolnik? \n";
	if(dane)
		cout<<"DA";
	else
		cout<<"NE";
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
























