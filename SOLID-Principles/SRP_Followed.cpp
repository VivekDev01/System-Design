#include<bits/stdc++.h>
using namespace std;

class Product{
    string name;
    double price;
public:
    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
    string getName(){
        return this->name;
    }
    double getPrice(){
        return this->price;
    }
};

// Cart: Responsible to add items in cart
class Cart{
    vector<Product*>products;
public:
    Cart(){}
    Cart(string name, double price){
        Product * p = new Product(name, price);
        products.push_back(p);
    }
    vector<Product*> getProducts(){
        return products;
    }
    void addItem(string name, double price){
        products.push_back(new Product(name, price));
        cout<<"Item : "<<name<<" | "<<price<<" added in your cart"<<endl;
    }
    ~Cart(){
        for(auto p: products){
            delete p;
        }
        products.clear();
    }
};

// CalculatePriceOfCart: Only responsible to to calculate price of cart
class CalculatePriceOfCart{
    Cart * c;
public:
    CalculatePriceOfCart(Cart *c){
        this->c = c;
    }
    double calculatePrice(){
        double sum=0;
        vector<Product*>products = c->getProducts();
        for(Product* it: products){
            sum+=it->getPrice();
        }
        cout<<"Total Price of your cart is "<<sum<<endl;
        return sum;
    }
};

// PrintInvoiceOfCart : Only responsible to print Invoice of cart
class PrintInvoiceOfCart{
    Cart * c;
public:
    PrintInvoiceOfCart(Cart *c){
        this->c = c;
    }
    void printInvoice(){
        cout<<"The following items are in your cart: "<<endl;
        int i=0;
        double sum=0;
        for(auto it: c->getProducts()){
            i++;
            cout<<i<<". "<<it->getName()<<" - "<<it->getPrice()<<endl;
            sum+=it->getPrice();
        }
        cout<<"Total Price: "<<sum<<endl;
    }
};


// SaveCartInDB : Only responsible to save data in DB
class SaveCartInDB{
    Cart *c;
public:
    SaveCartInDB(Cart *c){
        this->c = c;
    }
    void saveInDB(){
        cout<<"saving in db"<<endl;
    }
};

int main(){
    Cart * c = new Cart("Shoes", 2000.6);
    c->addItem("Shirt", 500.2);

    PrintInvoiceOfCart * p = new PrintInvoiceOfCart(c);
    p->printInvoice();

    CalculatePriceOfCart *cal = new CalculatePriceOfCart(c);
    cal->calculatePrice();

    SaveCartInDB *db = new SaveCartInDB(c);
    db->saveInDB();

    delete c;
    delete p;
    delete cal;
    delete db;

    return 0;
}

// By splitting the Cart class to multiple classes with single-single responsibility, achieved SRP.