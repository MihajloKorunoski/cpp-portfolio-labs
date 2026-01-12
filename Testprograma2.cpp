#include<iostream>
using namespace std;
class Employee{
	public:
		double getSalary(){
			return 1;
		}
};
class HourlyEmployee : public Employee{
	int h;
	public:
		HourlyEmployee(int _h) : h(_h){
		}
		double getSalary(){
			if (h>0) 
				return h;
			else return Employee::getSalary();
		}
};
int main(){
	HourlyEmployee e(100);
	cout<<e.getSalary();
	return 0;
}
