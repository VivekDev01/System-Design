#ifndef PAYMENT_UPI_STRATEGY_H
#define PAYMENT_UPI_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class PayWithUPI : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with upi"<<endl;
    }
};

#endif