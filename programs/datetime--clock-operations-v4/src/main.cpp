 #include<iostream>
 using namespace std;
 
 class Saat{
		friend Saat operator/(Saat, Saat);
	private:
		int chas;
		int minuti;
		int sekundi;
	public:
		Saat(){
			chas=minuti=sekundi=0;
		}
		Saat(int chas,int minuti, int sekundi){
			postavisaat(chas,minuti,sekundi);
		}
		void postavisaat(int chas,int minuti,int sekundi){
			this->chas=chas;
			this->minuti=minuti;
			this->sekundi=sekundi;
		}
		void prikazhivreme(Saat t){
			if(t.chas<10)
				cout<<" ";
			cout<<t.chas<<" saati, "<<t.minuti<<" minuti i"<<t.sekundi<<" sekundi";
		}
		Saat operator-(Saat tstart){
			int sekundirazlika,minutirazlika,chasrazlika;
			sekundirazlika=sekundi-tstart.sekundi;
			if(sekundirazlika<0){
				sekundirazlika+=60;
				minuti--;
			}
			minutirazlika=minuti-tstart.minuti;
			if(minutirazlika<0){
				minutirazlika+=60;
				chas--;
			}
			chasrazlika=chas-tstart.chas;
			return Saat(chasrazlika,minutirazlika,sekundirazlika);
		}
 };
 Saat operator/(Saat tstop, Saat tstart){
 	int chas,minuti,sekundi;
 	sekundi=tstop.sekundi-tstart.sekundi;
 	if(sekundi<0){
 		sekundi+=60;
 		tstop.minuti--;
	 }
	 minuti=tstop.minuti-tstart.minuti;
	 if(minuti<0){
	 	minuti+=60;
	 	tstop.chas--;
	 }
	 chas=tstop.chas-tstart.chas;
	 return Saat(chas,minuti,sekundi);
 }
 int main(){
 	Saat start(9,12,34);
 	Saat stop(12,7,15);
 	Saat vreme;
 	
 	cout<<"So operatorska funkcija chlenka na klasata: "<<endl;
 	vreme=stop-start;
 	vreme.prikazhivreme(vreme);
 	
 	stop={12,7,15};
 	cout<<endl<<endl<<"So prijatelska operatorska funkcija: "<<endl;
 	vreme=stop/start;
 	vreme.prikazhivreme(vreme);
 	
 	cout<<endl<<endl;
 	system("PAUSE");
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
