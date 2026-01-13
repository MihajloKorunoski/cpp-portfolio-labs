#include<iostream>
#include<cstring>
using namespace std;
class Saat{
	private:
		string vreme;
	public:
		Saat(){
			vreme="";
		}
		Saat(string vreme){
			postaviSaat(vreme);
		}
		void postaviSaat(string vreme){
			this->vreme=vreme;
		}
		void zemiSaat(string &vreme){
			vreme=this->vreme;
		}
		string zemiSaat(){
			return vreme;
		}
		Saat konverzija12vo24(Saat v12){
			v12.zemiSaat(vreme);
			string PM= vreme.substr(9,2);
			string cc= vreme.substr(0,2);
			int casa=stoi(cc);
			if(PM.compare("PM")==0)
				casa+=12;
			if(casa==12)
				if(PM.compare("AM")==0)
				casa-=12;
			cc=to_string(casa);
			if(casa<10)
				cc="0"+cc;
			string minIsec=vreme.substr(3,5);
			string vreme=cc+":"+minIsec;
			return Saat(vreme); 
		}
		Saat konverzija24vo12(Saat v24){
			string PMAM="AM";
			v24.zemiSaat(vreme);
			string cc=vreme.substr(0,2);
			int casa=stoi(cc);
			if(casa>12){
				casa-=12;
				PMAM="PM";
			}
			if(casa==00){
				casa+=12;
			}
			cc=to_string(casa);
			if(casa<10)
				cc="0"+cc;
			string minIsec=vreme.substr(3,5);
			string vreme= cc+":"+minIsec+" "+PMAM;
			return Saat(vreme);
		}
};
int main()
{
	string vlez;
	string vreme12,vreme24;
	int i;
	Saat v12,v24;
	cout<<"Izberete konverzija:"<<endl<<"\t 12: 12 vo 24"<<endl<<"\t 24: 24 vo 12"<<endl;
	cout<<endl<<"Izbor: ";
	getline(cin,vlez);
	i=stoi(vlez);
	switch(i){
		case 12:
			cout<<endl<<"Vnesete vreme vo 12-chasoven format (cc:mm:ss AM/PM): ";
			getline(cin,vreme12);
			v12={vreme12};
			v24=v12.konverzija12vo24(v12);
			cout<<endl<<"Vremeto vo 12-chasoven format: "<<v12.zemiSaat()<<endl<<"Vremeto vo 24-chasoven format: "<<v24.zemiSaat()<<endl;
			break;
		case 24:
			cout<<endl<<"Vnesete vreme vo 24-chasoven format (cc:mm:ss):";
			getline(cin,vreme24);
			v24={vreme24};
			v12=v24.konverzija24vo12(v24);
			cout<<endl<<"Vremeto vo 24-chasoven format: "<<v24.zemiSaat()<<endl<<"Vremeto vo 12-chasoven format: "<<v12.zemiSaat()<<endl;
			break;
	}
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
