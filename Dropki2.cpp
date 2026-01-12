#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Dropka{
		friend void operator!(Dropka&);
		friend ostream& operator<<(ostream&,const Dropka);
	private:
		int broitel;
		int imenitel;
	public:
		Dropka(int broitel,int imenitel){
			this->broitel=broitel;
			this->imenitel=imenitel;
		}
		~Dropka(){
		}
		Dropka operator+(Dropka d){
			return Dropka(broitel*d.imenitel+imenitel*d.broitel, imenitel*d.imenitel);
		}
		Dropka operator-(Dropka d){
			return Dropka(broitel*d.imenitel- imenitel*d.broitel, imenitel*d.imenitel);
		}
		Dropka operator*(Dropka d){
			return Dropka(broitel*d.broitel, imenitel*d.imenitel);
		}
		Dropka operator/(Dropka d){
			return Dropka(broitel*d.imenitel,imenitel*d.broitel);
		}
};

ostream& operator<<(ostream& output,const Dropka d){
	output<<d.broitel<<" / "<<d.imenitel;
	return output;
}
int NZD(int a, int b){
	do{
		if(a==b)
			break;
		if(a<b)
			b=b-a;
		else
			a=a-b;
	}while(a!=b);
	return a;
}
void operator!(Dropka& d){
	int nzd=NZD(abs(d.broitel),abs(d.imenitel));
	d.broitel/=nzd;
	d.imenitel/=nzd;
}
int main(){
	Dropka A{1,4}, B{6,8};
	!A; !B;
	cout<<"Za dropkite: \nA = ";
	cout<<A;
	cout<<" i \nB = ";
	cout<<B;
	cout<<endl<<endl;
	Dropka aplusb= A + B;
	!aplusb;
	Dropka aminusb= A - B;
	!aminusb;
	Dropka apob= A * B;
	!apob;
	Dropka avrzb= A / B;
	!avrzb;
	cout<<setw(20)<<"Zbirot        a + b = ";
	cout<<aplusb<<endl;
	cout<<setw(20)<<"Razlikata     a - b = ";
	cout<<aminusb<<endl;
	cout<<setw(20)<<"Proizvodot    a * b = ";
	cout<<apob<<endl;
	cout<<setw(20)<<"Kolichnikot   a / b = ";
	cout<<avrzb<<endl<<endl;
	system("PAUSE");
	return 0;
}



























