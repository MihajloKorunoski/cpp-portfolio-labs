#include<iostream>
using namespace std;

class Vektor{
		friend Vektor operator*(Vektor,Vektor);
	private:
		double x;
		double y;
		double z;
	public:
		Vektor(double=0.0,double=0.0,double=0.0);
		double zemix();
		double zemiy();
		double zemiz();
		void prikazhivektor(Vektor);
		Vektor operator%(Vektor);
};

Vektor::Vektor(double x,double y,double z){
	this->x=x;
	this->y=y;
	this->z=z;
}
double Vektor::zemix(){
	return x;
}
double Vektor::zemiy(){
	return y;
}
double Vektor::zemiz(){
	return z;
}
void Vektor::prikazhivektor(Vektor u){
	cout<<"("<<u.zemix()<<","<<u.zemiy()<<","<<u.zemiz()<<")";
}
Vektor Vektor::operator%(Vektor v){
	Vektor w;
	w.x=this->y*v.z-this->z*v.y;
	w.y=this->z*v.x-this->x*v.z;
	w.z=this->x*v.y-this->y*v.x;
	return w;
}
Vektor operator*(Vektor u,Vektor v){
	Vektor w;
	w.x=u.y*v.z-u.z*v.y;
	w.y=u.z*v.x-u.x*v.z;
	w.z=u.x*v.y-u.y*v.x;
	return w;
	
}

int main(){
	Vektor a(1,2,-1), b(2,-1,1);
	
	cout<<"\nVektorski proizvod so funkcija chlenka na klasata:\n";
	Vektor c=a%b;
	Vektor d=a.operator%(b);
	a.prikazhivektor(a);
	cout<<" x ";
	b.prikazhivektor(b);
	cout<<" = ";
	c.prikazhivektor(c);
	cout<<endl;
	d.prikazhivektor(d);
	
	cout<<"\nVektorski proizvod so samostojna funkcija \n";
	Vektor e=a*b;
	Vektor f=operator*(a,b);
	a.prikazhivektor(a);
	cout<<" x ";
	b.prikazhivektor(b);
	cout<<" = ";
	e.prikazhivektor(c);
	cout<<endl;
	f.prikazhivektor(d);
	
	cout<<endl;
	system("PAUSE");
	return 0;
}






