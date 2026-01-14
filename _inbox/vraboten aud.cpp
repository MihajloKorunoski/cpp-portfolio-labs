#include <iostream>
#include <cstring>
using namespace std;

enum position {
	employee,manager,owner
};

class Person
{
	private:
		char name[100];
		int salary;
		position pos;
	public:
		Person()
		{
		}
		Person(char *n, int s, position p)
		{
			strcpy(name,n);
			salary=s;
			pos=p;
		}
		~Person()
		{
		}
		void setName(char const *n)
		{
			strcpy(name, n);
		}
		void setSalary(int const s)
		{
			salary=s;
		}
		void setPosition( position p)
		{
			pos=p;
		}
		char const *getName()
		{
			return name;
		}
		int const getSalary()
		{
			return salary;
		}
		position const getPosition()
		{
			return pos;
		}
		
};
std::istream& operator>>( std::istream& is, position& i )
{
    int tmp ;
    if ( is >> tmp )
        i = static_cast<position>( tmp ) ;
    return is ;
}
void sort(Person a[],int n)
		{
			int i,j;
			Person p;
			for (i=0; i<n-1;i++)
				for (j=i; j<n;j++)
				{
					if(a[i].getSalary()<a[j].getSalary())
					p=a[j];
					a[j]=a[i];
					a[i]=p;
				}
		}
int main()
{
	Person employees[100];
	float salary;
	int n;
	position pos;
	char name[100];
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>name;
		cin>>salary;
		cin>>pos;
		employees[i].setName(name);
		employees[i].setSalary(salary);
		employees[i].setPosition(pos);
	}
	sort(employees,n);
	for (int i=0;i<n;i++)
	{
		cout<<i+1<<". "<<employees[i].getName()<<"\t";
		cout<<employees[i].getSalary()<<"\t";
		cout<<employees[i].getPosition()<<endl;
	}
	return 0;
}





























