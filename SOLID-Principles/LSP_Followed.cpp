#include<bits/stdc++.h>

using namespace std;

class NonWithdrawalAccount{
public:
    virtual void deposit(double amount) = 0; 
    virtual ~NonWithdrawalAccount(){};
};

class WithdrawalAccount : public NonWithdrawalAccount{ // subclass of NonWithdrawalAccount
public:
    virtual void withdraw(double amount) = 0;
    virtual ~WithdrawalAccount(){};
};

class SavingAccount : public WithdrawalAccount{
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


class CurrentAccount : public WithdrawalAccount{
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

class FDAccount : public NonWithdrawalAccount{
    double amount=0;
public:
    void deposit(double amount){
        this->amount+=amount;
        cout<<"amount deposit: "<<amount<<", Balance: "<<this->amount<<endl;
    }
};

/*
LSP says: Subclasses should be susbstitutable for their parent class.
Meaning: Parent class can easily be substituted with the child class.


HERE: child class FDAccount can now replace NonWithdrawalAccount.
PS: the fact is that FDAccount was not a subclass of Acocunt abstract class so we had to create proper abstract classes.
*/

class Client{
    vector<NonWithdrawalAccount*>NWA;
    vector<WithdrawalAccount*>WA; 
public:
    Client(vector<NonWithdrawalAccount*>NWA, vector<WithdrawalAccount*>WA){
        this->NWA = NWA;
        this->WA = WA;
    }
    void processTransactions(){
        for(int i=0;i<this->WA.size();i++){
            this->WA[i]->deposit(5000);
            try{
                this->WA[i]->withdraw(2000);
            }
            catch(const logic_error&e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }

        for(int i=0;i<this->NWA.size();i++){
            this->NWA[i]->deposit(5000);
        }
    }
};

int main(){
    vector<NonWithdrawalAccount*>NWA;
    vector<WithdrawalAccount*>WA; 
    WA.push_back(new SavingAccount());
    WA.push_back(new CurrentAccount());
    NWA.push_back(new FDAccount());

    Client * c = new Client(NWA, WA);

    c->processTransactions();
}


// by making two proper abstract classes, we achieved the LSP.