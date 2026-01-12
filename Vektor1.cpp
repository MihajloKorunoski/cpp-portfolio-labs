#include<iostream>
using namespace std;

class Vektor{
		friend void operator!(Vektor &);
		friend Vektor operator&(Vektor,Vektor);
		friend double operator*(Vektor,Vektor);
	private:
		double x;
		double y;
	public:
		Vektor(double=0.0,double=0.0);
		double zemix();
		double zemiy();
		void prikazhivektor(Vektor);
		Vektor operator-();
		Vektor operator+(Vektor&);
};

Vektor::Vektor(double x,double y){
	this->x=x;
	this->y=y;
}
double Vektor::zemix(){
	return x;
}
double Vektor::zemiy(){
	return y;
}
void Vektor::prikazhivektor(Vektor u){
	cout<<"("<<u.zemix()<<","<<u.zemiy()<<")";
}
Vektor Vektor::operator-(){
	return Vektor(-x,-y);
}
Vektor Vektor::operator+(Vektor &operand2){
	return Vektor(x+operand2.x,y+operand2.y);
}
void operator!(Vektor & v){
	v.x=-v.x;
	v.y=-v.y;
}
Vektor operator&(Vektor u, Vektor v){
	return Vektor(u.x+v.x,u.y+v.y);
} 
double operator*(Vektor u, Vektor v){
	return u.x*v.x+u.y*v.y;
}

int main(){
	Vektor a(4.3,8.2), b(3.3,1.1),c,d;
	cout<<"a = ";
	a.prikazhivektor(a);
	cout<<"\tb = ";
	b.prikazhivektor(b);
	cout<<endl;
	
	cout<<"\nNegacija so unaren operator, funkcija chlenka na klasata. (-a) \n";
	cout<<"-";
	a.prikazhivektor(a);
	a=-a;
	cout<<" = ";
	a.prikazhivektor(a);
	
	a=a.operator-();
	cout<<"\nZbir so binaren operator, funkcija chlenka na klasata. (a+b) \n";
	Vektor zbir=a+b;
	a.prikazhivektor(a);
	cout<<" + ";
	b.prikazhivektor(b);
	cout<<" = ";
	zbir.prikazhivektor(zbir);
	cout<<endl;
	
	Vektor zbir1=a.operator+(b);
	a.prikazhivektor(a);
	cout<<" + ";
	b.prikazhivektor(b);
	cout<<" = ";
	zbir.prikazhivektor(zbir);
	
	cout<<"\nNegacija so binaren operator, samostojna funkcija (!a) \n";
	cout<<"-";
	a.prikazhivektor(a);
	!a;
	cout<<" = ";
	a.prikazhivektor(a);
	
	operator!(a);
	cout<<"\nZbir so binaren operator, samostojna funkcija (a&b) \n";
	Vektor zbir2=a&b;
	a.prikazhivektor(a);
	cout<<" + ";
	b.prikazhivektor(b);
	cout<<" = ";
	zbir2.prikazhivektor(zbir2);
	cout<<endl;
	
	Vektor zbir3=operator&(a,b);
	a.prikazhivektor(a);
	cout<<" + ";
	b.prikazhivektor(b);
	cout<<" = ";
	zbir2.prikazhivektor(zbir2);
	
	cout<<"\nSkalaren proizvod so binaren operator, samostojna funkcija (a*b) \n";
	double skalarenproizvod= a*b;
	a.prikazhivektor(a);
	cout<<" * ";
	b.prikazhivektor(b);
	cout<<" = ";
	cout<<skalarenproizvod<<endl;
	
	double skalarenproizvod1= operator*(a,b);
	a.prikazhivektor(a);
	cout<<" * ";
	b.prikazhivektor(b);
	cout<<" = ";
	cout<<skalarenproizvod<<endl;
	
	cout<<endl;
	system("PAUSE");
	return 0;
}




















