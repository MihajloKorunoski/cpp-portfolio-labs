#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classes for customers
class Customer {
public:
    Customer(string name, int age, string email, string address)
        : name(name), age(age), email(email), address(address) {}
    virtual ~Customer() {}

    virtual string getClassName() const { return "Customer"; }
    virtual void print() const {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Email: " << email << endl
             << "Address: " << address << endl;
    }

protected:
    string name;
    int age;
    string email;
    string address;
};

class PremiumCustomer : public Customer {
public:
    PremiumCustomer(string name, int age, string email, string address,
                     string creditCardNumber)
        : Customer(name, age, email, address),
          creditCardNumber(creditCardNumber) {}
    ~PremiumCustomer() {}

    string getClassName() const override { return "PremiumCustomer"; }
    void print() const override {
        Customer::print();
        cout << "Credit Card Number: " << creditCardNumber << endl;
    }

private:
    string creditCardNumber;
};

// Payment methods
class PaymentMethod {
public:
    virtual ~PaymentMethod() {}
    virtual bool pay(float amount) = 0;
};

class CreditCard : public PaymentMethod {
public:
    CreditCard(string cardNumber, string expirationDate, int cvv)
        : cardNumber(cardNumber), expirationDate(expirationDate), cvv(cvv) {}
    ~CreditCard() {}

    bool pay(float amount) override {
        cout << "Paid $" << amount << " with credit card." << endl;
        return true;
    }

private:
    string cardNumber;
    string expirationDate;
    int cvv;
};

class PayPal : public PaymentMethod {
public:
    PayPal(string email, string password)
        : email(email), password(password) {}
    ~PayPal() {}

    bool pay(float amount) override {
        cout << "Paid $" << amount << " with PayPal." << endl;
        return true;
    }

private:
    string email;
    string password;
};

// Shopping cart
class ShoppingCart {
public:
    void addItem(string item, float price) {
        items.push_back(item);
        total += price;
    }

    bool pay(PaymentMethod* paymentMethod) {
        if (paymentMethod->pay(total)) {
            items.clear();
            total = 0;
            return true;
        }
        return false;
    }

    void print() const {
        for (const string& item : items) {
            cout << item << endl;
        }
        cout << "Total: $" << total << endl;
    }

private:
    vector<string> items;
    float total = 0;
};

// Website
class Website {
public:
    void changeTitle(string title) {
        cout << "Website title changed to '" << title << "'." << endl;
    }

    void addProduct(string name, float price) {
        cout << "Product '" << name << "' added with price $" << price << "." << endl;
    }

    void removeProduct(string name) {
        cout << "Product '" << name << "' removed." << endl;
    }
};

// Example method for adding a new customer to the system
void addCustomer(string name, int age, string email, string phone, PaymentMethod paymentMethod) {
    Customer newCustomer(name, age, email, phone, paymentMethod);
    customers.push_back(newCustomer);
}

// Example method for making a purchase
void makePurchase(Customer customer, Product product, int quantity) {
    double totalPrice = product.getPrice() * quantity;
    if (customer.getPaymentMethod() == PaymentMethod::CREDIT_CARD) {
        // Process credit card payment
        // ...
    } else if (customer.getPaymentMethod() == PaymentMethod::PAYPAL) {
        // Process PayPal payment
        // ...
    } else if (customer.getPaymentMethod() == PaymentMethod::BANK_TRANSFER) {
        // Process bank transfer payment
        // ...
    }
    // Update product inventory and customer purchase history
    // ...
}

// Example method for updating the website design
void updateWebsite(WebsiteDesign newDesign) {
    website.setDesign(newDesign);
}
void examplePayment()
{
    CreditCard cc("1234 5678 9012 3456", "01/23", 123);
    PayPal pp("john.doe@example.com", "password123");
    float amount = 100. finish this method float tax = 0.10;
    float totalAmount = amount + (amount * tax);

    // Display payment options
    cout << "Payment options:\n";
    cout << "1. Credit card\n";
    cout << "2. PayPal\n";

    // Get payment option from user
    int option;
    cout << "Enter payment option (1 or 2): ";
    cin >> option;

    // Perform payment based on option
    switch (option)
    {
    case 1:
        cc.makePayment(totalAmount);
        break;
    case 2:
        pp.makePayment(totalAmount);
        break;
    default:
        cout << "Invalid payment option\n";
        break;
    }

    void examplePurchase()
    {
        // Create customer
        Customer c("John", "Doe", "john.doe@example.com");

        // Create product
        Product p("ABC123", "Product Name", "Product Description", 99.99);

        // Create shopping cart
        ShoppingCart cart;
        cart.addItem(p, 1);

        // Display shopping cart
        cout << "Shopping Cart:\n";
        cart.display();

        // Get payment method from customer
        c.setPaymentMethod("Credit Card");

        // Checkout
        float amount = cart.getTotal();
        c.makePayment(amount);

        // Display receipt
        cout << "Receipt:\n";
        cart.display();
        cout << "Subtotal: $" << cart.getSubtotal() << "\n";
        cout << "Tax: $" << cart.getTax() << "\n";
        cout << "Total: $" << cart.getTotal() << "\n";
    }

    void exampleTransfer()
    {
        // Create customer
        Customer c("John", "Doe", "john.doe@example.com");

        // Set payment method
        c.setPaymentMethod("PayPal");

        // Perform transfer
        PayPal pp("john.doe@example.com", "password123");
        float amount = 500.00;
        pp.transfer(amount, "jane.doe@example.com");
    }
}

int main() {
    // Create some example customers
    Customer customer1("John Smith", 25, "john.smith@gmail.com", "555-1234", PaymentMethod::CREDIT_CARD);
    Customer customer2("Mary Johnson", 30, "mary.johnson@yahoo.com", "555-5678", PaymentMethod::PAYPAL);
    
    // Add the customers to the system
    addCustomer(customer1);
    addCustomer(customer2);
    
    // Create an example product
    Product product("Widget", 9.99, 100);
    
    // Make a purchase
    makePurchase(customer1, product, 2);
    
    // Update the website design
    WebsiteDesign newDesign("Blue", "White", "Arial");
    updateWebsite(newDesign);
    
    return 0;
}
