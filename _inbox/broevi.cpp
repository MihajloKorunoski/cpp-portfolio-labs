#include<iostream>
#include<cstring>
using namespace std;

class ArithmeticException{
public:
    void message(){
        cout<<"Division by zero is not allowed"<<endl;
    }
};

class NumbersNotDivisibleException{
    int n;
public:
    NumbersNotDivisibleException(int n){
        this->n=n;
    }
    void message(){
        cout<<"Division by "<<n<<" is not supported"<<endl;
    }
};

class ArrayFullException{
public:
    void message(){
        cout<<"The array is full. Increase the capacity"<<endl;
    }
};

class IndexOutOfBoundsException{
    int n;
public:
    IndexOutOfBoundsException(int n){
        this->n=n;
    }
    void message(){
        cout<<"Index "<<n<<" is out of bounds"<<endl;
    }
};

class NumberIsNotPositiveException{
    int n;
public:
    NumberIsNotPositiveException(int n){
        this->n=n;
    }
    void message(){
        cout<<"Number "<<n<<" is not positive integer"<<endl;
    }
};

class PositiveIntegers{
private:
    int *niza;
    int n;
    int capacity;
public:
    PositiveIntegers(int n, int *niza, int capacity){
        this->n=n;
        this->niza=new int[n];
        for(int i=0;i<n;i++)
            this->niza[i]=niza[i];
        this->capacity=capacity;
    }
    PositiveIntegers(int capacity=5){
        this->niza = new int[0];
        this->niza=0;
        this->n=0;
        this->capacity=capacity;
    }
    PositiveIntegers(const PositiveIntegers &p){
        niza=new int[p.n];
        for(int i=0;i<p.n;i++)
            niza[i]=p.niza[i];
        n=p.n;
        capacity=p.capacity;
    }
    PositiveIntegers &operator=(const PositiveIntegers &p){
        if(this!=&p){
            delete []niza;
            niza=new int[p.n];
            for(int i=0;i<p.n;i++)
                niza[i]=p.niza[i];
            n=p.n;
            capacity=p.capacity;
        }
        return *this;
    }
    ~PositiveIntegers(){
        delete []niza;
    }
    void increaseCapacity(int c){
        this->capacity+=c;
    }
    void operator+=(int k){
        if(capacity==n)
            throw ArrayFullException();
        if(k<=0)
            throw NumberIsNotPositiveException(k);
        int *temp=new int[n+1];
        for(int i=0;i<n;i++)
            temp[i]=niza[i];
        temp[n++]=k;
        delete []niza;
        niza=temp;
    }
    PositiveIntegers operator*(int k){
        int *tempniza = new int[n];
        for(int i=0;i<n;i++)
            tempniza[i]=this->niza[i]*k;
            //this->niza[i]=this->niza[i]*k;
        PositiveIntegers temp(n, tempniza, capacity);
        return temp;
        //return *this;
    }
    PositiveIntegers operator/(int k){
        if(k==0){
            throw ArithmeticException();
        }
        else{
            int flag=1;
            for(int i=0;i<n;i++)
                if(niza[i]%k!=0)
                    flag=0;
            if(flag==0)
                throw NumbersNotDivisibleException(k);
        }
        int *tempniza = new int[n];
        for(int i=0;i<n;i++)
            tempniza[i]=this->niza[i]/k;
        PositiveIntegers temp(n, tempniza, capacity);
        return temp;
    }
    int operator[](int k){
        if(k>n-1||k<0)
            throw IndexOutOfBoundsException(k);
        return niza[k];
    }
    void print(){
        cout<<"Size: "<<n<<" Capacity: "<<capacity<<" Numbers: ";
        for(int i=0;i<n;i++)
            cout<<niza[i]<<" ";
        cout<<endl;
    }
};

int main() {

int n,capacity;
	cin >> n >> capacity;
	PositiveIntegers pi (capacity);
	for (int i=0;i<n;i++){
		int number;
		cin>>number;
		try{
            pi+=number;
		}
		catch(ArrayFullException &e){
            e.message();
		}
		catch(NumberIsNotPositiveException &e){
            e.message();
		}

	}
	cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
	pi.print();
	int incCapacity;
	cin>>incCapacity;
	pi.increaseCapacity(incCapacity);
	cout<<"===INCREASING CAPACITY==="<<endl;
	pi.print();

	int n1;
	cin>>n1;
	for (int i=0;i<n1;i++){
		int number;
		cin>>number;
		try{
            pi+=number;
		}
		catch(ArrayFullException &e){
            e.message();
		}
		catch(NumberIsNotPositiveException &e){
            e.message();
		}
	}
	cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;

    pi.print();
	PositiveIntegers pi1;

	cout<<"===TESTING DIVISION==="<<endl;
    try{
        pi1 = pi/0;
        pi1.print();
    }
    catch(ArithmeticException &e){
        e.message();
    }
    catch(NumbersNotDivisibleException &e){
        e.message();
    }
    try{
        pi1 = pi/1;
        pi1.print();
    }
    catch(ArithmeticException &e){
        e.message();
    }
    catch(NumbersNotDivisibleException &e){
        e.message();
    }
    try{
        pi1 = pi/2;
        pi1.print();
    }
    catch(ArithmeticException &e){
        e.message();
    }
    catch(NumbersNotDivisibleException &e){
        e.message();
    }
	cout<<"===TESTING MULTIPLICATION==="<<endl;
	pi1 = pi*3;
	pi1.print();


	cout<<"===TESTING [] ==="<<endl;
	try{
        cout<<"PositiveIntegers[-1] = "<<pi[-1]<<endl;
	}
	catch(IndexOutOfBoundsException &e){
        e.message();
	}
	try{
        cout<<"PositiveIntegers[2] = "<<pi[2]<<endl;
	}
	catch(IndexOutOfBoundsException &e){
        e.message();
	}
	try{
        cout<<"PositiveIntegers[3] = "<<pi[3]<<endl;
    }
    catch(IndexOutOfBoundsException &e){
        e.message();
	}
	try{
        cout<<"PositiveIntegers[12] = "<<pi[12]<<endl;
	}
	catch(IndexOutOfBoundsException &e){
        e.message();
	}

return 0;
}