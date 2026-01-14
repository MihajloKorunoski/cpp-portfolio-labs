#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int studentid;
    string studentime,studentprezime;
    int studentocena;
public:
    Student();
    Student(int, string, string ,int);
    int zemiid();
    string zemiime();
    string zemiprezime();
    int zemiocena();
    void prikazhistudent();
};
Student::Student() {

}
Student::Student(int id, string ime, string prezime, int ocena) {
    studentid=id;
    studentime=ime;
    studentprezime=prezime;
    studentocena=ocena;
}
int Student::zemiid() {
    return studentid;
}
string Student::zemiime() {
    return studentime;
}
string Student::zemiprezime() {
    return studentprezime;
}
int Student::zemiocena() {
    return studentocena;
}
void Student::prikazhistudent() {
    cout<<left<<setw(10)<<zemiid()<<setw(15)<<zemiime()<<setw(15)<<zemiprezime()<<right<<setw(3)<<zemiocena()<<endl;
}

class Ispit{
private:
    string predmet,profesor;
    int brojnastudenti;
    Student studenti[100];
public:
    Ispit();
    Ispit(string, string,int ,Student[]);
    string zemipredmet();
    string zemiprofesor();
    void prikazhiispit();
};
Ispit::Ispit() {
    predmet=profesor="";
    for(int i=0;i<brojnastudenti;i++)
        studenti[i]=Student();
}
Ispit::Ispit(string predmet,string profesor, int brojnastudenti, Student studenti[]){
    this->predmet=predmet;
    this->profesor=profesor;
    this->brojnastudenti=brojnastudenti;
    for(int i=0;i<brojnastudenti;i++)
        this->studenti[i]=studenti[i];
}
string Ispit::zemipredmet() {
    return predmet;
}
string Ispit::zemiprofesor() {
    return profesor;
}
void Ispit::prikazhiispit() {
    cout<<"\t\tRezultati od ispit \n"<<"\nPredmet: \t"<<zemipredmet()<<"\nProfesor: \t"<<zemiprofesor()<<endl<<endl;
    cout<<setw(10)<<"ID"<<setw(15)<<"Ime    "<<setw(15)<<"Prezime"<<setw(11)<<"Ocena"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    for(int i=0;i<brojnastudenti;i++){
        cout<<right<<setw(2)<<i+1<<".\t";
        studenti[i].prikazhistudent();
    }
    cout<<"-----------------------------------------------------------------------"<<endl;
}
int main(){
    const int brojnastudenti=3;
    Student studenti[brojnastudenti];
    studenti[0]={123456,"Ethan","Miller", 10};
    studenti[1]={123457,"Ethan","Parker", 9};
    studenti[2]={123458,"Cole","Miller", 6};

    Ispit ovoj;
    ovoj = {"Diskretna Matematika", "Ryan Larson", brojnastudenti,studenti};

    ovoj.prikazhiispit();

    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}














