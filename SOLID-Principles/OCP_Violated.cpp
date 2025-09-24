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


// OCP says: desgin should be opened to add new features but closed to make changes in current code.
// Meaning: We should be able to add new features in current code without changing in current code.

// if I want to add these functions, then i need to make changes in SaveCartInDB class so OCP will be violated.
// void saveInMongoDB(){
//     cout<<"saving in MongoDB"<<endl;
// }
// void saveInFileDB(){
//     cout<<"saving in file db"<<endl;
// }

class SaveCartInDB{
    Cart *c;
public:
    SaveCartInDB(Cart *c){
        this->c = c;
    }
    void saveInSQLDB(){
        cout<<"saving in SQL db"<<endl;
    }
    void saveInMongoDB(){
        cout<<"saving in MongoDB"<<endl;
    }
    void saveInFileDB(){
        cout<<"saving in file db"<<endl;
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
    db->saveInSQLDB();

    delete c;
    delete p;
    delete cal;
    delete db;

    return 0;
}
