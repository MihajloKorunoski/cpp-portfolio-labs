#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
 
static int uchenik=0;
 
int main()
{
    int izbor;
    while(1)
    {
        cout<<"\n Izberi Edno od Ponudenite :: \n \n";
        cout<<"1) Dodadi Nov Uchenik\n";
        cout<<"2) Izmeni \n";
        cout<<"3) Izbrishi\n";
        cout<<"4) Prikazhi \n";
        cout<<"5) Izlez\n";
        cout<<"\Vnesi go tvojot izbor :: ";
        cin>>izbor;
 
        switch (izbor)
        {
          case 1 :
                {
                     ofstream fout;
                     fout.open("primer.txt",ios::out | ios::app);
                     cout<<"\n\nVnesi Detali od Studentot :: \n";
                     cout<<"\nVnesi Chetiricifrena Shifra na Student :: ";
                     int shifra;
                     cin>>shifra;
                     if(shifra<1000||shifra>9999)
					 {
					 cout<<"Shifrata mora da e chetiricifrena!"<<endl;
					 cout<<"Vnesi povtorno :: ";
					 cin>>shifra;
                     }
                     fout<<shifra;
                     cout<<"\nVnesi ime :: ";
                     string name;
                     cin>>name;
                     fout<<"\t\t"<<name;
                     cout<<"\nVnesi Prezime :: ";
                     string surname;
                     cin>>surname;
                     fout<<" "<<surname;
                     cout<<"\nVnesi Vozrast :: ";
                     int godini;
                     cin>>godini;
                     if(godini<15||godini>19)
					 {
					 cout<<"Uchenikot mora da ima od 15 do 19 godini!"<<endl;
					 cout<<"Vnesi povtorno :: ";
					 cin>>godini;
                     }
                     fout<<"\t\t\t"<<godini;
                     cout<<"\nVnesi Ocenka Po Programski jazik :: ";
                     int ocenka;
                     cin>>ocenka;
                     if(ocenka<1||ocenka>5)
					 {
					  cout<<"Takva ocenka e nevozmozhna!"<<endl;
					  cout<<"Vnesi povtorno :: ";
					  cin>>ocenka;
                     }
                     fout<<"\t\t"<<ocenka<<endl;
                     uchenik++; 
					 fout.close(); 
                }
                 break;

          case 2 :
                {
    				 std::string shifra;
    				 cout<<"Vnesi Shifra na Student Koj Sakash da go izmenish :: ";
    				 cin >> shifra; 
    				 ifstream read("primer.txt", ios::out | ios::app);
    				 ofstream write("primer2.txt", ios::out | ios::app); 
    				 if (read.is_open()) 
					 {
       				 std::string line;
      				 while (getline(read, line)) 
					 {
          		   	 if (line.find(shifra) == std::string::npos)
            		  write<<line<<endl;
       				 }
    				 } 
					 else 
					 {
       				 std::cerr << "Datotekata ne mozhe da se otvori\n";
   					 }

    				 read.close();
   					 write.close();
    				 std::remove("primer.txt");
    				 std::rename("primer2.txt", "primer.txt");
                     cout<<"\nVnesi Chetiricifrena Shifra na Student :: ";
                     int shifra2;
                     cin>>shifra2;
                     if(shifra2<1000||shifra2>9999)
					 {
					 cout<<"Shifrata mora da e chetiricifrena!"<<endl;
					 cout<<"Vnesi povtorno :: ";
					 cin>>shifra;
                     }
                     cout<<"\nVnesi ime :: ";
                     string name;
                     cin>>name;
                     cout<<"\nVnesi Prezime :: ";
                     string surname;
                     cin>>surname;
                     cout<<"\nVnesi Vozrast :: ";
                     int godini;
                     cin>>godini;
                     if(godini<15||godini>19)
					 {
					 cout<<"Uchenikot mora da ima od 15 do 19 godini!"<<endl;
					 cout<<"Vnesi povtorno :: ";
					 cin>>godini;
                     }
                     cout<<"\nVnesi Ocenka Po Programski jazik :: ";
                     int ocenka;
                     cin>>ocenka;
                     if(ocenka<1||ocenka>5)
					 {
					  cout<<"Takva ocenka e nevozmozhna!"<<endl;
					  cout<<"Vnesi povtorno :: ";
					  cin>>ocenka;
                     }
                     ofstream fout;
                     fout.open("primer.txt", ios::app | ios::out);
                     fout<<shifra2;
                     fout<<"\t\t"<<name;
                     fout<<" "<<surname;
                     fout<<"\t\t\t"<<godini;
                     fout<<"\t\t"<<ocenka<<endl;
                     uchenik++; 
					 fout.close(); 
                }
                 break;
          case 3 :
					{
    				std::string shifra;
    				cout<<"Vnesi Shifra na Student Koj Sakash da go izbrishish :: ";
    				cin >> shifra; 
    				ifstream read("primer.txt", ios::out | ios::app);
    				ofstream write("primer2.txt", ios::out | ios::app); 
    				if (read.is_open()) 
					{
       				std::string line;
      				 while (getline(read, line)) 
					{
          			if (line.find(shifra) == std::string::npos)
            		 write<<line<<endl;
       				}
    				} 
					else 
					{
       				std::cerr << "Datotekata ne mozhe da se otvori\n";
   					}

    				read.close();
   					write.close();
    				std::remove("primer.txt");
    				std::rename("primer2.txt", "primer.txt");
					}
				break;
          case 4 :
                {
                	 system("CLS");
                	 std::ifstream fin;
                     std::string line;
                     fin.open("primer.txt",ios::in);
                     cout<<"\t\tShifra:";
                     cout<<"\t\tIme i Prezime:";
                     cout<<"\t\t\tVozrast:";
                     cout<<"\tOcenka:"<<endl; 
                     while(fin)
                     {
                     std::getline(fin, line);
                     cout<<"\t\t"<<line<<endl;
                     }
                     fin.close();
                }
                break;
         case 5  :
                exit(0);
 
          default :
                cout<<"\n Nepravilen Vnes Obidi se povtorno \n";
          }
    }
    return 0;
}
