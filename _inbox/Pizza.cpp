#include <cstring>
#include <iostream>
using namespace std;

enum Size {small, big, family};

class Pizza {
protected:
    char name[20];
    char ingredients[100];
    float inPrice;

public:
      Pizza(const char *n = "", const char *ingr = "", float ip = 0) {
        strncpy(name, n, 19);
        name[19] = '\0';
        strncpy(ingredients, ingr, 99);
        ingredients[49] = '\0';
          inPrice = ip;
      }

      friend bool operator<(Pizza &p1, Pizza &p2) {
          return (p1.price() < p2.price());
      }
    
      virtual float price() = 0;

      virtual ~Pizza() {}
    char* getName(){return name;}

};

class FlatPizza : public Pizza {
private:
    Size size;

public:
    FlatPizza(const char *n = "", const char *ingr = "", float ip = 0, Size s = small)
      : Pizza(n, ingr, ip) {
        size = s;
  }

  float price() {
      if(size == small)
          return inPrice*1.1;
      else if(size == big)
		  return inPrice*1.2;
      else if(size == family)
          return inPrice*1.3;
      return inPrice;
      
  }
	
    friend ostream &operator<<(ostream &out, FlatPizza &fp) {
        out << fp.name << ": " << fp.ingredients << ", ";
        if(fp.size == small)
          out << "small - ";
      	else if(fp.size == big)
          out << "big - ";
      	else if(fp.size == family)
          out << "family - ";
        
        out << fp.price() << endl;
        return out;
    }

};

class FoldedPizza : public Pizza {
protected:
  bool whiteFlour;

public:
    FoldedPizza(const char *n = "", const char *ingr = "", float ip = 0, bool wf = true)
            : Pizza(n, ingr, ip) {
        whiteFlour = wf;
    }

    float price() {
        if(whiteFlour)
            return inPrice*1.1;
        return inPrice*1.3;
    }

    void setWhiteFlour(bool wf){
      whiteFlour = wf;
    }
    
    friend ostream &operator<<(ostream &out, FoldedPizza &fp) {
        out << fp.name << ": " << fp.ingredients << ", ";
        if(fp.whiteFlour)
          out << "wf - ";
      	else 
          out << "nwf - ";
        
        out << fp.price() << endl;
        return out;
    }


};



int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;
    
  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;
    
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;
      
    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;
        
    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;    
        
    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;
    
    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } 
  return 0;
}
