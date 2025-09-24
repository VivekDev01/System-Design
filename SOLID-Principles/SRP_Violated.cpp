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

    void addItem(string name, double price){
        Product * p = new Product(name, price);
        products.push_back(p);
        cout<<"Item : "<<name<<" | "<<price<<" added in your cart"<<endl;
    }

    double calculatePrice(){
        double sum=0;
        for(auto it: products){
            sum+=it->getPrice();
        }
        cout<<"Total Price of your cart is "<<sum<<endl;
        return sum;
    }

    void printInvoice(){
        cout<<"The following items are in your cart: "<<endl;
        int i=0;
        double sum=0;
        for(auto it: products){
            i++;
            cout<<i<<". "<<it->getName()<<" - "<<it->getPrice()<<endl;
            sum+=it->getPrice();
        }
        cout<<"Total Price: "<<sum<<endl;
    }

    void saveInDB(){
        cout<<"saving in db"<<endl;
    }
};

int main(){
    Cart * c = new Cart("Shoes", 2000.6);
    c->printInvoice();
    c->addItem("Shirt", 500.2);
    c->calculatePrice();
    c->printInvoice();
    c->saveInDB();
}