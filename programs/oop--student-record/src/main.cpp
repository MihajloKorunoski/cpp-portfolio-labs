#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student{
	private:
		int index;
		string ime;
		string prezime;
		double uspeh;
	public:
		Student();
		Student(int, string, string);
		Student(int, string, string, double);
		void postaviindex(int);
		int zemiindex();
		string zemiime();
		string zemiprezime();
		double zemiuspeh();
		void prikazhistudent();
		void sortiranjespisok(Student*, int);
		void spisoknastudenti(Student*, int);
};

Student::Student(){
}
Student::Student(int index, string ime, string prezime,double uspeh){
	this->index=index;
	this->ime=ime;
	this->prezime=prezime;
	this->uspeh=uspeh;
}
Student::Student(int index, string ime, string prezime){
	this->index=index;
	this->ime=ime;
	this->prezime=prezime;
}
int Student::zemiindex(){
	return index;
}
string Student::zemiime(){
	return ime;
}
string Student::zemiprezime(){
	return prezime;
}
double Student::zemiuspeh(){
	return uspeh;
}
void Student::prikazhistudent(){
	cout<<endl<<"Student: ID: "<<zemiindex()<<" "<<zemiime()<<" "<<zemiprezime()<<" "<<zemiuspeh()<<endl;
} 
void Student::sortiranjespisok(Student studenti[], int brojnastudenti){
	Student pom;
	int brojach=1;
	do{
		for(int i=brojnastudenti-1;i>=brojach; i--){
			if(studenti[i].index<studenti[i-1].index){
				pom=studenti[i];
				studenti[i]=studenti[i-1];
				studenti[i-1]=pom;
			}
		}
		brojach++;
	} while(brojach<brojnastudenti);
}
void Student::spisoknastudenti(Student studenti[],int brojnastudenti){
	cout<<left<<setw(10)<<"red.br."<<setw(10)<<"Index"<<setw(15)<<"Prezime"<<setw(15)<<"Ime"<<setw(15)<<"Bodovi \n"<<endl;
	for(int i=0; i<brojnastudenti;i++){
		cout<<right<<setw(3)<<i+1<<left<<setw(7)<<".";
		studenti[i].prikazhistudent();
	}
}
int main(){
	int index;
	double uspeh;
	string ime, prezime;
	string vlez;
	cout<<"Vnesete gi studentite."<<endl;
	cout<<"Za kraj vnesete 9999 za index na student."<<endl;
	Student studenti[100];
	int i=-1;
	while(true){
		i++;
		cout<<left<<setw(15)<<"Index:   ";
		getline(cin,vlez);
		index=stoi(vlez);
		if(index==9999)
			break;
		cout<<left<<setw(15)<<"Ime: ";
		getline(cin,ime);
		cout<<left<<setw(15)<<"Prezime: ";
		getline(cin,prezime);
		cout<<left<<setw(15)<<"Bodovi: ";
		getline(cin,vlez);
		uspeh=stod(vlez);
		studenti[i]={index,ime,prezime,uspeh};
	}
	int brojnastudenti=i;
	Student nekoj;
	nekoj.sortiranjespisok(studenti, brojnastudenti);
	
	cout<<endl<<"\t\t SPISOK NA STUDENTI"<<endl;
	nekoj.spisoknastudenti(studenti,brojnastudenti);
	
	cout<<endl;
	system("PAUSE");
	return 0;
}


























