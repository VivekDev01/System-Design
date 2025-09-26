#include<bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger(){};
};

class SimpleBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing simple burger"<<endl;
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing standard burger"<<endl;
    }
};

class PermiumBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing premium burger"<<endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string type){
        if(type=="simple"){
            return new SimpleBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else return new PermiumBurger();
    }
};

int main(){
    BurgerFactory * factory = new BurgerFactory();

    string type = "standard";

    Burger * simpleOne = factory->createBurger(type);
    simpleOne->prepare();
}


// you just need to provide a type to factory to create an object of that type.