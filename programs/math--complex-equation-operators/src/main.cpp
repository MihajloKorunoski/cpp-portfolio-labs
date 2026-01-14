#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber(double r=0, double i=0) {
        this->real = r;
        this->imaginary = i;
    }
    ComplexNumber(const ComplexNumber &c) {
        real = c.real;
        imaginary = c.imaginary;
    }
    ComplexNumber & operator =(const ComplexNumber &c) {
        if(this != &c) {
            real = c.real;
            imaginary = c.imaginary;
        }
        return *this;
    }
    ~ComplexNumber() {};


    friend ostream & operator << (ostream &o, const ComplexNumber &c) {
        if(!c.imaginary)
            o << c.real << endl;
        else if(!c.real)
            o << c.imaginary << "i" << endl;
        else
            o << c.real << "+" << c.imaginary << "i" << endl;
        return o;
    }

    friend istream & operator >> (istream &input, ComplexNumber &c) {
        return input >> c.real >> c.imaginary;
    }
    ComplexNumber operator +(const ComplexNumber &c) {
        return ComplexNumber(real+c.real, imaginary+c.imaginary);
    }
    ComplexNumber operator -(const ComplexNumber &c) {
        return ComplexNumber(real-c.real, imaginary-c.imaginary);
    }
    ComplexNumber operator *(const ComplexNumber &c) {
        return ComplexNumber(real*c.real, imaginary*c.imaginary);
    }
    ComplexNumber operator /(const ComplexNumber &c) {
        return ComplexNumber(real/c.real, imaginary/c.imaginary);
    }

    bool operator ==(const ComplexNumber &c) {
        if(c.real == real&&c.imaginary==imaginary)
            return 1;
        else return 0;
    }

    bool operator < (const ComplexNumber &c) {
        if(c.real==real) {
            if(imaginary < c.imaginary)
                return 1;
            else return 0;
        } else {
            if(real<c.real)
                return 1;
            else return 0;
        }
    }

    bool operator >(const ComplexNumber &c) {
        if(c.real==real) {
            if(imaginary > c.imaginary)
                return 1;
            else return 0;
        } else {
            if(real>c.real)
                return 1;
            else return 0;
        }
    }

    double module() {
        return sqrt(pow(real,2)+pow(imaginary,2));
    }
};

class Equation {
private:
    ComplexNumber *nums;
    char *znaci;

public:
    Equation() {
        nums = NULL;
        znaci = NULL;
    }
    Equation(const Equation &e) {
        znaci = new char[strlen(znaci)+1];
        strcpy(znaci, e.znaci);

        nums = new ComplexNumber[strlen(znaci)];
        for(int i = 0; i<strlen(znaci); i++)
            nums[i] = e.nums[i];
    }
    Equation & operator = (const Equation &e) {
        if(this != &e) {
            delete [] znaci;
            znaci = new char[strlen(e.znaci)+1];
            strcpy(znaci, e.znaci);
            delete [] nums;
            nums  = new ComplexNumber[strlen(znaci)];
            for(int i=0; i<strlen(znaci); i++)
                nums[i] = e.nums[i];
        }
        return *this;
    }
    ~Equation () {
        delete [] nums;
        delete [] znaci;
    }

    friend istream & operator >> (istream &input, Equation &e) {
        int i = 0;
        ComplexNumber *temp = new ComplexNumber[100];
        char *temp1 = new char[101];
        while(true) {
            input >> temp[i];
            input >> temp1[i];

            if(temp1[i]=='=')
                break;
            i++;
        }
        e.nums = temp;
        e.znaci = new char[strlen(temp1)+1];
        strcpy(e.znaci, temp1);
        return input;
    }

    ComplexNumber result() {
        ComplexNumber temp = nums[0];
        for(int i = 1; i<int(strlen(znaci)); i++) {
            if(znaci[i-1] == '+')
                temp = temp + nums[i];
            else if(znaci[i-1] == '-')
                temp = temp - nums[i];
            else if(znaci[i-1] == '*')
                temp = temp * nums[i];
            else if(znaci[i-1] == '/')
                temp = temp/nums[i];
            else if(znaci[i-1] == '=')
                temp = temp;
        }
        return temp;
    }
    double sumModules() {
        double sum = 0;
        for(int i = 0; i<int(strlen(znaci)); i++)
            sum += nums[i].module();
        return sum;
    }


};




// Не го менувајте main методот.

int main() {
    int testCase;
    double real, imaginary;
    ComplexNumber first, second, result;

    cin >> testCase;

    if (testCase <= 8) {
        cin >> real;
        cin >> imaginary;
        first = ComplexNumber(real, imaginary);
        cin >> real;
        cin >> imaginary;
        second = ComplexNumber(real, imaginary);
    }

    if (testCase == 1) {
        cout << "===== OPERATOR + =====" << endl;
        result = first + second;
        cout << result;
    } else if (testCase == 2) {
        cout << "===== OPERATOR - =====" << endl;
        result = first - second;
        cout << result;
    } else if (testCase == 3) {
        cout << "===== OPERATOR * =====" << endl;
        result = first * second;
        cout << result;
    } else if (testCase == 4) {
        cout << "===== OPERATOR / =====" << endl;
        result = first / second;
        cout << result;
    } else if (testCase == 5) {
        cout << "===== OPERATOR == =====" << endl;
        cout << first;
        cout << second;
        if (first == second)
            cout << "EQUAL" << endl;
        else
            cout << "NOT EQUAL" << endl;
    } else if (testCase == 6) {
        cout << "===== OPERATOR > =====" << endl;
        cout << first;
        cout << second;
        if (first > second)
            cout << "FIRST GREATER THAN SECOND" << endl;
        else
            cout << "FIRST LESSER THAN SECOND" << endl;
    } else if (testCase == 7) {
        cout << "===== OPERATOR < =====" << endl;
        cout << first;
        cout << second;
        if (first < second)
            cout << "FIRST LESSER THAN SECOND" << endl;
        else
            cout << "FIRST GREATER THAN SECOND" << endl;
    } else if (testCase == 8) {
        cout << "===== MODULE =====" << endl;
        double module = first.module();
        cout << first;
        cout << "Module: " << module << endl;
        cout << second;
        module = second.module();
        cout << "Module: " << module << endl;
    } else if (testCase == 9) {
        cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
        Equation equation;
        cin >> equation;
        cout << equation.sumModules();
    } else if (testCase == 10) {
        cout << "===== EQUATION RESULT =====" << endl;
        Equation equation;
        cin >> equation;
        result = equation.result();
        cout << result;
    }
    return 0;
}