#include <iostream>
#include <cstring>
using namespace std;
class Date
{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){
		}
		Date(int year, int month, int day): year(year), month(month), day(day){
		}
		Date(const Date &src): year(src.year), month(src.month), day(src.day){
		}
		~Date(){
		}
		void print()
		{
			cout<<year<<"."<<month<<"."<<day<<endl;
		}
};
class Person
{
	private:
		char name[20];
		char surname[20];
	public:
		Person()
		{
			strncpy(this->name,"not specified", strlen(name));
			strncpy(this->surname,"not specified", strlen(surname));
		}
		Person(char* name,char* surname)
		{
			strncpy(this->name, name, strlen(name));
			strncpy(this->surname, surname, strlen(surname));
		}
		~Person()
		{
		}
		void print()
		{
			cout<<name<<" "<<surname<<endl;
		}
};
class Car
{
	private:
		Person owner;
		Date date;
		float price;
	public:
		Car(Person owner, Date date, float price): owner(owner), date(date), price(price)
		{
		}
		Car():price(0)
		{
		}
		void print()
		{
			owner.print();
			date.print();
			cout<<"Price: "<<price<<endl;
		}
		float getPrice()
		{
			return price;
		}
};
void cheaperThan(Car* cars, int numCars, float price)
{
	for (int i=0; i<numCars;i++)
	{
		float priceCar= cars[i].getPrice();
		if(priceCar<price)
		{
			if(priceCar<price)
			{
				cars[i].print();
			}
		}
		
	}
}

int main()
{
	char name[20];
	char lastname[20];
	int year;
	int month;
	int day;
	float price;
	
	int testCase;
	cin>>testCase;
	if(testCase==1)
	{
		cin>>name;
		cin>>lastname;
		Person lik(name,lastname);
		
		cin>>year;
		cin>>month;
		cin>>day;
		Date date(year, month,day);
		cin>>price;
		Car car(lik,date,price);
		car.print();
	}
	if(testCase==2)
	{
		cin>>name;
		cin>>lastname;
		Person lik(name,lastname);
		
		cin>>year;
		cin>>month;
		cin>>day;
		Date date(year, month,day);
		cin>>price;
		Car car(lik,date,price);
		car.print();
	}
	else
	{
		int numCars;
		cin>> numCars;
		
		Car cars[10];
		for(int i=0; i<numCars; i++)
		{
			cin >> name;
			cin >> lastname;
			Person lik(name, lastname);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
		float priceLimit;
		cin>>priceLimit;
		cheaperThan(cars,numCars,priceLimit);
	}
	
	return 0;
}






















