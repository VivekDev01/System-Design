#include<bits/stdc++.h>

using namespace std;

class Account{
public:
    virtual void deposit(double amount) = 0; 
    virtual void withdraw(double amount) = 0;
    virtual ~Account(){};
};

class SavingAccount : public Account{
    double amount=0;
public:
    void deposit(double amount){
        this->amount+=amount;
        cout<<"amount deposit: "<<amount<<", Balance: "<<this->amount<<endl;
    }
    void withdraw(double amount){
        if(amount>this->amount){
            cout<<"amount cannot be withdrawn as balance is low, balance: "<<this->amount<<endl;
            return;
        }
        this->amount-=amount;
        cout<<"amount withdraw: "<<amount<<", Balance: "<<this->amount<<endl;
    }
};


class CurrentAccount : public Account{
    double amount=0;
public:
    void deposit(double amount){
        this->amount+=amount;
        cout<<"amount deposit: "<<amount<<", Balance: "<<this->amount<<endl;
    }
    void withdraw(double amount){
        if(amount>this->amount){
            cout<<"amount cannot be withdrawn as balance is low, balance: "<<this->amount<<endl;
            return;

        }
        this->amount-=amount;
        cout<<"amount withdraw: "<<amount<<", Balance: "<<this->amount<<endl;
    }
};

class FDAccount : public Account{
    double amount=0;
public:
    void deposit(double amount){
        this->amount+=amount;
        cout<<"amount deposit: "<<amount<<", Balance: "<<this->amount<<endl;
    }
    void withdraw(double amount){ 
        throw logic_error("Withdrawal not allowed"); // here violating LSP bcz client expects it to work, but it doesn't which client does not know.
    }
};

/*
LSP says: Subclasses should be susbstitutable for their parent class.
Meaning: Parent class can easily be substituted with the child class.


HERE: child class FDAccount can not replace Account bcz client expects withdrawal too.
*/

class Client{
    vector<Account*>accounts;
public:
    Client(vector<Account*>accounts){
        this->accounts = accounts;
    }
    void processTransactions(){
        for(int i=0;i<this->accounts.size();i++){
            this->accounts[i]->deposit(5000);
            try{
                this->accounts[i]->withdraw(2000);
            }
            catch(const logic_error&e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*>accounts; // creating vector of objects of derived class of Account (not the object of Account)
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FDAccount());

    Client * c = new Client(accounts);

    c->processTransactions();
}