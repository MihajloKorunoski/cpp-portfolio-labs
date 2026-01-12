#include<iostream>
#include<iomanip>
using namespace std;

int NZS(int a, int b){
	int pom;
	if(b<a){
		pom=a;
		a=b;
		b=pom;
	}
	int nzs=b;
	do{
		nzs+=b;
	}while(nzs%a!=0);
	return nzs;
}
int NZD(int a, int b){
	do{
		if(a==b)
			break;
		(a<b)? b=b-a : a= a-b;
	} while(a!=b);
	return a;
}
void kratenjedropka(int& a,int& b){
	int nzd=NZD(abs(a),abs(b));
	a/=nzd;
	b/=nzd;
}
class Dropka{
	private:
		int broitel,imenitel;
	public:
		Dropka(){
		}
		Dropka(int broitel,int imenitel){
			this->broitel=broitel;
			this->imenitel=imenitel;
		}
		~Dropka(){
		}
		Dropka zbirnadropki(Dropka u,Dropka v){
			int nzsuv=NZS(u.imenitel,v.imenitel);
			return Dropka(u.broitel*(nzsuv/u.imenitel)+ v.broitel*(nzsuv/v.imenitel),nzsuv);
		}
		Dropka razlikanadropki(Dropka u,Dropka v){
			int nzsuv=NZS(u.imenitel,v.imenitel);
			return Dropka(u.broitel*(nzsuv/u.imenitel)- v.broitel*(nzsuv/v.imenitel),nzsuv);
		}
		Dropka proizvodnadropki(Dropka u,Dropka v){
			int bro=u.broitel*v.broitel;
			int ime=u.imenitel*v.imenitel;
			kratenjedropka(bro,ime);
			return Dropka(bro,ime);
		}
		Dropka kolichniknadropki(Dropka u,Dropka v){
			int bro=u.broitel*v.imenitel;
			int ime=u.imenitel*v.broitel;
			kratenjedropka(bro,ime);
			return Dropka(bro,ime);
		}
		void prikazhidropka(Dropka d){
			cout<<d.broitel<<" / "<<d.imenitel;
		}
};

int main(){
	Dropka u{2,9},  v{5,12};
	cout<<"Za dropkite: \nu = ";
	u.prikazhidropka(u);
	cout<<" i v = "; v.prikazhidropka(v);
	cout<<endl<<endl<<left;
	Dropka w;
	cout<<setw(20)<<"Zbirot u + v = ";
	w.prikazhidropka(w.zbirnadropki(u,v));
	cout<<endl;
	cout<<setw(20)<<"Razlikata u - v = ";
	w.prikazhidropka(w.razlikanadropki(u,v));
	cout<<endl;
	cout<<setw(20)<<"Proizvodot u * v = ";
	w.prikazhidropka(w.proizvodnadropki(u,v));
	cout<<endl;
	cout<<setw(20)<<"Kolichnikot u / v = ";
	w.prikazhidropka(w.kolichniknadropki(u,v));
	cout<<endl;
	
	cout<<endl;
	system("PAUSE");
	return 0;
}
