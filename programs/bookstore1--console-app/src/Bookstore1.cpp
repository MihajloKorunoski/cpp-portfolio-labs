#include<iostream>
#include<cstring>
#include<string>
using namespace std;

enum typeC{standard,loyal,vip, MAX=20
};

class Customer{
	friend class FINKI_bookstore;
	private:
		char ime[50];
		char eadresa[50];
		char a[10];
		typeC tip;
		static int osnovenpopust;
		static const int dopolnitelenpopust;
		int brojproiz;
	public:
		Customer(){
			ime[50]='\0';
			eadresa[50]='\0';
			tip=standard;
			brojproiz=0;
		}
		char * tip1()
    	{
    		if (tip==standard){
    			strcpy(a, "standard");
        		return a;
    		}
        	if (tip==loyal)
        		{
        		strcpy(a, "loyal");
        		return a;
        		}
        	if (tip==vip)
        	{
        	strcpy(a, "vip");
        	return a;
        	}
    	}
		Customer(char* ime, char* eadresa, typeC tip, int brojproiz){
			strcpy(this->ime,ime);
			strcpy(this->eadresa,eadresa);
			this->tip=tip;
			this->brojproiz=brojproiz;
		}
		void setDiscount1(int x)
    	{
    	osnovenpopust=x;
    	}
		Customer(const Customer & c){
			strncpy(ime,c.ime,50);
			strncpy(eadresa,c.eadresa,50);
			tip=c.tip;
			brojproiz=c.brojproiz;
		}
		
		int popust(){
			if(tip==0)
				return 0;
			if(tip==1)
				return osnovenpopust;
			return osnovenpopust+dopolnitelenpopust;
		}
		friend ostream& operator <<(ostream &out,Customer& p)
	{
		out<<p.ime<<endl<<p.eadresa<<endl<<p.brojproiz<<endl;
		out<<p.tip1()<<" "<<p.popust()<<endl;
		return out;
	}
};
int Customer::osnovenpopust=10;
const int Customer::dopolnitelenpopust=20;

class FINKI_bookstore{
	friend class Customer;
	private:
		Customer *p;
		int brojkupuvachi;
	public:
		FINKI_bookstore(){
			p=0;
			brojkupuvachi=0;
		}
		FINKI_bookstore(Customer *p, int brojkupuvachi){
			setCustomers(p,brojkupuvachi);
		}
		FINKI_bookstore(const FINKI_bookstore& d){
			delete [] p;
			brojkupuvachi=d.brojkupuvachi;
			p=new Customer[d.brojkupuvachi];
			for(int i=0;i<d.brojkupuvachi;i++){
				p[i]=d.p[i];
			}
		}
		void setCustomers(Customer *p, int brojkupuvachi){
			this->p=new Customer[brojkupuvachi];
			this->brojkupuvachi=brojkupuvachi;
			for(int i=0;i<brojkupuvachi;i++){
				this->p[i]=p[i];
			}
		}
		
		~FINKI_bookstore(){
			delete [] p;
		}
		FINKI_bookstore& operator+=(Customer &c){
			int imaist=0;
			for(int i=0;i<brojkupuvachi;i++){
				if(!strcmp(p[i].eadresa, c.eadresa)){
					imaist=1;
					throw 1;
				}
			}
			if(imaist==0){
				Customer * temp=new Customer[brojkupuvachi+1];
				for(int i=0;i<brojkupuvachi;i++){
					temp[i]=p[i];
				}
				temp[brojkupuvachi]=c;
				delete [] p;
				p=temp;
				brojkupuvachi++;
			}
			return *this;
		}
		void update(){
			for(int i=0 ;i<brojkupuvachi;i++){
				if(p[i].tip==standard&&p[i].brojproiz>5)
				p[i].tip=loyal;
				if(p[i].tip==loyal&&p[i].brojproiz>10)
				p[i].tip=vip;
			}
		}
		friend ostream & operator<<(ostream &out,FINKI_bookstore &f){
			for(int i=0;i<f.brojkupuvachi;i++){
				out<<f.p[i];
			}
			return out;
		}
	
};
int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
      try
      {
    fc+=c;
      }
      catch(...)
      {
      cout<<"The user already exists in the list!"<<endl;
      }
    
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;
   
}
