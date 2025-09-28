#ifndef PAYMENT_CREDIT_STRATEGY_H
#define PAYMENT_CREDIT_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class PayWithCreditCard : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with credit card"<<endl;
    }
};

#endif