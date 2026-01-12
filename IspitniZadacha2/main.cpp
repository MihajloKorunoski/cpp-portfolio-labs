#include<iostream>
#include<cstring>

using namespace std;

enum typeC {
    standard, loyal, vip, MAX = 20
};

class Customer {
private:
    char ime[50];
    char adresa[50];
    char a[10];
    typeC tip;
    static int opopust;
    const static int dpopust;
    int b;
public:
    Customer(char *name = "", char *email = "", typeC tip1 = standard, int numProducts = 0) {
        strcpy(ime, name);
        strcpy(adresa, email);
        tip = tip1;
        b = numProducts;
    }

    void setDiscount1(int x) {
        opopust = x;
    }

    char *tip1() {
        if (tip == standard) {
            strcpy(a, "standard");
            return a;
        }
        if (tip == loyal) {
            strcpy(a, "loyal");
            return a;
        }
        if (tip == vip) {
            strcpy(a, "vip");
            return a;
        }
    }

    int popust() {
        if (tip == 0) {
            return 0;
        } else if (tip == 1) {
            return opopust;
        } else {
            return opopust + dpopust;
        }
    }

    friend ostream &operator<<(ostream &o, Customer &a) {
        o << a.ime << endl << a.adresa << endl << a.b << endl << a.tip1() << " " << a.popust() << endl;
        return o;
    }

    friend class FINKI_bookstore;
};

int Customer::opopust = 10;
const int Customer::dpopust = 20;

class FINKI_bookstore {
    Customer *kupuvac;
    int n;
public:
    FINKI_bookstore() {
        kupuvac = 0;
        n = 0;
    }

    void setCustomers(Customer *customers, int n) {
        kupuvac = new Customer[n];
        for (int i = 0; i < n; i++) {
            kupuvac[i] = customers[i];
            this->n = n;
        }
    }

    FINKI_bookstore &operator+=(Customer &c) {
        int imaist = 0;
        for (int i = 0; i < n; i++) {
            if (!strcmp(kupuvac[i].adresa, c.adresa)) {
                imaist = 1;
                throw 1;
            }

        }
        if (!imaist) {
            Customer *temp = new Customer[n + 1];
            for (int i = 0; i < n; i++) {
                temp[i] = kupuvac[i];
            }
            temp[n] = c;
            delete[] kupuvac;
            kupuvac = temp;
            n++;
        }
        return *this;
    }

    void update() {
        for (int i = 0; i < n; i++) {
            if (kupuvac[i].tip == loyal && kupuvac[i].b > 10) {
                kupuvac[i].tip = vip;
            }
            if (kupuvac[i].tip == standard && kupuvac[i].b > 5) {
                kupuvac[i].tip = loyal;
            }
        }
    }

    friend ostream &operator<<(ostream &o, FINKI_bookstore &a) {
        for (int i = 0; i < a.n; i++) {
            o << a.kupuvac[i];
        }
        return o;
    }
};


int main() {
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1) {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2) {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3) {
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4) {
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc += c;

        cout << fc;
    }

    if (testCase == 5) {
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        }
        catch (...) {
            cout << "The user already exists in the list!" << endl;
        }

        cout << fc;
    }

    if (testCase == 6) {
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
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