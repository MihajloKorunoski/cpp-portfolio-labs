#include<iostream>
#include<cstring>
using namespace std;
class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){
		}
		Date(int year,int month,int day){
			this->year=year;
			this->month=month;
			this->day=day;
		}
		Date(const Date& src){
			this->year=src.year;
			this->month=src.month;
			this->day=src.day;
		}
		void print(){
			cout<<year<<"."<<month<<"."<<day<<endl;
		}
};
class Person{
	private:
		char name[20];
		char surname[20];
	public:
		Person(){
			strncpy(this->name,"not specified",20);
			strncpy(this->surname,"not specified",20);
		}
		Person(char*name,char*surname){
			strncpy(this->name,name,20);
			strncpy(this->surname,surname,20);
		}
		~Person(){
		}
		void print(){
			cout<<name<<" "<<surname<<endl;
		}
};
class Car{
	private:
		Person owner;
		Date date;
		float price;
	public:
		Car(){
			price=0;
		}
		Car(Person owner,Date date, float price){
			this->owner=owner;
			this->date=date;
			this->price=price;
		}
		void print(){
			owner.print();
			date.print();
			cout<<"Price: "<<price<<endl;
		}
		float getPrice(){
			return price;
		}
};
void cheaperthan(Car* cars, int numcars, float price){
	for (int i=0;i<numcars;i++){
		float pricecar=cars[i].getPrice();
		if(pricecar<price){
			cars[i].print();
		}
	}
}
int main(){
	char name[20];
	char lastname[20];
	int year;
	int month;
	int day;
	float price;
	
	int testcase;
	cin>>testcase;
	
	if(testcase==1){
		cin>>name;
		cin>>lastname;
		Person lik(name,lastname);
		
		cin>>year;
		cin>>month;
		cin>>day;
		Date date(year,month,day);
		
		cin>>price;
		Car car(lik,date,price);
		
		car.print();
	}
	else if(testcase==2){
		cin>>name;
		cin>>lastname;
		Person lik(name,lastname);
		
		cin>>year;
		cin>>month;
		cin>>day;
		Date date(year,month,day);
		
		cin>>price;
		Car car(lik,date,price);
		
		car.print();
	}
	else if (testcase==3){
		int numcars;
		cin>>numcars;
		
		Car cars[10];
		for(int i=0;i<numcars;i++){
			cin>>name;
		cin>>lastname;
		Person lik(name,lastname);
		
		cin>>year;
		cin>>month;
		cin>>day;
		Date date(year,month,day);
		
		cin>>price;
		cars[i]={lik,date,price};

		}
		float pricelimit;
		cin>>pricelimit;
		cheaperthan(cars,numcars,pricelimit);
	}
	return 0;
}
























